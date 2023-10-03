#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> days;
    vector<int> v;
    days.push_back(0);
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        days.push_back(x);
    }
    for(int i=1; i<=m; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    int res = 0;
    int i = 0;
    for(int curr = 1; curr<=n; curr++){
        if(i<v.size() && curr<=v[i]){
            res += days[curr];
            i += days[curr];
            if(i>=v.size()) res -= i - v.size();
        } else {
            i = lower_bound(v.begin(),v.end(),curr) - v.begin();
            if(i<v.size()) {
                res += days[curr];
                i += days[curr];
                if(i>=v.size()) res -= i - v.size();
            }
        }
    }
    cout<<res;
    return 0;
}
/*
3 5
2 0 6
2
3
1
2
3
*/