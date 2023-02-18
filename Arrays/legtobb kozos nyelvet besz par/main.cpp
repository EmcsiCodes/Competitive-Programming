#include <iostream>
#include <map>
#include <set>
using namespace std;

int main()
{
    int n;
    cin>>n;
    map<string, set<string> > m;
    map< pair<string,string>, int> sol;
    for(int i=1; i<=n; i++){
        string s1,s2;
        cin>>s1>>s2;
        m[s2].insert(s1);
    }
    for(auto i:m){
        cout<<i.first<<": ";
        for(auto j:i.second){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}// 1 2 3 4 5 6 7 n*(n-1)/2--1000*999/2=500*999=500000*200 1000000
//1,2 1,3 1,4 1,5 1,6 1,7 2,3 2,4 2,5 2,6 2,7 3,4 3,5 3,6 3,7 4,5 4,6 4,7 5,6 5,7 6,7