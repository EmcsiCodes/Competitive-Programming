#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int n;
    cin>>n;
    multiset<int> s;
    for(int i=1; i<=n; i++){
        int x; cin>>x;
        s.insert(x);
    }
    int res = 0;
    while(s.size()>1){
        auto last2 = s.begin();
        auto last1 = last2;
        last2++;
        int curr = *last1 + *last2;
        res += curr;
        s.erase(last1);
        s.erase(last2);
        s.insert(curr);
    }
    cout<<res;
    return 0;
}