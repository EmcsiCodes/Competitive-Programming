#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int f;
    cin>>f;
    vector< vector <int> > v;
    for(int i=0; i<f; i++){
        int x;
        vector<int> v1;
        cin>>x;
        for(int j=0; j<x; j++){
            int y;
            cin>>y;
            v1.push_back(y);
        }
        v.push_back(v1);
    }
    map<int,int> m;
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[i].size(); j++){
            m[v[i][j]]++;
        }
    }
    int c=0;
    for(auto it:m){
        if(it.second==1) c++;
    }
    if(c==0) cout<<0;
    else{
    cout<<c<<endl;
    for(auto it:m){
        if(it.second==1) cout<<it.first<<" ";
    }
    }

    return 0;
}
