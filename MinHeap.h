#ifndef MINHEAP_H
#define MINHEAP_H 
/*    @file MinHeap.h    
      @author Matt Hoendorf <hoendomd@mail.uc.edu>
      @date 11.04.14

			@description Implements a templated minimum queue, using a
			heap structure.
*/
#include <vector>
#include <stdexcept>
#include <iostream>

using namespace std;

template <class T> class MinHeap{
public: 

MinHeap(){
	q_data.resize(0);
}

~MinHeap(){}

void push(T value){
	q_data.push_back(value);
  int pos = q_data.size()-1;
  int parent = (int)(pos-1)/2;
  while(parent >= 0 && q_data[pos] < q_data[parent]){
  	swap(parent, pos);
  	pos = parent;
  	parent = (int)(pos-1)/2;
  }
  return;
}

void pop(){
	if(q_data.size() == 0){
    throw logic_error( "The queue is empty - nothing to pop." );
  }
	else{
		q_data[0] = q_data[q_data.size()-1];
		q_data.pop_back();
		int pos = 0;
		bool bubDown = (2*pos+1 < q_data.size());
		while(bubDown){
			if(2*pos+1 >= q_data.size()){
				bubDown = false;
			}
			else if(2*pos+2 >= q_data.size()){
				if(q_data[pos] > q_data[2*pos+1]){
					swap(pos, 2*pos+1);
					pos = 2*pos+1;
				}
				bubDown = false;
			}
			else{
				if(q_data[pos] > q_data[2*pos+1] && q_data[2*pos+1] <= q_data[2*pos+2]){
					swap(pos,2*pos+1);
					pos = 2*pos+1;
				}
				else if(q_data[pos] > q_data[2*pos+2]){
					swap(pos, 2*pos+2);
					pos = 2*pos+2;
				}
				else{
					bubDown = false;
				}
			}
		}
  }
}

T top(){ 
	if(q_data.size() == 0){
    throw logic_error("The queue is empty - nothing to return.");
  }
  else{
    return q_data[0];
  }
}

void swap(int i, int j){
	T temp = q_data[i];
	q_data[i] = q_data[j];
	q_data[j] = temp;
	return;
}

unsigned int size(){ 
	return q_data.size();
}

private:

	vector<T> q_data;

};

#endif
