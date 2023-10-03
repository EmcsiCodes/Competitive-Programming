#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct in{
    int end;
    int profit;
    int i;
};

struct Compare{
    bool operator()(in const& p1,in const& p2){
        return p1.end<p2.end;
    }
};

int main()
{
    int n;
    cin>>n;
    vector<in> v;
    for(int i=1; i<=n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y,i});
    }
    sort(v.begin(),v.end(),Compare());
    int day = 1;
    set< pair<int,int> > profits;
    vector<bool> jobs(n+1,true);
    for(int i=0; i<v.size(); i++){
        profits.insert({v[i].profit,v[i].i});
        if(day>v[i].end){
            day--;
            auto it = profits.begin();
            jobs[it->second] = false;
            profits.erase(it);
        }
        day++;
    }
    vector<int> res;
    int sum = 0;
    for(int i=0; i<v.size(); i++){
        if(jobs[v[i].i]) {
            res.push_back(v[i].i);
            sum += v[i].profit;
        }
    }
    cout<<sum<<'\n';
    for(auto i:res) cout<<i<<" ";
    return 0;
}
/*
6
3 60
4 40
1 10
3 30
7 70
4 20
*/