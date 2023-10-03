#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main()
{
    int n;
    cin>>n;
    map<int,int> m;
    vector<int> v(2*n+1,0);
    vector<int> t;
    int last = 0;
    for(int i=1; i<=n; i++){
        int x,y;
        cin>>x>>y;
        v[x] = v[i] + 1;
        v[y] = v[i] - 1;
        if(x>n) m[v[x]]++;
        if(y>n) m[v[y]]++;
    }
    int res = 0;
    int maxOcc = 0;
    int maxOccIndex = 0;
    for(auto i:m){ //map<int,int> m
        if(maxOcc<i.second){ //???
            maxOcc = i.second;
            maxOccIndex = i.first;
        }
    }
    cout<<maxOccIndex<<" "<<maxOcc;
    return 0;
}
/*
5
2 3
6 4
7 5
8 9
10 11
*/