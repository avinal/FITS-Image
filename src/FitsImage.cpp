#include "FitsImage.hpp"

FitsImage::FitsImage(std::string file_name)
{
    this->file_name = file_name;
    produce_pixel_values();
}

void FitsImage::produce_pixel_values()
{
    if (!fits_open_file(&fptr, file_name.c_str(), READONLY, &status))
    {
        if (!fits_get_img_param(fptr, 2, &bitpix, &naxis, naxes, &status))
        {
            if (naxis > 2 || naxis == 0)
            {
                std::cerr << "Only 1D or 2D images are supported" << std::endl;
            }
            else
            {
                pix_value = new double[naxes[0] * sizeof(double)];
                if (pix_value == nullptr)
                {
                    std::cerr << "Memory Allocation Error" << std::endl;
                    return;
                }

                parsed.reserve(naxes[0] * naxes[1]);

                for (fpixel[1] = naxes[1]; fpixel[1] >= 1; fpixel[1]--)
                {
                    if (fits_read_pix(fptr, TDOUBLE,
                                      fpixel, naxes[0],
                                      NULL, pix_value,
                                      NULL, &status))
                    {
                        break;
                    }
                    for (int ii = 0; ii < naxes[0]; ii++)
                    {
                        parsed.push_back(pix_value[ii]);
                    }
                }
                delete pix_value;
            }
        }
        fits_close_file(fptr, &status);
    }
    if (status)
    {
        fits_report_error(stderr, status);
    }
}

void FitsImage::double_to_uchar()
{

    //double sum = std::accumulate(parsed.begin(), parsed.end(), 0.);
    auto min_val = std::min_element(parsed.begin(), parsed.end());
    auto max_val = std::max_element(parsed.begin(), parsed.end());
    double minval = *min_val;
    double maxval = *max_val;

    for (long i = 0; i < parsed.size(); i++)
    {
        parsed[i] = static_cast<unsigned char>((parsed[i] - minval) * 255 / (maxval - minval));
    }
}

void FitsImage::export_to_jpeg()
{
    gray8_image_t img(naxes[0], naxes[1]);
    gray8_image_t::view_t w = view(img);
    int pixel_position;
    for (int i = 0; i < naxes[0]; i++)
    {
        pixel_position = naxes[1] * i;
        for (int j = 0; j < naxes[1]; j++)
        {
            w(j, i) = gray8_pixel_t(parsed[pixel_position + j]);
        }
    }
    std::string name_img = file_name.substr(0, file_name.find("."));
    name_img += ".jpeg";
    jpeg_write_view(name_img.c_str(), w);
}