# Sorted-List-via-cpp

IMPORTANT! : Programming assignment is given as as EE441 - Programming Assignment 1 (7).pdf
 .

This project contains the implementation of a SortedList class and accompanying test cases to verify its functionality. The code  demonstrates the use of dynamic arrays, exception handling, and various list operations.

Features of the SortedList Class
1. Dynamic Sorted Storage : Maintains a list of floating-point numbers in sorted order automatically.

2. Core Functionalities:

Insertion: Adds elements while preserving the sorted order.
Deletion: Removes elements at a specified index.
Copying: Deep copy of one sorted list into another.
Index Access: Retrieves elements by their index with bounds checking.
Find: Searches for an element and returns its index using binary search.
Print: Outputs all elements in the list to the console.
Exception Handling : Throws exceptions for invalid operations (e.g., out-of-range index, exceeding maximum capacity).
Macro Definition : Uses SORTEDLIST_MAX_SIZE to define the maximum number of elements (set to 20).

I tested the code in Code::Blocks, and the output from the compiler was as follows:
Original List: 1 2 3 4.5 5.5
Copied List: 1 2 3 4.5 5.5
Copy test successful if both lists match.
Trying to access index 5 (out of range):
Passed out-of-range index test: Index is out of range
Accessing valid index 1: 20
Passed valid index access test.
Initial List: 10 20 30

Trying to remove element at index 5 (out of range):
Passed out-of-range remove test: Index is out of range

Initial List: 10 20 30

Removing element at index 1 (should be 20.0):
Removed element: 20
List after removal: 10 30
Passed valid remove test if list is updated correctly.

Current List for find tests: 10 20 30

Trying to find 40.0 (not in the list):
Passed non-existent element find test: Number is not in the list

Current List for find tests: 10 20 30

Finding 20.0 (should be at index 1):
Found 20.0 at index: 1
Passed valid find test if index is correct.
Inserting random values into the list:
Inserting 41...
41
Inserting 67...
41 67
Inserting 34...
34 41 67
Inserting 0...
0 34 41 67
Inserting 69...
0 34 41 67 69
Inserting 24...
0 24 34 41 67 69
Inserting 78...
0 24 34 41 67 69 78
Inserting 58...
0 24 34 41 58 67 69 78
Inserting 62...
0 24 34 41 58 62 67 69 78
Inserting 64...
0 24 34 41 58 62 64 67 69 78
Inserting 5...
0 5 24 34 41 58 62 64 67 69 78
Inserting 45...
0 5 24 34 41 45 58 62 64 67 69 78
Inserting 81...
0 5 24 34 41 45 58 62 64 67 69 78 81
Inserting 27...
0 5 24 27 34 41 45 58 62 64 67 69 78 81
Inserting 61...
0 5 24 27 34 41 45 58 61 62 64 67 69 78 81
Inserting 91...
0 5 24 27 34 41 45 58 61 62 64 67 69 78 81 91
Inserting 95...
0 5 24 27 34 41 45 58 61 62 64 67 69 78 81 91 95
Inserting 42...
0 5 24 27 34 41 42 45 58 61 62 64 67 69 78 81 91 95
Inserting 27...
0 5 24 27 27 34 41 42 45 58 61 62 64 67 69 78 81 91 95
Inserting 36...
0 5 24 27 27 34 36 41 42 45 58 61 62 64 67 69 78 81 91 95
List after inserting 20 elements:
0 5 24 27 27 34 36 41 42 45 58 61 62 64 67 69 78 81 91 95

Trying to insert another element after reaching max capacity (should throw length_error):
Passed max capacity insertion test: The list is full

Process returned 0 (0x0)   execution time : 0.114 s
Press any key to continue.







