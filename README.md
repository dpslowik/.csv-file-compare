# .csv-file-compare
A simple program writen in C++ that can read and manipulate data from .csv (a.k.a comma separated value excel spreadsheets) and then store the result into a new file

To compile this program you'll need the main file 'ExcelCompare[v1.0].cpp' plus 3 header files:
  - IndexCompare.h
  - convert.h
  - OtherFunctions.h
  
To use the program you'll need to have the two .csv files that you want to pull data from in the same directory as the program.  Right now the program is setup to grab data from the first column in each file and then return the values that are equal or greater than into a new user specified .csv file.  The program works best if you don't have data in other columns than the first.

In the source code, there are some other functions that can change how the program grabs the data or how the data is compared and also a bunch of debugging functions.
