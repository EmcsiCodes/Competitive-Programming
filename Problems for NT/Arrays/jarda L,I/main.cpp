#include <iostream>

using namespace std;

int main()
{
    int n,T[30];
    cin>>n;
    T[0]=0;
    T[1]=1;
    T[2]=2;
    T[3]=5;
    int sum = 1;
    for(int i=4; i<=n; i++){
        T[i] = T[i-1] + T[i-2] + 2 * sum + 2;
        sum += T[i-2];
    }
    cout<<T[n];
    return 0;
}
