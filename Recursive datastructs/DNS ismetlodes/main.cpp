#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    string curr = s.substr(0,k);
    map<string, pair<int,int> > m;
    m[curr].first++;
    m[curr].second = 1;
    int l = 0;
    int r = k;
    while(r<s.size()){
        curr = curr + s[r];
        curr.erase(0,1);
        m[curr].first++;
        if(m[curr].first == 1) m[curr].second = l+2;
        l++;
        r++;
    }
    int maxNum = 0;
    int maxNumI = 0;
    for(auto i:m){
        if(i.second.first > maxNum){
            maxNum = i.second.first;
            maxNumI = i.second.second;
        }
    }
    cout<<maxNum<<" "<<maxNumI;
    return 0;
}
/*
11 3
TACACAGTACA
*/