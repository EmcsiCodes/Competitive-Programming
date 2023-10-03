#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int k,m,n;
    cin>>k>>m>>n;
    vector<int> v(366 + m,0), getsFree(366 + m,0);
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        v[x]++;
    }
    int res = 0;
    for(int i=1; i<=365 + m; i++){
        k += getsFree[i];
        if(k>0 && v[i]>0){
            int p;
            if(k>v[i]) {
                p = v[i];
                k -= p;
            }
            else {
                p = k;
                k = 0;
            }
            res += p;
            getsFree[i+m] += p;
        }
    }
    cout<<res;
    return 0;
}
/*
2
7
8
1
10
2
11
1
3
4
18
*/