#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

#define INF 10000000
struct in{
    int road;
    int hour;
    int min;
};

int main()
{
    int n,m;
    cin>>n>>m;
    unordered_map<int,vector<in>> v;
    for(int i=1; i<=m; i++){
        int x,y,z,q;
        cin>>x>>y>>z>>q;
        v[x].push_back({y,z,q});
    }
    pair<int,int> dp[101][101];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++) dp[i][j] = {INF,0};
    }
    for(auto i = v.begin(); i!=v.end(); i++){
        for(int j = 1; j<i->second.size(); j++){
            int time = i->second[j].min + 60 * i->second[j].hour;
            int prevtime = i->second[j-1].min + 60 * i->second[j-1].hour;
            int currtime = time - prevtime;
            if(dp[i->second[j-1].road][i->second[j].road].first > currtime){
                dp[i->second[j-1].road][i->second[j].road].first = currtime;
                dp[i->second[j-1].road][i->second[j].road].second = i->first;
            }
        }
    };
    for(int i=1; i<n; i++){
        cout<<dp[i][i+1].second<<" ";
    }
    cout<<endl;
    for(int i=2; i<=n; i++){
        cout<<dp[i][i-1].second<<" ";
    }
    return 0;
}