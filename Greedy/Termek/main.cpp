#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct in{
    int node;
    char c;
    int i;
};

struct Compare{
    bool operator()(in const& p1, in const& p2){
        if(p1.node == p2.node) return p1.c < p2.c;
        return p1.node < p2.node;
    }
};

vector<int> roomNum(100001,0);
vector<int> res[100001];

int main()
{
    int n;
    cin>>n;
    vector<in> v;
    for(int i=1; i<=n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,'x',i});
        v.push_back({y,'y',i});
    }
    sort(v.begin(),v.end(), Compare());
    queue<int> next;
    int maxRooms = 0;

    for(int i=0; i<v.size(); i++){
        if(v[i].c == 'x') {
            if(next.empty()){
                maxRooms++;
                next.push(maxRooms);
            }
            res[next.front()].push_back(v[i].i);
            roomNum[v[i].i] = next.front();
            next.pop();
        } else {
            next.push(roomNum[v[i].i]);
        }
    }
    cout<<maxRooms<<'\n';
    for(int i=1; i<=maxRooms; i++){
        for(auto j:res[i]) cout<<j<<" ";
        cout<<'\n';
    }
    return 0;
}
/*
8
1100 1200
500 520
510 570
600 630
630 700
700 800
600 800
650 700
*/