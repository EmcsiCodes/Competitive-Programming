#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector< pair<int,int > > v;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        v.push_back({x,1});
    }
    multiset< pair<int,int> > s;
    for(int i=v.size()-1; i>=0; i--){
        auto it = s.lower_bound({v[i].first,0});
        if(it == s.begin()){
            v[i].second = s.size();
            s.insert(v[i]);
        }
        else {
            it--;
            s.erase(it);
            v[i].second = it->second;
            s.insert(v[i]);
        }
    }
    cout<<s.size()<<'\n';
    vector<int> res[10001];
    for(int i=0; i<n; i++){
        res[v[i].second].push_back(i+1);
    }
    for(int i=0; i<s.size(); i++){
        for(auto j:res[i]) cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}
/*
10
4 1 5 10 7 9 2 8 3 2 
*/