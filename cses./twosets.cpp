//problem https://cses.fi/problemset/result/5533265/#test21
#include <iostream>
using namespace std;
extern "C" long findSum(long n);
int main() {
    long num = 0;
    cin >> num;
    long sum = findSum(num);
    if(sum%2==0){
        int arr[num];
        int arr1[num];
        long firstSize = 0;
        for(int i = 0; i<num; i++){
            arr[i] = i+1;
            arr1[i] = 0;
        }
        //if yes then print out two arrays that sum up to half of the sum
        cout << "YES" << endl;
        long half = sum/2;
        for(long i = num-1; i>= 0; i--){
            if(half - arr[i]>= 0){
                half = half - arr[i];
                arr1[i] = arr[i];
                arr[i] = 0;
               
                firstSize++;
            }
        }
        cout << firstSize << endl;
        for(int i = 0; i<num; i++){
            if(arr1[i]!=0){
                cout << arr1[i] << " ";
            }
           
        }
        cout<<endl;
        cout << num-firstSize<<endl;
        for(int i = 0; i<num; i++){
            if(arr[i]!=0){
                cout << arr[i] << " ";
            }
        }
        cout << endl;


    }
    else{
        cout << "NO" << endl;
    }
}
long findSum(long n){
    long sum = 0;
    sum = n*(n+1)/2;
    return sum;

}
