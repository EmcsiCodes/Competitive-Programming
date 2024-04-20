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
    ifstream f("level2_0.in");
    ofstream g("level2_e.out");
    int n;
    f>>n;
    string x;
    for(int i=0; i<n; i++){
        string s;
        f>>s;
        int x,y;
        x=y=0;
        int maxup, maxdown, maxleft, maxright;
        maxup = 0;
        maxright = 0;
        maxleft = 0;
        maxdown = 0;
        for(int j=0;j<s.length();j++)
        {
            if(s[j] == 'W') x++;
            if(s[j] == 'S') x--;
            if(s[j] == 'A') y--;
            if(s[j] == 'D')  y++;
            maxup = max(maxup, x);
            maxdown = min(maxdown, x);
            maxright = max(maxright, y);
            maxleft = min(maxleft, y);
        }
        g<<maxleft <<"-"<<maxright<<" "<<maxdown<<"-"<<maxup<<endl;
    }
    return 0;
}