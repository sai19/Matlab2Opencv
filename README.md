#################################### FOR STDFILT #######################################
1. store both files driverstdfilt.cpp and stdfilt.cpp in same directory
2. follow the instructions given at (http://docs.opencv.org/2.4/doc/tutorials/introduction/linux_gcc_cmake/linux_gcc_cmake.html#linux-gcc-usage) for running the code. (I am working on linux)
3. give the input through command line like this
  ./driverstdfilt <image path> <kernel size(int)>
4. after running above code image will be displayed
5. The function is compatible for coloured images too



#################################### FOR imQuantize #######################################

1. store both files driverimQuantize.cpp and imQuantize.cpp in same directory
2. follow the instructions given at (http://docs.opencv.org/2.4/doc/tutorials/introduction/linux_gcc_cmake/linux_gcc_cmake.html#linux-gcc-usage) for running the code. (I am working on linux)
3. give the input through command line like this
  ./driverimQuantize <image path> 
4. after running above code image will be displayed
5. The function is not compatible for coloured images but can be used by applying it to each channel of the coloured image.
