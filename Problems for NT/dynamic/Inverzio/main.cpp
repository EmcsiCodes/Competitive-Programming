#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    int n;
    cin>>n;
    unordered_map<int,int> m;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        m[x] = i;
    }
    pair<int,int> res = {0,0};
    int minIndex = 1000000;
    for(int i=n; i>=1; i--){
        if(minIndex > m[i]){
            minIndex = m[i];
        } else if(m[i] - minIndex > res.second){
            res = {minIndex, m[i] - minIndex};
        }
    }
    if(res.second == 0) cout<<-1;
    else cout<<res.first<<" "<<res.first + res.second;
    return 0;
}
/*
6
4 1 2 3 6 5
*/
/*
5
4 3 5 1 2
*/