*  Created on: Feb 21, 2023
 *      Author: justinshi
 */
#include <iostream>
using namespace std;
extern "C" long findHorizontalCross(int n);
extern "C" long nCr(long n, long r);
extern "C" long fact(long n);
int main() {
    //this code is supposed to read in the number of tests cases the loop starting from 1 to that testcase then it will call the findHorizaontalCross function and print from 1 to testcases values
    int testCases = 0;
    cin >> testCases;
    for (long i = 1; i <= testCases; i++) {
        long tem = nCr(i*i, 2);
        long possible = tem-findHorizontalCross(i);
        cout << possible<< endl;
    }
    return 0;
}
long findHorizontalCross(int n) {
    //finds all the 2 by 3 arrays that can fit in a n by n array
   return 2*(n-3+1)*(n-2+1);
}
long nCr(long n, long r)
{
    return fact(n) / (fact(r) * fact(n - r));
}

// Returns factorial of n
long fact(long n)
{
      if(n==0)
      return 1;
    long res = 1;
    for (long i = 2; i <= n; i++)
        res = res * i;
    return res;
}







