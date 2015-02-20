/*
  MinHeap_test.h
  Unit tests for MinHeap
  
*/

#include "MinHeap.h"
#include <stdexcept>
#include <string>
#include <stdlib.h>

#include <cxxtest/TestSuite.h>

class MyTests : public CxxTest::TestSuite {
public:

	void testSize1() {
    MinHeap<int> a;
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  void testSize2() {
    MinHeap<int> a;
    a.push(1);
    a.push(1);
    a.push(1);
    a.push(1);
    a.push(1);
    TS_ASSERT_EQUALS(a.size(), 5);
  }
  void testPop1() {
    MinHeap<int> a;
		try{
			a.pop();
		}catch(exception &e){
			return;
		}
		TS_ASSERT(0);
  }
  void testPop2() {
    MinHeap<int> a;
    a.push(1);
    a.pop();
		try{
			a.top();
		}catch(exception &e){
			return;
		}
		TS_ASSERT(0);
  }
  void testPop3() {
    MinHeap<int> a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.pop();
    TS_ASSERT_EQUALS(a.top(), 2);
  }
  void testPop4() {
    MinHeap<int> a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.pop();
    TS_ASSERT_EQUALS(a.size(), 2);
  }
  void testTop1() {
    MinHeap<int> a;
    a.push(1);
    a.push(3);
    a.push(5);
    TS_ASSERT_EQUALS(a.top(), 1);
  }
  void testTop2() {
    MinHeap<int> a;
    a.push(5);
    a.push(3);
    a.push(1);
    TS_ASSERT_EQUALS(a.top(), 1);
  }
  void testTop3() {
    MinHeap<int> a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.push(5);
    a.push(6);
    a.pop();
    a.pop();
    a.pop();
    TS_ASSERT_EQUALS(a.top(), 4);
  }
  void testTop4() {
    MinHeap<int> a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.push(5);
    a.push(6);
    a.pop();
    a.pop();
    a.pop();
    a.pop();
    a.pop();
    TS_ASSERT_EQUALS(a.top(), 6);
  }


};
