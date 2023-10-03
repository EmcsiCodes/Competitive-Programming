#include <iostream>
#include <vector>

using namespace std;

struct in{
    int time;
    int cap;
};

int main()
{
    int n,c,t;
    cin>>n>>c>>t;
    vector<in> v;
    for(int i=1; i<=n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    int i = 0, res = 0;
    while(i<v.size()){
        int currCap = 0;
        int maxTime = v[i].time + t;
        while(i<v.size() && v[i].time <= maxTime && currCap + v[i].cap <= c){
            currCap += v[i].cap;
            i++;
        }
        res++;
    }
    cout<<res;
    return 0;
}
/*
5 100 10
1 30
6 50
8 30
19 50
28 40
*/