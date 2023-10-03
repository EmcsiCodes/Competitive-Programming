#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define INF 10000000;

//Almost the same problem like the "Postas"
//The program makes the same approach

int main()
{
    int n;
    cin>>n;
    vector<int> v[1001];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int x;
            cin>>x;
            v[i].push_back(x);
        }
    }
    multiset< pair<int,int> > s;
    for(int i=1; i<=n; i++){
        s.insert({v[i][0],i});
    }
    pair<int,int> res = {0,0};
    int best = INF;
    int length = n;
    for(int t=1; t<=length; t++){
        int lo = s.begin()->first;
        int hi = s.rbegin()->first;
        if(hi - lo < best){
            best = hi - lo;
            res = {lo, hi};
        }
        int i = s.begin()->second;
        auto it = upper_bound(v[i].begin(),v[i].end(),lo);
        if(it==v[i].end()) break;
        s.erase(s.begin());
        s.insert({*it,i});
    }
    if(n == 1){
        res.first = s.begin()->first;
        res.second = s.rbegin()->first;
    }
    cout<<res.first<<" "<<res.second;
    return 0;
}