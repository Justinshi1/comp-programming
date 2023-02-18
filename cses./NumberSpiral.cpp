
using namespace std;
#include <iostream>
#include<algorithm>
extern "C" int findDiagnalNumber(int n);
extern "C" int isRow(int row, int col, int maxNum);
 int main (){
    int testCases = 0;
    cin>>testCases;
    int output[testCases];
    for(int i = 0; i<testCases; i++){
      int row = 0;
      int col = 0;
      cin>>row>>col;
      int maxNum = max(row-1, col-1);
      int diagNum = findDiagnalNumber(maxNum);
      int dir = 1; // 1 stands for clockwise 0 means counterclockwise
      int step = abs((maxNum-row)+(maxNum-col));
      int isrow = isRow(row, col, maxNum);

      if(isrow ==0){
        output[i] = diagNum;
        continue;
      }
      if(maxNum%2 == 0 ){
        //counterclockwise
        dir = 0;
        if(isrow == -1){
          output[i] = diagNum-col;
        }
        else{
          output[i] = diagNum+row;
        }

      }
      else{
        //clockwise case
        if(isrow == -1){
          output[i] = diagNum+col;
        }
        else{
          output[i] = diagNum-row;
        }
      }

    }
    for(int i = 0; i<testCases; i++){
      cout<<output[i]<<endl;
    }
    return 0;
 }
 int findDiagnalNumber(int n){
  return n*n+n+1; //I LOVE CALCULUS
 }
 int isRow(int row, int col, int maxNum){
  //-1 is part of a row, 1 is col, 0 is a diagnol number 
  if(row>col){
    return -1;
  }
  else if (row<col){
    return 1;

  }
  else {
    return 0;
  }
 }

 
