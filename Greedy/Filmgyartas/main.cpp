#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct in{
    int start,end;
};

struct Compare{
    bool operator()(in const& p1, in const& p2){
        return p1.start < p2.start;
    }
};

int main()
{
    int d,k,n,A,B;
    cin>>d>>k>>n>>A>>B;
    vector<in> v;
    vector<int> events;
    for(int i=1; i<=k; i++){
        int x;
        cin>>x;
        events.push_back(x);
    }
    for(int i=1; i<=n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end(),Compare());
    pair<int,int> res = {0,0};
    int i = 0;
    int j = 0;
    while(i<v.size() && j<events.size()){
        int currDis = 0;
        while(i<v.size() && v[i].start <= events[j]) {
            currDis = max(currDis,v[i].end);
            i++;
        }
        if(currDis!=0){
            res.second++;
            while(j<events.size() && events[j]<=currDis){
                res.first++;
                j++;
            }
        }
    }
    cout<<res.first<<'\n'<<res.second*A + res.first*B;
    return 0;
}
/*
{
(2 10), 
(4 8), 
(3 3), 
(2 4), 
(2 7)
}
*/