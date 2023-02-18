#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    vector< pair<int,char> > v;
    cin>>n;
    for(int i=0; i<n; i++) {
        int x,y;
        cin>>x>>y;
        v.push_back({x,'x'});
        v.push_back({y,'y'});
    }
    sort(v.begin(),v.end());
    pair<int,int> res={0,100001};
    int count = 0, l=0, r=0;
    int minMeet;
    if(n%2==0) minMeet = n/2;
    else minMeet = n/2 + 1;
    while(r<v.size()){
        while(count!=minMeet && r<v.size()){
            if(v[r].second == 'x') count++;
            r++;
        }
        //cout<<count<<", v["<<l<<"]:"<<v[l].first<<", v["<<r<<"]:"<<v[r-1].first<<endl;
        while(l<v.size() && v[l].second == 'x') {
            l++;
        }
        //cout<<count<<", v["<<l<<"]:"<<v[l].first<<", v["<<r<<"]:"<<v[r-1].first<<endl;
        if(count==minMeet && r<v.size() && v[r-1].first - v[l].first < res.second - res.first){
            res.first = v[l].first;
            res.second = v[r-1].first;
            //cout<<res.first<<" "<<res.second<<endl;
        }
        count--;
        l++;
        while(l<=r && v[l].second!='y'){
            l++;
        }
        //cout<<count<<", v["<<l<<"]:"<<v[l].first<<", v["<<r<<"]:"<<v[r-1].first<<endl;
    }
    cout<<res.second - res.first + 1<<endl;
    cout<<res.first<<" "<<res.second;
    return 0;
}