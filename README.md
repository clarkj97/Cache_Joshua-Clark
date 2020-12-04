# Cache_Joshua-Clark
Direct Cache Mapping Simulator Code.
Submitted by: Joshua Clark
Class: CEC 470
Date: 03 December 2020


Direct Cache Mapping simulator. Included files:

DirectCache.cpp --> C++ File
DirectCache.h  --> The main header file
TestAddressSequences.h  -->  Header file containing the given test sequences to be used in the simulation.





Build Notes:
--> This program was written in Visual Studio Code 2019
--> To test different sequences, navigate to 'TestAddressSequences.h' and un-comment the #define SEQ#. Then run the program.
--> 'TestAddressSequences.h' was added as a #include in 'DirectCache.h'.
--> needed to change this:


    blocks = new (int[number_of_lines_in_cache, number_of_words_in_block]);


to this:

    blocks = new (int[number_of_lines_in_cache * number_of_words_in_block]);

In other words, change the comma to a star. Otherwise the IDE could run it.

Graph Data:

the provided pdf provides a graph of the percentage of hits recorded for each
Word ID bit and instruction sequence. Sequence 03 provided the highest percentage
of hits (93%) across all word ID bits, while sequence 01 had the lowest (0%). Sequence 
05 had an initial hit percentage of 19% for a word ID bit of 1 while the other 4 word 
ID bits remained at 58%.
