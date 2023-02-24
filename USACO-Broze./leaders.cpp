//2023 january problem 1

#include <iostream>
using namespace std;
//first generate string array for all cows 
//check if array fits into valid leader qualities 
//if it does add to leader count 
//divide leader count by two to find pairs of leaders
int main(){
    unsigned int gLeaders = 0;
    unsigned int hLeaders = 0;
    unsigned int firstIndexG = 0;
    unsigned int firstIndexH = 0;
    unsigned int numCows = 0;
    cin >> numCows;
    bool leaderArray[numCows];
    string cows = "";
    cin >> cows;
    firstIndexG = cows.find_first_of('G');
    firstIndexH = cows.find_first_of('H');
    unsigned int cowList[numCows];
    //int cowList [] = {2, 2, 3};


    //the index starting from one each cows list extends till
    for(int i = 0; i < numCows; i++){
        cin >> cowList[i];
    }
    if(cows.find_first_of('G')+cowList[cows.find_first_of('G')]-1 >= cows.find_last_of('G')){
        gLeaders++;
        firstIndexG = cows.find_first_of('G');
        leaderArray[cows.find_first_of('G')] = true;
    }
    if(cows.find_first_of('H')+cowList[cows.find_first_of('H')]-1 >= cows.find_last_of('H')){
        hLeaders++;
        firstIndexH = cows.find_first_of('H');
        leaderArray[cows.find_first_of('H')] = true;
    }
    //second condition is does it contain a leader of the other cow this is based on the assumtion that at least one leader satisifies the first rule
    if(firstIndexH > firstIndexG){
        for(int i = firstIndexG; i < firstIndexH; i++){
            if(cows[i] == 'G' && cowList[i]-1 >= firstIndexH){
                leaderArray[i] = true;
                gLeaders++;
            }
        }
    }
    if(firstIndexG > firstIndexH){
        for(int i = firstIndexH; i < firstIndexG; i++){
            if(cows[i] == 'H' && cowList[i]-1 >= firstIndexG){
                leaderArray[i] = true;
                hLeaders++;
            }
        }
    }
    //now we have to find the total pairs of leaders each pair of leaders have to be different types
    cout << gLeaders*hLeaders << endl;




    return 0;
}
