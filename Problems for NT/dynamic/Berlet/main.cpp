#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

void solve(vector < pair<int,int> > v){
    set < pair<int,int> > sol;
    for(int i=0; i<v.size(); i++){
        pair<int,int> p = make_pair(v[i].second,INT_MAX);
        auto it = sol.lower_bound(p);
        cout<<endl;
        if(it==sol.begin() && it->first>=v[i].first) {
            sol.insert(make_pair(v[i].first, v[i].first - v[i].second + 1));
        } else {
            sol.insert(make_pair(v[i].first, it->second + v[i].first - v[i].second + 1));
        }
        for(auto t : sol){
        cout<<t.first<<","<<t.second<<" ";
    }
    cout<<endl<<p.first<<","<<p.second<<" lowerbound:"<<it->first<<","<<it->second<<endl;
    }

    int solution=0;
    for(auto it : sol){
        cout<<it.first<<","<<it.second<<" ";
    }
    //cout<<solution<<endl;

}

int main()
{
    int n,m;
    cin>>n>>m;
    vector< pair<int,int> > v;
    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back(make_pair(y,x));
    }
    sort(v.begin(),v.end());
    solve(v);
    return 0;
}
/*
5 25
2 7
3 10
13 15
8 11
20 25
*/
