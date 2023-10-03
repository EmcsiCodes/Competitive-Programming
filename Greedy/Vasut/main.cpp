#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    vector<int> res;
    res.push_back(0);
    int endPoint = v[n-1];
    for(int i=1; i<v.size(); i++){
        if(v[res.back()]+k<=v[i] && v[i]+k<=endPoint) res.push_back(i);
    }
    res.push_back(n-1);
    cout<<res.size()<<'\n';
    for(auto i:res) cout<<i+1<<" ";
    return 0;

}
/*
5 10
0 5 13 24 28
*/