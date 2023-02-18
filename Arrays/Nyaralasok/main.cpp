#include <iostream>
#include <vector>
using namespace std;

void threeSumClosest(vector<int> v, int p){
    int best=p;
    vector<int> sol={0,0,0};
    if(v[0]>p) cout<<-1;
    for(int i=0; i<v.size()-2; i++){
        int l=i+1,r=v.size()-1;
        if(p-v[i]-v[i+1]-v[i+2]<0) break;
        while(l<r){
            int sum=v[i]+v[l]+v[r];
            if(p-sum<best && sum<=p){
                best=p-sum;
                sol[0]=i+1;
                sol[1]=l+1;
                sol[2]=r+1;
                if(best==0) break;
            }
            if(sum<p){
                l++;
            }
            if(sum>p){
                r--;
            }
        }
    }
    if(sol[0]==0) cout<<-1;
    else cout<<sol[0]<<" "<<sol[1]<<" "<<sol[2]<<endl;
}

int main()
{ 
    int n,p;
    cin>>n>>p;
    vector<int> v;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    threeSumClosest(v,p);
    return 0;
}