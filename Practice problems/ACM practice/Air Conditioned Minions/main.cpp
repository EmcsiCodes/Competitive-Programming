#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> v;
    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    sort(v.begin(), v.end());
    int last = v[0].second;
    int res = 1;
    for(int i=1; i<v.size(); i++){
        int currL = v[i].first;
        int currR = v[i].second;
        if(currL > last){
            res++;
            last = currR;
        } else {
            last = min(last, currR);
        }
    }
    cout<<res;
}