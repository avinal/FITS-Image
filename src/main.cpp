#include "FitsImage.hpp"

int main(int argc, char const *argv[])
{
    std::string file_name;
    std::cout << "Enter a FITS file name" << std::endl;
    std::cin >> file_name;
    FitsImage fits_image(file_name);
    fits_image.export_to_jpeg();
    return 0;
}
