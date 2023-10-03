#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct in{
    int start;
    int end;
};

struct Compare{
    bool operator()(in const& p1,in const& p2){
        return p1.start < p2.start;
    }
};

int main()
{
    int n,t,d;
    cin>>n>>t>>d;
    vector<in> v;
    for(int i=1; i<=n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    t--;
    sort(v.begin(),v.end(),Compare());
    int i = 0, index = 1;
    vector<int> res[10000];
    while(i<v.size()){
        int last = v[i].end;
        while(i<v.size() && v[i].start<last){
            last = min(last, v[i].end);
            i++;
        }
        last--;
        res[index].push_back(last);
        int photosMade = 1;
        int nextlast = v[i].end;
        while(i<v.size() && photosMade < d && v[i].start <= last + t){
            if(v[i].start < nextlast){
                nextlast = min(nextlast, v[i].end);
                i++;
            } else {
                photosMade++;
                res[index].push_back(nextlast-1);
                nextlast = v[i].end;
            }
        }
        if(i<v.size() && photosMade!=d) res[index].push_back(last + t - 1);
        index++;
    }
    index--;
    cout<<index<<'\n';
    for(int i=1; i<=index; i++){
        for(auto j:res[i]) cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}
/*
8 3 2
1 3
4 6
1 4
4 8
3 6
8 12
2 4
5 9
*/