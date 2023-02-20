#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    vector<int> res;
    res.push_back(1);
    int endPoint = n-1;
    for(int i=1; i<v.size(); i++){
            cout<<v[res.back()]<<"+"<<k<<" "<<v[i]<<endl;
        if(v[res.back()-1]+k<=v[i] && v[i]+k<=v[endPoint]) res.push_back(i+1);
    }
    res.push_back(endPoint);
    cout<<res.size()<<'\n';
    for(auto i:res) cout<<i<<" ";
    return 0;

}
