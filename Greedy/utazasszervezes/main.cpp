#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n,k,m,c;
    cin>>n>>k>>m>>c;
    vector<int> isFree(30000,0), rendeles(30000,0);
    for(int i=1; i<=c; i++){
        int x;
        cin>>x;
        rendeles[x] += 1;
    }
    int res = 0;
    for(int i=1; i<=k; i++){
        n += isFree[i];
        isFree[i] = 0;
        if(n>0 && rendeles[i]>0){
            n--;
            isFree[i+m] += 1;
            res++;
            rendeles[i]--;
            i--;
        }
    }
    cout<<res;
    return 0;
}
/*
2 10 4 6
1 2 2 5 6 7
*/