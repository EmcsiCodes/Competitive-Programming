#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;
ifstream in("pufu.in");
ofstream out("pufu.out");
int TestNum, n;

int main(){
    in>>TestNum;
    for(int i=0; i<TestNum; i++){
        in>>n;
        unordered_map<string,int> ump;
        for(int j = 0; j<n; j++){
            string s;
            in>>s;
            ump[s] ++;
        }
        out<<ump["ciocolata"]<<" "<<ump["cascaval"]<<" "<<ump["sare"]<<'\n';
    }
}