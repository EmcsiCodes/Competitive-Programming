#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

#define INF 1000000
struct in{
    int h;
    int end;
};

struct Compare{
    bool operator()(in const& p1, in const& p2){
        return p1.h<p2.h;
    }
};

vector<in> v;

int main()
{
    int h,n,k;
    cin>>h>>n>>k;
    priority_queue<in, vector<in>, Compare> pq, t;
    int m = 0;
    for(int i=1; i<=n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({y,x});
    }
    int j = 0;
    int res = INF;
    for(int i=1; i<=h; i++){
        while(j<n && v[j].end == i - 1) {
            pq.push({v[j].h, i - 1 + k});
            j++;
        }
        while(!pq.empty() && pq.top().end<i) {
            pq.pop();
        }
        if(!pq.empty()) res = min(res,pq.top().h);
    }
    cout<<res;
    return 0;
}
/*
11 4 5
0 5
2 3
3 2
6 4
*/
/*
13 4 4
1 5
2 4
3 3
7 4
*/