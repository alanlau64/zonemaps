# CS 561: Data Systems Architecture - TemplateZonemaps


## About

TemplateZonemaps is a simple template for you, the student, to use for the simple
implementation project in CS 561. Note that this is a high level template, it is
not extensive, rather it is meant to help guide you on what we expect when
you implement the zonemaps. You can use this as base code or start from
scratch. You may require additional helper functions to satisfy the requirements of the project.

## Generating Workloads
You will be asked to generate workloads of a specific size, with varying noise levels. A workload generator
is provided as part of the API that performs the required functionality. Here, noise (%) is the percentage (int) 
of out of order elements, and windowThreshold(%) is the window (as percentage of total elements) within which an
out of order element can be placed from its original location. So, a 5% noise and 5% window threshold means 
5% of the total domain size of elements will be out-of-order and each of these out-of-order elements will be 
placed within a 5% window from its original (sorted) location. Compile the workload generator using 
the "make" command, and execute using
```c
./workloadgenerator <domain_size> <noise_percentage> <windowThreshold>
```
For example, to generate a workload of 1 Million integers with 0% noise and 5% windowThreshold, use: 
```c
./workloadgenerator 1000000 0 5
```

## Zone Map Header
The zonemaps.h header file is a template that defines the basic components of a zone map data structure. It is 
required to implement the data structure using this template in a separate file named "zonemaps.cpp". You are 
free to modify certain components of the template to improve performance of the data structure, however the core 
functionality should remain the same. In your implementation, it is important to comment your code to highlight various 
design decisions and logic. 

## Testing 
The main.cpp file provides a foundational testing framework expected for this project. You are required to generate the 
workloads, read the data and build the zone map, perform point queries and range queries. For point queries, use the simple 
query generator function inside the main.cpp file. Refer to the assignment instruction document for range queries. Both point 
queries and range queries are to be timed for evaluating performance. The execution times are to be written either into a log file
or displayed onto the terminal along with 
other relevant details about the workload, such as: domain size, noise percentage, window threshold, etc. 

Compile all files using the "make" command. 
There are currently 4 test cases pre-configured in main.cpp, as per the assignment request. Once the implementation of zone maps is 
complete, you will be required to fill in the appropriate test call in the main.cpp file for the point/range queries. To run a specific test case, 
use the command: 
```c
./main <input_file> <test_case>
```
For example, to run point queries on an input file:
```c
./main ./data_1000000-elems_0-kperct_5-lperct_1seed1611707662.dat test_pq
```

## Contact

If you have any questions please feel free to see Aneesh in office hours, or
email your queries at aneeshr@bu.edu.
