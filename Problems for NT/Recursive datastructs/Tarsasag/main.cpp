#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//the program is wrong but its too painfull to delete it after spending more than a day for it


#define LL long long
vector< pair<int,LL> > adj[10001];
int n,k;
bool valid(LL mid){
    queue<int> q;
    q.push(1);
    vector<LL> dis(n+1,0);
    int currSec = 0;
    //cout<<mid<<endl;
    while(!q.empty()){
        int node = q.front();
        q.pop();
       // cout<<node<<":";
        for(auto i:adj[node]){
            dis[i.first] = dis[node] + i.second;
            //cout<<i.first<<"("<<dis[i.first]<<")->";
            if(dis[i.first]>mid){
                currSec++;
                dis[i.first] = 0;
                
            }//cout<<currSec<<", ";
            q.push(i.first);
        }
        //cout<<endl;
    }
    if(currSec<=k) return true;
    return false;
}

int main()
{
    cin>>n>>k;
    for(int i=2; i<=n; i++){
        int x;
        LL y;
        cin>>x>>y;
        adj[x].push_back({i,y});
    }
    queue<int> q;
    q.push(1);
    LL sum = 0;
    vector<LL> dis(n+1,0);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            dis[i.first] = dis[node] + i.second;
            sum = max(sum,dis[i.first]);
            q.push(i.first);
        }
    }
    LL l = 0;
    LL r = sum;
    LL best = sum;
    while(l<=r){
        LL mid = (l + r) / 2;
        if(valid(mid)){
            r = mid - 1;
            best = min(best,mid);
        } else l = mid + 1;
    }
    cout<<best;
    return 0;
}
/*
5 2
1 5
1 2
2 4
2 2
*/