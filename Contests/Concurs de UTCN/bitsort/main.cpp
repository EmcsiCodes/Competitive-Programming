#include <iostream>
#include <vector>

using namespace std;

struct linkedList{
    int num;
    struct LL * next;
}LL;

int sortBits(int k,vector<int> bits, vector<int> sortedBits){
    vector<int> currBits(sortedBits.size(), 0);
    for(int i=0; i<bits.size(); i++){
        currBits[i] = bits[0];
    }
    if(k == bits[0]){

    }
}

int main(){
    int n, m;
    cin>> n >> m;
    vector<int> bits;
    int ones = 0, zeros = 0;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        bits.push_back(x);
        if(x == 1) ones++;
        else zeros++;
    }
    int first = 0, second = 0;
    vector<int> sortedBits;
    for(int i=0; i<m; i++){
        int x;
        cin>>x;
        sortedBits.push_back(x);
        if(i%2 == 0) first += x;
        else second += x;
    }
    if(zeros == ones){
        //start with the first '1' or '0'
        if(bits[0] == 1){
            //start with 1

        } else {
            //start with 0
        }
    } else {
        if(zeros == first){
            //start with '0'
        } else {
            //start with '1'
        }
    }
    return 0;
}