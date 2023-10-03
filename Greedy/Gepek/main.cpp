#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector< pair<int,int> > v,res(m+1);
    multiset< pair<int,int > > robots;
    for(int i=1; i<=m; i++){
        int x;
        cin>>x;
        v.push_back({x,i});
    }
    sort(v.begin(),v.end());
    robots.insert({1,1});
    int totalRobots = 1;
    for(int i=0; i<v.size(); i++){
        auto currRobot = robots.begin();
        if(currRobot->first <= v[i].first) {
            res[v[i].second] = {currRobot->first,currRobot->second};
            robots.erase(currRobot);
            robots.insert({currRobot->first+1,currRobot->second});
            
        } else {
            totalRobots++;
            robots.insert({2,totalRobots});
            res[v[i].second] = {1,totalRobots};
        }
    }
    cout<<totalRobots<<'\n';
    for(int i=1; i<=m; i++) cout<<res[i].first<<" "<<res[i].second<<'\n';
    return 0;
}
/*
10 8
3 2 3 2 4 5 6 2
*/