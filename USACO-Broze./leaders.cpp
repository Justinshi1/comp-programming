//problem jan 2023
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    // Read in the string of cow breeds
    string breeds;
    cin >> breeds;

    // Read in the list of E values
    vector<int> E(N);
    for (int i = 0; i < N; i++) {
        cin >> E[i];
    }

    int count = 0;

    // Loop through all possible pairs of cows (i, j)
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            // Check if the breeds of cows i and j are different
            if (breeds[i] != breeds[j]) {
                // Check if cow i's list includes cow j
                if (j <= E[i]) {
                    // Check if cow j's list includes either all cows of her breed or cow i
                    if (E[j] == N || breeds[j] == breeds[E[j]] || E[j] >= E[i]) {
                        count++;
                    }
                }
            }
        }
    }

    // Output the count of valid leader pairs
    cout << count << endl;

    return 0;
}
