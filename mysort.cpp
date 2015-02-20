/*    @file mysort.cpp    
      @author Matt Hoendorf <hoendomd@mail.uc.edu>
      @date 11.04.14

			@description This program will sort line-by-line
			whatever is given on standard
			input, and print the result to the screen.  
			
			By default each line will be interpreted as a string, but if
			-n is given, each line will be converted to an int (using atoi)
			and sorted.
			
			By default merge sort should be used.  
			If -h, heapsort should be used.
			If -m, mergesort should be used.
			If -i, insertion sort should be used.
			
			The last sort command should be followed.
*/
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <algorithm>

#include <MinHeap.h>

using namespace std;

template <class T> 
void print(vector<T> &v){
  for(unsigned int i = 0; i < v.size(); i++){
    cout << v[i] << endl;
  }
}

template <class T> 
void merge(vector<T> &a, vector<T> &b, vector<T> &v){
  unsigned int ai = 0;
  unsigned int bi = 0;
  while(ai < a.size() || bi < b.size()){
    if( ai == a.size()){
      v.push_back(b[bi]);
      bi++;
    }else if( bi == b.size()){
      v.push_back(a[ai]);
      ai++;
    }else if(a[ai] < b[bi]){
      v.push_back(a[ai]);
      ai++;
    }else{
      v.push_back(b[bi]);
      bi++;
    }
  }
  return;
}

template <class T> 
void mergeSort(vector<T> &v){ // In place!
  // base case!
  if(v.size() <= 1){
    return;
  }
  // cut list into two halves
  int middle = v.size() / 2;
  vector<T> left;
  left.reserve(v.size());
  vector<T> right;
  right.reserve(v.size());
  for(unsigned int i = 0; i < v.size(); i++){
    if(i < middle){
      left.push_back(v[i]);
    }else{
      right.push_back(v[i]);
    }
  }
  // sort (mergesort) each of the smaller lists
  mergeSort(left);
  mergeSort(right);
  // merge them together!
  v.clear();
  merge(left, right, v);
}

template <class T>
void insertionSort(vector<T> &v)
{
  int i, j, n = v.size();
  T target;
  for (i = 1; i < n; i++)
  {
    j = i;
    target = v[i];
    while (j > 0 && target < v[j-1])
    {
      v[j] = v[j-1];
      j--;
    }
    v[j] = target;
  }
}

int main(int argc, char* argv[]){
  
  int nflag = 0;
  int mflag = 0;
  int iflag = 0;
  int hflag = 0;
	int i = 0;
	string usage = "Usage: ./mysort [optional -n parameter] < [text_file.txt]";
  
  while ((i = getopt (argc, argv, "nmih")) != -1){
    switch (i){
      case 'n':
        nflag = 1;
        break;
      case 'm':
      	mflag = 1;
        break;
      case 'i':
      	iflag = 1;
        break;
      case 'h':
      	hflag = 1;
        break;
      case '?':
				if (isprint (optopt))
          fprintf (stderr, "Unknown option `-%c'.\n", optopt);
        else
          fprintf (stderr, "Unknown option character `\\x%x'.\n", optopt);
        return 0;
      default:
      	abort();
    }
  }
  
  // Open file given (argv depends on if -n is given)
  if(nflag == 1){
    vector<int> data;
 		int size = 0;
 		int num;
    while(cin >> num){
  		data.push_back(num);
 			size++;
  	}
    if((iflag == 1) && (mflag == 0) && (hflag == 0)){
      insertionSort(data);
      print(data);
    }
    else if((hflag == 1) && (mflag == 0) && (iflag == 0)){
      MinHeap<int> heap;
      for(unsigned int i = 0; i < data.size(); i++){
        heap.push(data[i]);
      }
      while(heap.size() != 0){
        cout << heap.top() << "\n";
        heap.pop();
      }
    }
    else{
      mergeSort(data);
      print(data);
    }
  }
 	
 	else{
 		vector<string> data;
 		int size = 0;
    string str;
 		while(cin >> str){
 			data.push_back(str);
 			size++;
  	}
  	if((iflag == 1) && (mflag == 0) && (hflag == 0)){
      insertionSort(data);
      print(data);
    }
    else if((hflag == 1) && (mflag == 0) && (iflag == 0)){
      MinHeap<string> heap;
      for(unsigned int i = 0; i < data.size(); i++){
        heap.push(data[i]);
      }
      while(heap.size() != 0){
        cout << heap.top() << "\n";
        heap.pop();
      }
    }
    else{
      mergeSort(data);
      print(data);
    }
 	}


  return 0;
}
