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
    int c=0;
    vector< pair<int,int> > sol;
    sort(v.begin(),v.end());
    for(int i=0; i<v.size(); i++){
        if(v[i].second == 'x') c++;
        else c--;
        if(c==2){
            sol.push_back(make_pair(v[i].first,v[i+1].first));
        }
    }
    cout<<sol.size()<<endl;
    for(int i=0; i<sol.size(); i++) cout<<sol[i].first<<" "<<sol[i].second<<endl;
    return 0;
}