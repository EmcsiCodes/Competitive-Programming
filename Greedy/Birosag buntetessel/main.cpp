#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct in{
    int end;
    int c;
    int i;
};

struct Compare{
    bool operator()(in const& p1,in const& p2){
        return p1.end < p2.end;
    }
};

int main()
{
    int n;
    cin>>n;
    vector<int> leaveForEnd;
    vector<in> v;
    for(int i=1; i<=n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y,i});
    }
    sort(v.begin(),v.end(),Compare());
    multiset< pair<int,int> > fines;
    int day = 1;
    int totalFine = 0;
    for(int i=0; i<v.size(); i++){
        fines.insert({v[i].c,v[i].i});
        if(v[i].end<day){
            day--;
            auto it = fines.begin();
            totalFine += it->first;
            leaveForEnd.push_back(it->second);
            fines.erase(it);
        }
        day++;
    }
    vector<int> res(n+1,0);
    cout<<totalFine<<'\n';
    int p = n;
    for(auto i:leaveForEnd) {
        res[i] = p;
        p--;
    }
    int num = 1;
    for(int i=0; i<v.size(); i++){
        if(res[v[i].i] == 0) {
            res[v[i].i] = num;
            num++;
        }
    }
    for(int i=1; i<=n; i++) cout<<res[i]<<" ";
    return 0;
}
/*
7
4 70
2 60
4 50
3 40
1 30
4 20
6 10
*/