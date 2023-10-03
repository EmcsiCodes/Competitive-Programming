#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct in{
    int n;
    char c;
};

struct Compare{
    bool operator()(in const& p1,in const& p2){
        if(p1.n == p2.n) return p1.c<p2.c;
        return p1.n<p2.n;
    }
};

int main()
{
    int m,n;
    cin>>m>>n;
    vector<in> v;
    for(int i=1; i<=n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({y,'x'});
        v.push_back({x,'y'});
    }
    sort(v.begin(),v.end(),Compare());
    int count = 0;
    int maxTime = 0, index = 0;
    for(int i=0; i<v.size(); i++){
        if(v[i].c == 'x') count++;
        else {
            if(count == maxTime) index = max(index,v[i].n);
            count--;
        }
        maxTime = max(maxTime,count);
    }
    cout<<maxTime<<'\n'<<index;
    return 0;
}