Visualisation of the bit structure of the decimal numbers (-128 to 127) which 
are stored as an 8-bit signed char. Displaying binary in groups of a nibble.

Compiling:
Native Windows:
clang -Dtest_visualise -std=c11 -Wall -pedantic -g visualise.c -o visualise.exe
Linux/MacOS/WSL:
clang -Dtest_visualise -std=c11 -Wall -pedantic -g visualise.c -o visualise \
	    -fsanitize=undefined -fsanitize=address

Usage:
./visualise char <INPUT DECIMAL -128 TO 127>
Other inputs will output 'Input error.'

Testing:
./visualise
Successful tests output 'All tests pass.'

Examples:
./visualise char 7    # outputs: 0000 0111
./visualise char 999  # outputs: Input error.
./visualise           # outputs: All tests pass.