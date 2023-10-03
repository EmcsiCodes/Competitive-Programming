#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector< pair<int,int> > gas;
priority_queue<int> pq;
int main()
{
    double n,fuel,fuelCons;
    int k;
    cin>>n>>k>>fuel>>fuelCons;
    for(int i=1; i<=k; i++){
        int x,y;
        cin>>x>>y;
        gas.push_back({x,y});
    }
    sort(gas.begin(),gas.end());
    //cout<<double(fuel/fuelCons)<<endl;
    double d = 100*(fuel/fuelCons);
    int pos = 0, res = 0;
    while(d<n){
        res++;
        while(pos<gas.size() && gas[pos].first<=d){
            pq.push(gas[pos].second);
            pos++;
        }
        fuel = pq.top();
        pq.pop();
        d += 100*(fuel/fuelCons);
    }
    cout<<res;
    return 0;
}
/*
2000 5 40 7
400 20
500 40
500 80
800 30
1200 30
*/