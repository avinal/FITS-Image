#include <boost/gil.hpp>
#include <boost/gil/extension/io/jpeg/old.hpp>
#include <cfitsio/fitsio.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>

using namespace boost::gil;

class FitsImage
{
    fitsfile *fptr;
    int status = 0;
    int bitpix, naxis, anynull;
    long naxes[2] = {1, 1}, fpixel[2] = {1, 1};
    double *pix_value;
    std::vector<double> parsed;
    std::string file_name;
    double minval, maxval;


    void produce_pixel_values();
    void double_to_uchar();

public:
    FitsImage();
    FitsImage(std::string file_name);
    void export_to_jpeg();
};