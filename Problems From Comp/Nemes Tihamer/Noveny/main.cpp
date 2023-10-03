#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,m,k,l;
    cin>>n>>m>>k>>l;
    int x;
    cin>>x;
    int alive[100001];
    alive[0] = 0;
    int newPlants[100001];
    newPlants[0] = 0;
    int sum = 0;
    newPlants[1] = l;
    alive[1] = l;
    for(int i=2; i<=x; i++){
        if(i>m) sum = (sum + newPlants[i-m])%20180113;
        if(i>m+k) sum -= newPlants[i-m-k];
        newPlants[i] = sum;
        alive[i] = (newPlants[i] + alive[i-1])%20180113;
        if(i>n) alive[i] -= alive[i-n];
    }
    cout<<newPlants[x]<<'\n'<<alive[x];
    return 0;
}
