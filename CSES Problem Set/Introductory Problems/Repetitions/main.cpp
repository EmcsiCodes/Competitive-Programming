#include <iostream>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int l = 1;
    int res = 1;
    for(int i=1; i<s.length(); i++){
        if(s[i-1] == s[i]) l++;
        else l = 1;
        res = max(res,l);
    }
    cout<<res;
    return 0;
}