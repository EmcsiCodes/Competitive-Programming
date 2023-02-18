#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;

int main()
{
    int n,m;
    unordered_map<string,int> fruits;
    cin>>n;
    for(int i=1; i<=n; i++){
        string s;
        cin>>s;
        fruits[s]=1;
    }
    cin>>m;
    for(int i=1; i<=m; i++){
        string s;
        cin>>s;
        if(fruits[s]!=1) fruits[s]=1;
        else fruits[s]=0;
    }
    set<string> fruits_sol;
    for(auto i:fruits){
        if(i.second==1) fruits_sol.insert(i.first);
    }
    cout<<fruits_sol.size()<<endl;
    for(auto i:fruits_sol){
        cout<<i<<" ";
    }
    return 0;
}