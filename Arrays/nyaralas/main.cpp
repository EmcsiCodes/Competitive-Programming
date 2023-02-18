#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> temp;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        temp.push_back(x);
    }
    int r=k;
    map<int,int> m;
    for(int i=0; i<k; i++){
        m[temp[i]]+=1;
    }
    pair<int,int> best={1,m.begin()->first};
    while(r<n){
        if(m[temp[r-k]]==1) m.erase(temp[r-k]);
        else m[temp[r-k]]--;
        m[temp[r]]+=1;
        if(m.begin()->first > best.second){
            best.first = r - k + 2;
            best.second = m.begin()->first;
        }
        r++;
    }
    cout<<best.first<<" "<<best.second;
    return 0;
}