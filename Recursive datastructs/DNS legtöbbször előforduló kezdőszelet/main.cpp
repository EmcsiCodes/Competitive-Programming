#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    unordered_map<string,int> m;
    for(int i=1; i<=n; i++){
        string s;
        cin>>s;
        if(s.length()>k) s.erase(k);
        m[s]++;
    }
    int maxFreq = 0;
    string maxFreqs;
    for(auto i:m){
        if(i.second > maxFreq){
            maxFreq = i.second;
            maxFreqs = i.first;
        }
    }
    cout<<maxFreq<<'\n'<<maxFreqs;
    return 0;
}
/*
8 3
AGG
AGGTCGA
AG
GAGA
GAGGCG
AGGTGC
GATACT
ATAGCC
*/