/*    @file randNums.cpp    
      @author Paul Talaga
      @date November 2 2014

			@description This program will print to the screen a series
			for random integers under 1,000 separated with a newline.
			
			An optional paramter allows you to specify how many numbers
			to produce, with K and M units allowed (K=1,000 and M=1,000,000)
			
			Ex:
			g++ -O3 -o randNums randNums.cpp
			./randNums 1M > test.txt
			Will fill test.txt with 1 million random numbers. About 4.7MB worth.
*/

#include <iostream> 
#include <stdlib.h>

using namespace std;

int main(int argc, char* argv[]){
  srand(time(0));
  
  long size = 10; // # number to output by default
  
  if(argc > 1){
    string input = string(argv[1]);
    unsigned long scale = 1;
    int loc = input.length();
    if(input.find("K") != string::npos){
      scale = 1000;
      loc = input.find("K");
    }else if(input.find("M") != string::npos){
      scale = 1000000;
      loc = input.find("M");
    }
    long number = atoi(input.substr(0,loc).c_str());
    size = number * scale;
  }

  while(size > 0){
    cout << rand() % 100000<< endl;
    size--;
  }
  return 0;
}
