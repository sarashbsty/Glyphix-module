## What is Glyphix?

Glyphix is a simple program designed to convert any alphabetic text you input into large, stylized characters made from ASCII symbols. It's perfect for creating eye-catching headings for your scripts, fun messages, or just adding a unique flair to your terminal output.

The program currently supports a specific font style , but it's built to be easily expandable.

## Build Guide for web-assembly module
 Open a terminal and change to the project’s source directory.
 Eg: C:\Users\user123\Desktop\GitHub\Glyphix-module

 Make a folder inside the directory and open it:  
 
    mkdir build
    cd build
 
 Build the project :
 
    emcmake cmake ..
    cmake --build .

 After the build completes, the glyphix.js and glyphix.wasm will be generated in this build  folder.
