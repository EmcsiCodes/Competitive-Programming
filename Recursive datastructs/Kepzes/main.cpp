#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> v, s(n+1,0);
    v.push_back(0);
    set<int> res;
    vector<bool> colored(n+1,false);//, touching(n+1,false);
    colored[1] = true;
    res.insert(1);
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        v.push_back(x);
        s[x]++;
    }
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(s[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int i = q.front();
        q.pop();
        s[v[i]]--;
        if(s[i] == 0 && !colored[v[i]] && !colored[i]) {
            colored[v[i]] = true;
            res.insert(v[i]);
        }
        if(s[v[i]] == 0) q.push(v[i]);
    }
    cout<<res.size()<<'\n';
    for(auto i:res) cout<<i<<" ";
    return 0;
}
/*
12
0 1 1 1 2 12 12 12 3 9 10 3 
*/