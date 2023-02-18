#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    unordered_map<string,int> given;
    unordered_map<int,string> chosen;
    for(int i=1; i<=n; i++){
        string s;
        cin>>s;
        given[s]=0;
    }
    for(int i=1; i<=m; i++){
        string s;
        cin>>s;
        chosen[i]=s;
    }
    vector<int> A;
    vector<string> B;
    for(auto i:chosen){
        if(given.find(i.second)==given.end()){
            A.push_back(i.first);
        } else given[i.second]++;
    }
    cout<<A.size()<<" ";
    for(auto i:A){
        cout<<i<<",";
    }
    cout<<'\b';
    for(auto i:given){
        if(i.second==0) B.push_back(i.first);
    }
    cout<<B.size()<<" ";
    for(auto i:B){
        cout<<i<<",";
    }
    cout<<'\b';
    for(auto i:given){
        if(i.second!=0) cout<<i.first<<":"<<i.second<<",";
    }
    cout<<'\b';
    return 0;
}
/*4 5
VISUAL BASIC
PASCAL
LOGO
C++
PASCAL
PASCAL
DELPHI
C++
PASCAL
*/