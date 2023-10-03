#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    unordered_map<string, vector<int> > m;
    for(int i=1; i<=n; i++){
        string s;
        cin>>s;
        while(s.length()!=0){
            m[s].push_back(i);
            s = s.substr(0,s.length()-1);
        }
    }
    int k;
    cin>>k;
    for(int i=1; i<=k; i++){
        string s;
        cin>>s;
        int last = m[s].size() == 0 ? n : m[s][0];
        //string f = s.substr(0,1);
        //auto p = upper_bound(m[f].begin(),m[f].end(),last) - m[f].begin();
        int res = last;
        //cout<<s<<":"<<res<<endl;
        while(s.length()!=0){
            if(m[s].size() !=0){
                auto it = upper_bound(m[s].begin(),m[s].end(),last);            
                it--;
                int pos = it - m[s].begin();
                res += pos + 1;
                //cout<<s<<" "<<res<<" pos="<<pos + 1<<endl;
            }
            s = s.substr(0,s.length()-1);
        }
        cout<<res<<'\n';
    }
    return 0;
}
/*
5
robot
hobo
hobbit
robi
botor
3
semmi
robi
bori 
*/