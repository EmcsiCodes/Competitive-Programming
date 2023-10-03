#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int n,s;
    cin>>n>>s;
    vector<int> v;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    multiset<int> trucks;
    trucks.insert(2*s);
    for(int i=1; i<v.size(); i++){
        auto curr = trucks.begin();
        if(*curr + s > v[i]){
            trucks.insert(2*s);
        } else {
            trucks.erase(curr);
            trucks.insert(*curr + 2*s);
        }
    }
    cout<<trucks.size()<<'\n';
    cout<<*trucks.rbegin();
    return 0;
}