#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n,m;
    vector< pair<int,char> > v;
    cin>>n;
    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back(make_pair(x,'x'));
        v.push_back(make_pair(y,'y'));
    }
    cin>>m;
    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        v.push_back(make_pair(x,'x'));
        v.push_back(make_pair(y,'y'));
    }
    sort(v.begin(),v.end());
    int c=0;
    vector < pair<int,int> > sol;
    sol.push_back(make_pair(v[0].first,0));
    for(int i=0; i<v.size(); i++){
        if(v[i].second == 'x') c++;
        else c--;
        if(i<v.size()-1 && 1 + v[i].first==v[i+1].first) continue;
        if(c==0) {
            int last = sol.size() - 1;
            sol[last].second = v[i].first;
            if(i<v.size()-1) sol.push_back(make_pair(v[i+1].first,0));
        }
    }
    cout<<sol.size()<<endl;
    for(auto i:sol){
        cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
}