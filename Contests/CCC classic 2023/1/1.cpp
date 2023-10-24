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
    ifstream f("level1_5.txt");
    ofstream g("level1_5.out");
    int n;
    f>>n;
    char a[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            f>>a[i][j];
        }
    }
    int x;
    f>>x;
    for(int i=0;i<x;i++)
    {
        int aa,bb;
        f>>aa;
        char c;
        f>>c;
        f>>bb;
        g<<a[bb][aa]<<endl;
    }
    return 0;
}