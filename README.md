# LZ78 compression

The program is a demonstartion of an LZ78 compression algorithm as it reads content of text file and saves index-symbol pairs in output file. Such a file can be then decompressed using the program.

The program has four possible parameters:<br>
 -c filemane.txt – compress this file<br>
 -d filename.txt – decompress this file<br>
 -o filename.txt – name of an output file, if not given, the default is lz78_output.txt<br>
 -s number – dictionary size, if not given, the default size is 1000
  
Parameters -c and -d cannot be used at the same program execution but either of these is necessary to run. Parameter -s is meaningless in decompression.
