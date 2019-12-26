Compilation of the program requires qmake. Any version available post qt4.3 works
To run the unit tests, the program uses gtest framework
The directories client and server contain respective .pro files
Invoke qmake on these .pro files to generate the Makefile.

eg. 
cd server
qmake server.pro
make

similarly

cd client
qmake client.pro
make

The above assumes that qmake is in the user's PATH
The above steps will create binaries in the client and server directories.
The binaries are named client and server respectively.

To run, invoke by passing a input data file.(Sample file called data.txt is provided). The data file contains 2 lines
1. path to the input directory.
2. path to the output directory.
The input file has 2 tuple data in each row. The message Id and the message Text
User should have read permissions on the input and write permissions on the output.
Sample input and output files are also provided.
