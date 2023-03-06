using namespace std;
#include <iostream>
#include<algorithm>
int main() {
    long long lines = 0;
    cin >> lines;
    long long days = 0;
    cin >> days;
    long long total = 0;
    long long prevEndDay = 0;
    long long numHayBales = 0;
    long long dayOfDelivery = 0;
    long long start = 0;
    int flag = 0;
    for (long long i = 1; i <= lines; i++) {
        cin >> dayOfDelivery;
        cin >> numHayBales;
        if (dayOfDelivery > days) {
            break;
        }
        if(flag == 1){
            break;
        }
        long long endDay = dayOfDelivery + numHayBales - 1;
        if(endDay >= days){
            endDay = days;
            flag = 1;
        }
        if (dayOfDelivery > prevEndDay) {
            //no overlap case
            start = dayOfDelivery;
            
             prevEndDay = endDay;
        }
        else { // overlap case
            start = prevEndDay + 1;
            endDay = prevEndDay + numHayBales;
            if(endDay >= days){
                endDay = days;
                flag = 1;
            }
            prevEndDay = endDay;
        }
        //calculate end day
       
        total += endDay - start + 1;
        if (total >= days) {
            total = days;
            break;
        }
       
    }
    cout << total << endl;
    return 0;
}
