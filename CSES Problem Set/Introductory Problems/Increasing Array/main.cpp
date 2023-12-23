#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    long long res = 0;
    for(int i=1; i<v.size(); i++){
        res += max(v[i-1] - v[i],0);
        v[i] = max(v[i-1],v[i]);
    }
    cout<<res;
    return 0;
}