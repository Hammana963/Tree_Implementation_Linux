# Tree_Implementation_Linux
Program that interacts with the system's actual filesystem (via system calls), 
traverses a portion of the directory hierarchy, and manages scarce resources. Recursively prints directory contents in a tree-like format.

Program is run using a Makefile
to run executable use the following command:
./tree_tests <directory on system>

the following tags can be used befor the <directory on system> argument for additional functionality.

[-a]: The -a switch causes "hidden" files to be processed.
[-s]: The -s switch causes the size for each file to be printed. For example,

./tree tmp
tmp [size: 192]
|-- alpha [size: 0]
|-- bob [size: 0]
|-- tmp [size: 224]
|   |-- alpha [size: 11]
|   |-- bob [size: 23]
|   |-- burrito [size: 0]
|   |-- tmp [size: 96]
|   |   |-- bob [size: 13]
|   |-- zebra [size: 13]
|-- zebra [size: 17]
