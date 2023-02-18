#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int n;
    vector< vector < pair<int,int> > > v;
    cin>>n;
    for(int i=0; i<n; i++){
        int x,y;
        vector< pair<int,int> > be;
        cin>>x>>y;
        for(int j=1; j<x; j++){
            int z;
            cin>>z;
            be.push_back(make_pair(y,z));
            y=z;
        }
        be.push_back(make_pair(y,0));
        v.push_back(be);
    }
    /*
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[i].size(); j++){
            cout<<v[i][j].first<<"("<<v[i][j].second<<") ";
        }
        cout<<endl;
    }*/
  ///  linked list!
    return 0;
}
