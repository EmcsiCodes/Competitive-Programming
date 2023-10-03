#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream in("tastatura2.in");
    ofstream out("tastatura2.out");
    string s1, s2;
    getline(in,s1);
    while(s1!="*"){
        getline(in,s2);
        unordered_map<char,int> freq1, freq2;
        for(int i=0; i<s1.length(); i++){
            freq1[s1[i]]++;
        }
        for(int i=0; i<s2.length(); i++){
            freq2[s2[i]]++;
        }
        int res = 0;
        for(auto i:freq1){
            if(i.second!=freq2[i.first]) res++;
        }
        out<<res<<'\n';
        getline(in,s1);
    }
    return 0;
}