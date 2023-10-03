#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int n,start,t;
    cin>>n>>start>>t;
    vector<int> v;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    set<int> res;
    res.insert(start-1);
    int last = v[start-1];
    for(int i=start; i<v.size(); i++){
        if(last + t <= v[i]) {
            last = v[i];
            res.insert(i);
        }
    }
    last = v[start-1];
    for(int i = start - 2; i>=0; i--){
        if(last - t >= v[i]){
            last = v[i];
            res.insert(i);
        }
    }
    cout<<res.size()<<endl;
    for(auto i:res) cout<<i+1<<" ";
    return 0;
}