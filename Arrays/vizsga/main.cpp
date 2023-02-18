#include <iostream>
using namespace std;
int main()
{

    int n,p;
    cin>>n>>p;
    string s1,s2;
    cin>>s1>>s2;
    int same=0,diff=0;
    for(int i=0; i<s1.size(); i++){
        if(s1[i]==s2[i]) same++;
        else diff++;
    }
    pair<int,int> sol;
    if(p <= diff) sol.first = 0;
    else sol.first = p - diff;
    if(same >= p) sol.second = p + diff;
    else sol.second = n + same - p;
    cout<<sol.first<<" "<<sol.second;
    return 0;
}
