#include "BinHeap.hpp"
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;


BinHeap::BinHeap(string arr[], int len) {
	heaplen = 0;
	arrlen = len;
	heap = new string[arrlen];
	for (int i = 0; i < len; i++) {
		insertHeap(arr[i]);
	}
	printHeap();
}

BinHeap::~BinHeap() {
	delete [] heap;
}

void BinHeap::printHeap() {
	cout << endl;
	for (int i = 0; i < arrlen;i++) {
		cout << i << ", ";
	}
	cout << endl;
	for (int i = 0; i < heaplen;i++) {
		cout << heap[i] << ", ";
	}
	cout << endl;
}

int BinHeap::findMax(int x, int y) {
	if ((x < heaplen) && (y < heaplen)) {
		if (heap[x] > heap[y]) {
			return(x);
		}
		else {
			return(y);
		}
	}
	else if (x < heaplen) {
		return x;
	}
	else return -1;
}
void BinHeap::insertHeap(string s) {
	if(heaplen==0){
		heap[0]=s;
		heaplen++;
	}
	else{
		heaplen++;
		heap[heaplen-1]=s;
		bubbleUp(heaplen-1);
	}
	/* here – look at the .hpp for a description of the method that goes here */
}
string BinHeap::deleteHeap() { // returns the string that was deleted
	string temp=heap[0];
	heap[0]=heap[heaplen-1];
	heaplen--;
	bubbleDown(0);
	return temp;
	/* here – look at the .hpp for a description of the method that goes here */
}

void BinHeap::bubbleUp(int i) {
	bool test=findMax(i,(i-1)/2)==i;
	while(test){
		string temp=heap[i];
		heap[i]=heap[(i-1)/2];
		heap[(i-1)/2]=temp;
		i=((i-1)/2);
		if(i==0){
			test=false;
		}
		else{
			test=findMax(i,(i-1)/2)==i;
		}
	}
	/* here – look at the .hpp for a description of the method that goes here */
}
void BinHeap::bubbleDown(int i) {
	bool test=true;
	int max=findMax(2*i+1,2*i+2);
	if(max==-1){
		test=false;
	}
	else{
		test=findMax(i,max)==max;
	}
	while(test){
			string temp=heap[max];
			heap[max]=heap[i];
			heap[i]=temp;
			i=max;
			max=findMax(2*i+1,2*i+2);
			if(max==-1){
				test=false;
			}
			else{
				test=findMax(i,max)==max;
			}

	}
	/* here – look at the .hpp for a description of the method that goes here */
}
/***************************************************************************/
/* Part 2 */
string BinHeap::deleteHeap2() {
	string temp=heap[0];
	heap[0]=heap[heaplen-1];
	heap[heaplen-1]=temp;
	heaplen--;
	bubbleDown(0);
	return temp;
	/* here – look at the .hpp for a description of the method that goes here */
}
void BinHeap::deleteAll() {
	int len =heaplen;
	for(int i=0;i<len;i++){
		deleteHeap2();
	}
	heaplen=len;
/* here – look at the .hpp for a description of the method that goes here */
}
