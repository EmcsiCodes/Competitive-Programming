#include <iostream>

using namespace std;

void backt(int maxx,int n,int m,int t[201][201],int a[201][201],int p,int q,int k){
    maxx--;
    cout<<maxx<<endl;
    string s="";
    for(int i=maxx; i>=1; i--){
        if(p>1){
            if(abs(a[p][q]-a[p-1][q])<=k && t[p-1][q]==i){
                s = 'L' + s;
                p--;
                continue;
            }
        }
        if(q>1){
            if(abs(a[p][q-1]-a[p][q])<=k && t[p][q-1]==i){
                s = 'J' + s;
                q--;
            }
        }
    }
    cout<<p<<" "<<q<<endl<<s;
}

int main()
{
    int n,m,k,a[201][201],t[201][201];
    cin>>n>>m>>k;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>a[i][j];
        }
    }
    int maxx = 0;
    int p=0,q=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(i==1 or j==1) t[i][j] = 1;
            else {
                bool u=false,l=false;
                if(abs(a[i][j]-a[i-1][j])<=k) u=true;
                if(abs(a[i][j]-a[i][j-1])<=k) l=true;
                t[i][j]=1;
                if(u==true and l==true) t[i][j] = max(t[i-1][j],t[i][j-1]) + 1;
                if(u==true and l==false) t[i][j] = t[i-1][j] + 1;
                if(u==false and l==true) t[i][j] = t[i][j-1] + 1;
                if(t[i][j]>maxx){
                    maxx=t[i][j];
                    p=i;
                    q=j;
                }
            }
        }
    }
    backt(maxx,n,m,t,a,p,q,k);
    /*
    cout<<endl;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }
    /*
5 4 1
7 7 9 7
4 5 3 4
6 6 5 2
4 7 8 2
1 2 3 4
//
    */
    return 0;
}
