#include <iostream>
#include <map>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    string s;
    ifstream in("je.be");
    getline(in,s,'#');
    int treeNum = 0, currTree, p = 0, maxx = 0;
    int prev = 0;
    int freq[100001] = {0}, treeAt[100001] = {0};
    for(int i=0; i<s.length(); i++){
        if(s[i] == '(') {
            freq[currTree]++;
            p++;
        }
        if(s[i] == ')') {
            currTree--;
            p--;
        }
        if(p == prev){
            prev = treeNum;
        }
        if(s[i] == 'F') {
            treeNum++;
            currTree = treeNum;
            if(i>0 && s[i - 1] == 'F' || i == 0) freq[currTree - 1]++;
        }
    }
    for(int i=0; i<treeNum; i++) {
        maxx = max(maxx,freq[i]);
        cout<<freq[i]<<" ";
    }
    cout<<treeNum - 1<<'\n'<<maxx;
    return 0;
}