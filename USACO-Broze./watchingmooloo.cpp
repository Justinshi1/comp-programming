#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    long long* days = new long long[n];
    for (int i = 0; i < n; i++) {
        cin >> days[i];
    }

    long long totalCost = 0;

    long long groupStart = days[0];
    long long groupCost = 1+k;
   
    int flag = 0;
    for (int i = 1; i < n; i++) {
        
        if (days[i] - days[i-1] + 1 <= k+1) {
           
            //group case
            groupCost = days[i] - groupStart + 1 + k;
            if (i == n - 1) {
                totalCost += groupCost;
            }
        }
        else {
            // previous group cost
            totalCost += groupCost;
            groupCost = 0;
            //new group start
            groupStart = days[i];
            groupCost = 1 + k; 
            if (i == n - 1) {
                totalCost += groupCost;
            }

        }
    }

    cout << totalCost << endl;

    return 0;
}
