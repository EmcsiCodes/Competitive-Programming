#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

struct in{
    int start;
    int end;
    int i;
};

struct Compare{
    bool operator()(in const& p1,in const& p2){
        return p1.start < p2.start;
    }
};

int main()
{
    int n,k;
    cin>>n>>k;
    vector<in> v;
    for(int i=1; i<=n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y,i});
    }
    sort(v.begin(),v.end(),Compare());
    multiset< pair<int,int> > tables;
    vector<int> cap(20000,0);
    int index = 1;
    vector<int> res[20000];
    res[1].push_back(v[0].i);
    cap[1]++;
    tables.insert({v[0].end,1});//cout<<"sziaaa";
    for(int i=0; i<v.size(); i++){
        cout<<v[i].i<<": "<<v[i].start<<" "<<v[i].end<<endl;
    }
    for(int i=1; i<v.size(); i++){
        auto it = tables.lower_bound({v[i].start,1000000});
        if(it==tables.begin()){
            if(cap[it->second]<k){
                res[it->second].push_back(v[i].i);
                tables.insert({v[i].end,it->second});
                cap[it->second]++;
            }
            else {
                index++;
                res[index].push_back(v[i].i);
                tables.insert({v[i].end,index});
                cap[index]++;
                  
            } 
            continue; 
        }
        tables.insert({v[i].end,tables.begin()->second});
        res[tables.begin()->second].push_back(v[i].i);
        cap[tables.begin()->second]++;
        for(auto j=tables.begin(); j!=it; j++) {
            cap[j->second]--;
        }
        tables.erase(tables.begin(),it);
    }
    cout<<index<<endl;
    for(int i=1; i<=index; i++){
        for(auto j:res[i]) cout<<j<<" ";
        cout<<'\n';
    }
    return 0;
}
/*
7 3
7 8
1 3
2 6
4 6
2 5
1 4
7 9
*/