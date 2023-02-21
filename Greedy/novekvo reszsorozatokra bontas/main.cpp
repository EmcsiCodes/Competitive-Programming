#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> v(n+1);
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        v[i] = x;
    }
    multiset<int> s;
    for(int i=0; i<v.size(); i++){
        auto it = s.lower_bound(v[i]);
        if(it == s.begin()){
            s.insert(v[i]);
        } else {
            it--;
            s.erase(it);
            s.insert(v[i]);
        }
    }
    cout<<s.size();
    return 0;
}