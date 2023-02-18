#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector< pair<int,int> > v[1001];
    for(int i=1; i<=m; i++){
        int x,y,s;
        cin>>x>>y>>s;
        v[x].push_back({y,s});
        v[y].push_back({x,s});
    }
    int longestPath = 0;
    for(int i=1; i<=n; i++){
        int sum = 0;
        if(v[i].size()==1){
            sum = v[i][0].second;
            int j = v[i][0].first;
            int p = i;
            while(v[j].size()==2){
                if(v[j][0].first == p){
                    sum += v[j][1].second;
                    j = v[j][1].first;
                } else {
                    sum += v[j][0].second;
                    j = v[j][0].first;
                }
                p = j;
            }
        }
        //cout<<i<<": "<<v[i].size()<<" "<<sum<<endl;
        longestPath = max(longestPath,sum);
    }
    cout<<longestPath<<endl;
    int mostPaths = 0;
    for(int i=1; i<=n; i++){
        int p = v[i].size();
        mostPaths = max(mostPaths,p);
    }
    for(int i=1; i<=n; i++){
        if(v[i].size() == mostPaths){
            cout<<i<<" ";
        }
    }
    cout<<'\b'<<'\n';
    int maxmin = 0;
    int maxminIndex = 0;
    for(int i=1; i<=n; i++){
        int currMin = 1000000;
        for(auto j:v[i]){
            currMin = min(currMin, j.second);
        }
        if(currMin > maxmin){
            maxmin = currMin;
            maxminIndex = i;
        }
    }
    cout<<maxminIndex<<endl;
    return 0;
}
/*
7 8
1 2 10
2 3 15
2 4 10
2 5 5
3 5 5
4 5 15
5 6 5
6 7 10
*/