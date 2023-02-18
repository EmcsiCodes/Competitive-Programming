#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
    int t,n,k;
    cin>>t>>n>>k;
    int u=n;
    vector< vector<int> > vec;
    for(int i=0;i<t; i++){
        int x;
        cin>>x;
        vector <int> v;
        u=min(u,x);
        for(int j=0;j<x; j++){
            int y;
            cin>>y;
            v.push_back(y);
        }
        vec.push_back(v);
    }
    set<int> s,s1;
    for(int i=0; i<u; i++){
        for(int j=0; j<vec.size(); j++){
                s1.insert(vec[j][i]);
            }
        if(s1.size()+s.size()<=k){
            for(auto it=s1.begin(); it!=s1.end(); it++) s.insert(*it);
            s1.clear();
        } else break;
    }
    cout<<s.size()<<endl;
    for(auto it=s.begin(); it!=s.end(); it++) cout<<*it<<" ";
    return 0;
}
