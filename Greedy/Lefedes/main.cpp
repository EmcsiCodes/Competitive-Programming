#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool valid(int mid,vector<int>v,int m){
    int sum = 0;
    int sec = 0;
    for(int i=0; i<v.size(); i++){
        sum += v[i];
        if(sum>mid){
            sum = v[i];
            sec++;
        }
    }
    if(sec<=m) return true;
    return false;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> v;
    int sum = 0;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        v.push_back(x);
        sum += x;
    }
    sort(v.begin(),v.end());
    int l = 0;
    int r = sum;
    int best = 0;
    while(l<=r){
        int mid = (l + r)/2;
        if(valid(mid,v,m)){
            r = mid - 1;
            best = mid;
        } else {
            l = mid + 1;
        }
    }
    cout<<best;
    return 0;
}
/*
7 3
3 1 4 11 7 9 15 
*/