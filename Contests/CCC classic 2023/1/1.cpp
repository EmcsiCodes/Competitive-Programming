#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <map>
#include <fstream>

using namespace std;
#define inf 100000000

int main()
{
    ifstream f("level1_5.in");
    ofstream g("level1_5.out");
    int n;
    f>>n;
    string x;
    for(int i=0; i<n; i++){
        string s;
        f>>s;
        unordered_map<char,int> m;
       for(int j=0; j<s.length(); j++){
            m[s[j]]++;
        }
        g<<m['W']<<" "<<m['D']<<" "<<m['S']<<" "<<m['A']<<endl;
    }
    return 0;
}