#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n;
    string s;
    cin>>n;
    set<string> p;
    for(int i=1; i<=n; i++){
        string s;
        cin>>s;
        p.insert(s);
    }
    cout<<p.size()<<endl;
    for(auto it : p) cout<<it<<" ";
    return 0;
}
