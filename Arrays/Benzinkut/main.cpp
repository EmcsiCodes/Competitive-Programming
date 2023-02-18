#include <iostream>

using namespace std;

int main()
{
    int n,k;
    pair<int,int> a[1001];
    pair<int,int> last;
    int ktav[1001];
    cin>>n>>k>>a[1].first>>a[1].second;
    last.first=a[1].first;
    last.second=1;
    for(int i=1; i<=n; i++){
        ktav[i]=0;
    }
    for(int i=2; i<=n; i++){
        cin>>a[i].first>>a[i].second;
        if(a[i].first-k>=last.first){
            ktav[i]=
        }
    }
    return 0;
}
