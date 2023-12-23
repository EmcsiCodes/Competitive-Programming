#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    cout<<0<<'\n';
    int illegalmoves = 0;
    int lastline = 0;
    for(long long i=2; i<=n; i++){
        if(i == 3) illegalmoves = 8;
        else if(i == 4) {
            illegalmoves = 24;
            lastline = 2 + 3 + 3 + 2;
        }
        else if(i>4){
            lastline += 4;
            illegalmoves += lastline + 2 + 4*(i-3);
        }
        long long a = i*i;
        cout<<a*a - (a*(a+1))/2 - illegalmoves<<'\n';
    }
    return 0;
}