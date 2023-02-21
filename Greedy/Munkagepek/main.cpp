#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
    int n;
    vector<int> v;
    cin>>n;
    v.push_back(0);
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    multiset<int> robots;
    robots.insert(0);
    for(int i=1; i<=n; i++){
        auto it = robots.begin();
        if(*it >= v[i]){
            robots.insert(1);
        } else {
            auto toErase = robots.lower_bound(*it);
            robots.erase(toErase);
            robots.insert(*it+1);
        }
    }
    cout<<robots.size();
    return 0;
}