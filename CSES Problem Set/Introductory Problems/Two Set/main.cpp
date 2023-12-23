#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int main()
{
    ll n;
    cin>>n;
    if((n*(n+1))/2%2) {
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<endl;
    ll target = (n*(n+1))/2/2;
    vector<int> res1,res2;
    ll sum1 = 0;
    ll used = 0, last;
    ll i = 1;
    for(i=1; i<=n; i++){
        res1.push_back(i);
        if(sum1 + n + 1 > target){
            res1.push_back(target - sum1 - i);
            used = target - sum1 - i;
            last = n - i + 2;
            break;
        } else res1.push_back(n-i+1);
        sum1 += n + 1;
        if(sum1 == target){
            last = n - i + 2;
            break;
        }
    }
    cout<<res1.size()<<endl;
    for(auto i:res1) cout<<i<<" ";
    cout<<endl<<n - res1.size()<<endl;
    for(ll j=i+1; j<last; j++){
        if(j!=used) cout<<j<<" ";
    }
    return 0;
}