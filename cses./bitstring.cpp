//problem link https://cses.fi/problemset/result/5533574/
#include <iostream>
#include <math.h>
using namespace std;
extern "C" long long getPowerbase2(long long n);
int main(){
    long long n = 0;
    cin >> n;
    cout<<getPowerbase2(n)<<endl;
    return 0;
}
long long getPowerbase2(long long n){
    long long two =2;
    long long res = 0;
  if (n <= 29 ){
    return pow(2,n);
  }
  else{
   res = fmod(pow(2, 30), 1000000007);
    for (long long i = 31; i <= n; i++){
        res = fmod(res*2, 1000000007);
    }
    return res;
  }
    
}
