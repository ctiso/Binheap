/*
 * BinHeap.hpp
 *
 *  Created on: Nov 3, 2019
 *      Author: tisoc
 */

#ifndef BINHEAP_HPP_
#define BINHEAP_HPP_
#include <string>
using namespace std;

class BinHeap {
	public: /* yeah, everything’s public. No getters or setters. Deal with it. */
		int heaplen; /*The number of values in the heap */
		int arrlen; /*Note: this is the length of the ARRAY, not the number of values in the heap! */
		string *heap; /* the heap array (which just so happens to be located on the heap in memory – it’s allocated
		in the constructor */
		BinHeap(string arr[], int len); /* the constructor*/
		~BinHeap(); /* the destructor*/
		void printHeap(); /* a method for printing out the heap */
		int findMax(int x, int y); /* a method for finding the max of 2 strings in an array */

		void bubbleDown(int i); //7 pts
/* this method you’re writing. It takes an index (usually 0) and compares the value at that index with the
values of the two children (it calls findMax for that). If the value at the index is less than the value of the greatest
child, it swaps with the greatest child and the index becomes that of the greatest of the two children. It continues
until either it can’t bubble down any further or until neither child is greater than the parent (the value at the index */

		void bubbleUp(int i); // 7 pts
/* this method you’re writing – it takes an index (the last index in the HEAP (not the array) and compares the value in
the index with the value of its parent. If it is greater than the value of the parent, they swap and the current index
becomes that of its parent. It continues until the two don’t swap or until you hit the root */

		void insertHeap(string s); // 4 pts
/* you’re writing this one – this one calls bubble up after inserting a new value (s) into the heap and updating
the heap fields */
		string deleteHeap();
		string deleteHeap2();
		void deleteAll(); //2 pts

};
#endif /* BINHEAP_HPP_ */
