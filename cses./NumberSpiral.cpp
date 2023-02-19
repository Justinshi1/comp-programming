
 //problem link https://cses.fi/problemset/task/1071/
using namespace std;
#include <iostream>
#include<algorithm>
extern "C" long findDiagnalNumber(long n);
extern "C" long isRow(long row, long col, long maxNum);
int main() {
    long testCases = 0;
    cin >> testCases;
    long* output = new long[testCases];
    for (int i = 0; i < testCases; i++) {
        long row = 0;
        long col = 0;
        cin >> row >> col;
        row--;
        col--;
        long maxNum = max(row , col );
        long diagNum = findDiagnalNumber(maxNum);
        long dir = 1; // 1 stands for clockwise 0 means counterclockwise
        long step = abs((maxNum - row) + (maxNum - col));
        long isrow = isRow(row, col, maxNum);

        if (isrow == 0) {
            output[i] = diagNum;
            continue;
        }
        if (maxNum % 2 == 0) {
            //counterclockwise
            dir = 0;
            if (isrow == -1) {
                output[i] = diagNum -(maxNum -col) ;
            }
            else {
                output[i] = diagNum + (maxNum - row);
            }

        }
        else {
            //clockwise case
            if (isrow == -1) {
                output[i] = diagNum +(maxNum- col); 
            }
            else {
                output[i] = diagNum - (maxNum - row);
            }
        }

    }
    for (int i = 0; i < testCases; i++) {
        cout << output[i] << endl;
    }
    delete output;
    return 0;
}
long findDiagnalNumber(long n) {
    return n * n + n + 1; //I LOVE CALCULUS
}
long isRow(long row, long col, long maxNum) {
    //-1 is part of a row, 1 is col, 0 is a diagnol number 
    if (row > col) {
        return -1;
    }
    else if (row < col) {
        return 1;

    }
    else {
        return 0;
    }
}
