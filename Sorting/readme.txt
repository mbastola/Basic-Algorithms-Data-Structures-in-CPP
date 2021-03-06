Compile all by typing 'make sorttimes' that will compile all 3 programs in this project.

Alternatively you can compile each programs as follows;

--sorts.cc--
To compile: make sorts
 
This program has various sorting functions that sort the given array in different ways. For question no 1) I have implemented Insertion ,Selection, Quick and Merge sort algorithms. The quickSort function has two sub/helper functions namely quickSorthelper and partition. I had issues with array index when not decreasing the high index by one. Thus I created the helper function that implements the quicksort by decreasing the high index by one. The mergeSort too takes in a sub function called merge that creates two arrays dynamicallly by using 'new' method but deletes them before returning so that there is not memory leakage. 

sorts.cc also has new functions for question 4) namely insertionSort,selectionSort and quickSort. They take in two pointers that point to high and low index of the array instead of a array and two indices as in question 1). All the sorts have their respective headers in sorts.h file

--fillArray.cc --
To compile: make fillArray

This program has functions that fill the arrays in mixed, increasing and decreasing order. 


Both fillArray.cc and sorts.cc do not have main function in them so to run them you need to call sorttimes.cc

--sorttimes.cc--

to compile: make sorttimes

to Run: ./sorttimes filename initialOrderingType size1 size2 ....

This program has the main function in it. It calls in all the needed files such as sorts.h, fillArrays.h and other standard Clib files.Also it calls in Boost library for time implementation. It takes first commandline argument as filename where you can see the time taken by successive sorting algoritms. For example, with mixed ordering type I got following result. As defined in the question the first column in for array size,2nd for insertionSort, 3rd for Selection, 4th for Quick and 5th for Merge Sort.

Q3)Analysis:

As we can see from the data in graphs.pdf,

The initial ordering affects the perfomance of the sorts. Specific
sort algoirithmshave their best and worst cases with specific orderings.   

For mixed list the performance of quickSort and mergeSort was faster
while insertion and selection performed poorly. Insertion works better
than slection as inserting is faster relative to swapping that goes in
selection sort. However they are both slow. This attributes to the
O(n^2) in the worst case for  of slection sort and insertion sort. For
mixed arrays the quick(best case) and merge sorts(average case)both  have O(nlogn) efficiency.

For sorted lists, the insertion sort works faster which is best case
efficiecny for insertion sort. Here the O(n^2) becomes O(n) as only
one comparison needs to be done on each pass i.e n comparisions for
entire list. However this ordering type is bad for quick sort as its
O(nlogn) efficiency breaks down to O(n^2). Here each passes divides
the list into size 0 and n, 1 and n-1, 2 and n-2 and so on for n times
giving n^2 recursions. Also there is an space overhead for computing
the sub functions recursively. Hence its even worse than selection sort.

In reverse sorted arrays,Quick sort still performs worst due to
n^2 operations and recursive overheads. The insertion sort here performs bad
because it has to move each element in the first position of the array
that breaks it efficiency to n^2 operations. It is even worse than a
mixed list case or selection sort in reverse list as in the former,
the number of shifts are lesser and in the latter number of swaps are
lesser. Merge sort is also stable and maintains its O(nlogn) average
case. Again the quick sort fails moiserably. Selection sort performs b
etter tha quick sort because of less computational overhead of recursion.

Issues:
 -sorting not tested with negative numbers.
