#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector< pair<int,int> > res;
    int sum = 0;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        res.push_back({x,0});
        sum += x;
    }
    sort(res.begin(),res.end(), greater<>());
    int totalSum = 0;
    for(int i=0; i<n; i++){
        res[i].second = sum;
        totalSum += sum;
        sum -= res[i].first;
    }
    totalSum -= res[n-1].first;
    cout<<totalSum<<'\n';
    for(int i=0; i<n-1; i++){
        cout<<res[i].second<<" "<<res[i].first<<'\n';
    }
    return 0;
}
/*
5
2 5 2 7 10
*/
