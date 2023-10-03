#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, currday = 1;
    cin>>n;
    vector<int> res;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;       
        if(currday<=x){
            res.push_back(i);
            currday++;
        }
    }
    cout<<res.size()<<'\n';
    for(auto i:res) cout<<i<<" ";
    return 0;
}
/*
7
1
1
2
2
2
4
4
*/