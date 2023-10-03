#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

#define INF 10000000
struct in{
    int cap;
    int h;
};

struct Compare{
    bool operator()(in const& p1, in const& p2){
        return p1.h<p2.h;
    }
};

void fill(set< pair<int,int> > &s, int cap){
    while(cap!=0){    
        auto hi = s.begin();
        auto lo = hi;
        hi++;
        int h1 = lo->first;
        int h2 = INF;
        if(hi!=s.end()) h2 = hi->first;
        if(cap/lo->second + h1 >= h2){
            cap -= (h2 - h1) * (lo->second);        
            pair<int,int> newh = {h2,hi->second+lo->second};
            s.erase(lo);
            s.erase(hi);
            s.insert(newh);
        } else {
            pair<int,int> newhm = {1,cap%lo->second};
            pair<int,int> newh = {cap/lo->second + lo->first,lo->second};
            if(cap%lo->second != 0) {
                newh.second -= newhm.second;
                newhm.first += newh.first;
                s.erase(lo);
                s.insert(newh);
                s.insert(newhm);
            }
            else s.insert(newh);
            return;
        }
    }
}

int main()
{
    int h,n;
    cin>>h>>n;
    vector<in> v;
    for(int i=1; i<=n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end(),Compare());
    set< pair<int,int> > s;
    int lasth = 0;
    for(int i=0; i<v.size(); i++){
        if(v[i].h>lasth) s.insert({0,v[i].h - lasth});
        lasth = v[i].h;
        fill(s,v[i].cap);
    }
    cout<<s.begin()->first;
    return 0;
}
/*
10 6
3 5
3 5
14 7
6 8
3 10
10 10
*/