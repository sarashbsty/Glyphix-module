## What is Glyphix?

Glyphix is a simple program designed to convert any alphabetic text you input into large, stylized characters made from ASCII symbols. It's perfect for creating eye-catching headings for your scripts, fun messages, or just adding a unique flair to your terminal output.

The program currently supports a specific font style , but it's built to be easily expandable.

## Build Guide for web-assembly module
 Open a terminal inside the project’s directory.
 Eg: C:\Users\user123\Desktop\GitHub\Glyphix-module

 Make a folder inside the directory and open it:  
 
    mkdir build
    cd build
 
 Build the project :
 
    emcmake cmake ..
    cmake --build .

 After the build completes, the glyphix.js and glyphix.wasm will be generated in this build  folder.

## Functions Exposed
1. run_glyphix : to input json and get output json
2. free_json : to clear the output json
3. free : normal free function to clear allocated heap mem

## JSON sturutre

Input: 

    {"row" : 5 , "text" : "A" , "style" : "~"}       
Here, row >= 5, 
      text: A-Z,a-z ,
      style: It can be any character except '~' , of which the ascii art will be created.
      
  '~' is reserved for specific mode where the ascii art will use the character of a letter of the text, instead of single characer for whole text

Output:  
     
    {"error" : false, "errorMsg" : "", "text" : "A    \nA   A\n ....."}

## Sample

<img width="1053" height="187" alt="image" src="https://github.com/user-attachments/assets/136fb0fc-baae-4a56-ae2a-d8daccf87492" />
<img width="677" height="305" alt="image" src="https://github.com/user-attachments/assets/90835f3b-89f5-4447-a340-d3d16945481e" />


note: Used main() function to invoke the run_glyphix() function and print in terminal

