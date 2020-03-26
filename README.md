# FitsImage
A small program to extract images from FITS file using Boost.GIL and CFITSIO.

# How to build
1. This program uses conan as package manager make sure to config conan before building. 
   see [here](https://docs.conan.io/en/latest/getting_started.html) for more about conan.
2. To config conan on either machine follow these steps
   ```
   git clone https://github.com/avinal/fitsReader.git
   conan
   cd <your-path-here>/FitsImage
   mkdir build
   cd build
   conan install ..
   ```
. For Windows using CMAKE
   ```
   cd build
   conan install ..
   cmake .. -G "Visual Studio 16"
   cmake --build . --config Release
   ```
3. For Linux Systems using CMAKE
   ```
   cd build
   conan install ..
   cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
   cmake --build .
   ```
4. Don't forget to put FITS file and *cfitsio.dll* in fitsReader/build/bin directory when running. 

## Example Images
1. ![Eagle Nebula ](/image/18.jpeg)
2. ![Sample 15](/images/15.jpeg)
3. ![Sample 17](/image/17.jpeg)

