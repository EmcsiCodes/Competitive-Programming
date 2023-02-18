#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n,h;
    cin>>n>>h;
    int r=0,l=0;
    vector<int> day;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        day.push_back(x);
    }
    int sum=day[0],best=n+1;
    int p,q;
    while(r<day.size()){        
        if(sum<h){
            r++;
            sum+=day[r];
        } 
        if(sum>=h){
            sum-=day[l];
            if(r-l<best){
                best = r-l;            
                p=l+1;
                q=r+1;
            }
            l++;
        }
    }
    if(best==n+1) cout<<-1;
    else cout<<p<<" "<<q;
    return 0;
}