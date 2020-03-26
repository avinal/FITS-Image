# FitsImage
A small program to extract images from FITS file using Boost.GIL and CFITSIO.
*Works Best with BITPIX = 8, 16 and 32 and NAXIS = 2.*

# Running the program
Directly grab the latest release from [Releases](https://github.com/avinal/FitsImage/releases) section for Windows.

# How to build 
*(Currnetly the conan file and cfitsio libraries included are configured for Windows 64 bits. Make necessary changes
in Cmake config when using on linux.)*
1. This program uses conan as package manager make sure to config conan before building. 
   see [here](https://docs.conan.io/en/latest/getting_started.html) for more about conan.
2. To config conan on either machine follow these steps
   ```
   git clone https://github.com/avinal/FitsImage.git
   conan
   cd <your-path-here>/FitsImage
   mkdir build
   cd build
   conan install ..
   ```
3. For Windows using CMAKE
   ```
   cd build
   conan install ..
   cmake .. -G "Visual Studio 16"
   cmake --build . --config Release
   ```
4. For Linux Systems using CMAKE
   ```
   cd build
   conan install ..
   cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
   cmake --build .
   ```
5. Don't forget to put FITS file and *cfitsio.dll* or equivalent for linux in fitsReader/build/bin directory when running. 

## Example Images
1. ![Eagle Nebula ](/image/18.jpeg)

2. ![Sample 15](/image/15.jpeg)


