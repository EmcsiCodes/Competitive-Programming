#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,h;
    cin>>n>>h;
    vector<int> dis(n+1,1);
    vector<int> s(n+1,0);
    int totalMoney = 10;
    int noSub = 1;
    int mostSub = 0;
    int mostSubI = 0;
    int maxDis = 0;
    int currDay = 1;
    s[1] = 0;
    for(int i=2; i<=n; i++){
        int x,y;
        cin>>x>>y;
        if(currDay == x){
            dis[i] = dis[y] + 1;
            totalMoney += dis[y] + 10;
            if(s[y]!=0) noSub++;
            s[y]++;
            if(s[y] > mostSub){
                mostSub = s[y];
                mostSubI = y;
            }
            maxDis = max(maxDis, dis[i]);
        } else {
            cout<<totalMoney<<" "<<noSub<<" "<<mostSubI<<" "<<maxDis<<'\n';
            dis[i] = dis[y] + 1;
            totalMoney += dis[y] + 10;
            if(s[y]!=0) noSub++;
            s[y]++;
            if(s[y] > mostSub){
                mostSub = s[y];
                mostSubI = y;
            }
            maxDis = max(maxDis, dis[i]);
            currDay = x;
        }
    }
    cout<<totalMoney<<" "<<noSub<<" "<<mostSubI<<" "<<maxDis<<'\n';
    return 0;
}
/*
4 2
1 1
1 2
2 2
*/