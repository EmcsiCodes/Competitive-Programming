#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n,p;
    cin>>n>>p;
    vector< pair<int,int> > v;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(make_pair(x,i));
    }
    sort(v.begin(),v.end());
    pair<int,int> sol;
    sol.first=0;
    sol.second=0;
    for(int i=0; i<v.size(); i++){
        auto k=lower_bound(v.begin(),v.end(),p);//-v[i].first
        cout<<i<<endl;

       // if(k!=v.end()) {
            //int q=k->first;
        //if(q+v[i].first==p){
                    //  sol.first=v[i].second+1;
           // sol.second=k->second+1;
       //     break;
       // }

      //  }
    }
    if(sol.first==0) cout<<-1;
    else cout<<sol.first<<" "<<sol.second;
    return 0;
}
