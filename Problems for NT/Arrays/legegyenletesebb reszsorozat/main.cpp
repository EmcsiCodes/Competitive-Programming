#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> v;
    map<int,int> m;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    for(int i=0; i<k; i++){
        m[v[i]]+=1;
    }
    int r=k;
    pair<int,int> best = {1, m.rbegin()->first - m.begin()->first};
    while(r<v.size()){
        if(m[v[r-k]]==1) m.erase(v[r-k]);
        else m[v[r-k]]--;
        m[v[r]]+=1;
        int p = m.rbegin()->first - m.begin()->first;
        if(p < best.second){
            best.first = r - k + 2;
            best.second = p;
        }
        r++;
    }
    cout<<best.first<<" "<<best.second;
    return 0;
}