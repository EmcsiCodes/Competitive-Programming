#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector < vector < pair < int,int > > > v;
    for(int i=0; i<n; i++){
        int m;
        cin>>m;
        vector < pair <int,int> > be;
        for(int j=0; j<m; j++){
            int a,b;
            cin>>a>>b;
            be.push_back(make_pair(a,b));
        }
        v.push_back(be);
    }
    vector < vector<int> > sol1,sol2;
    vector<int> be1,be2;
    for(int j=0; j<v[0].size(); j++){
        be1.push_back(v[0][j].first);
        be2.push_back(v[0][j].second);
    }
    sol1.push_back(be1);
    sol2.push_back(be2);
    for(int i=1; i<v.size(); i++){
        vector<int> be1,be2;
        for(int j=0; j<v[i].size(); j++){
           // if(v[i][j])
            int it = upper_bound(sol2[i-1].begin(),sol2[i-1].end(),v[i][j].first)-sol2[i-1].begin();
            if(it<sol2[i-1].size() && v[i][j].second>=sol1[i-1][it]){
                if(min(v[i][j].second,sol2[i-1][it])!=max(v[i][j].first,sol1[i-1][it]))
                {
                    be1.push_back(max(v[i][j].first,sol1[i-1][it]));
                    be2.push_back(min(v[i][j].second,sol2[i-1][it]));
                }

            }
        }
        sol1.push_back(be1);
        sol2.push_back(be2);
    }
    cout<<sol1[n-1].size()<<endl;
    for(int i=0; i<sol1[n-1].size(); i++){
        cout<<sol1[n-1][i]<<" "<<sol2[n-1][i]<<endl;
    }
//hatekonyabb otlet: ne nezzek minden elemet a
//sorozatbol upperboundal hanem egy elem upperboundjanak
// az upperboundja lesz a next elem
    return 0;
}
