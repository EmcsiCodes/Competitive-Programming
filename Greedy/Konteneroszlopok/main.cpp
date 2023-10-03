#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> v;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    multiset< pair<int,int> > s;
    for(int i=v.size()-1; i>=0; i--){
        auto it = s.lower_bound({v[i],0});
        if(it->first == v[i]) {
            s.erase(it);
            s.insert({v[i],it->second});
            v[i] = it->second;
            continue;
        }
        if(it == s.begin()){
            s.insert({v[i],s.size()+1});
            v[i] = s.size();
        } else {
            it--;
            s.erase(it);
            s.insert({v[i],it->second});
            v[i] = it->second;
        }
    }
    cout<<s.size()<<'\n';
    for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
    return 0;
}
/*
10 9
6 3 4 3 8 1 2 7 3 5 
*/