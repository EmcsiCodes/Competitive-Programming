#include <iostream>
#include <vector>
using namespace std;

bool searchTree(vector<int> v){
    if(v.size()<3) return true;
    int hi=1000001,lo=0,mid=v[1];
    if(mid>v[0]) {
        lo = v[0];
    } else {
        hi = v[0];
    }
    for(int i=2; i<v.size(); i++){
        if(v[i]>mid && v[i]<hi) {
            lo = mid;
            mid = v[i];
            continue;
        }
        if(v[i]<mid && v[i]>lo) {
            hi = mid;
            mid = v[i];
            continue;
        }
        return false;
    }
    return true;
}

int main()
{
    int k;
    cin>>k;
    vector<bool> sol;
    for(int i=1; i<=k; i++){
        int n;
        cin>>n;
        vector<int> v;
        for(int j=0; j<n; j++){
            int x;
            cin>>x;
            v.push_back(x);
        }
        if(searchTree(v)) sol.push_back(true);
        else sol.push_back(false);
    }
    for(auto i:sol){
        if(i) cout<<"IGEN"<<endl;
        else cout<<"NEM"<<endl;
    }
    return 0;
}