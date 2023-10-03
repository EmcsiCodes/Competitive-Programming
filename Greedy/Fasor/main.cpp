#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> v;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    int maxx = 0, curr = 0, i = 0;
    while(i<v.size() && curr<k){
        if(v[i]>maxx){
            curr = 0;
            maxx = v[i];
        } else curr++;
        i++;
    }
    cout<<i - curr;
}
/*
10 3
6 2 1 8 4 8 7 12 9 3
*/