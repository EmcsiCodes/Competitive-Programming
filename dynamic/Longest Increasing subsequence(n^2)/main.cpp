#include <iostream>
#include <vector>
using namespace std;

void LIS(vector<int> v){
    vector<int> lis(v.size(), 1);
    for(int i=0; i<v.size(); i++) {
        for(int j=0; j<i; j++){
            if(v[i]>v[j] && lis[i]<lis[j]+1){
                lis[i]=lis[j]+1;
            }
        }
    }
    int maxlength=0,index=0;
    for(int i=lis.size()-1; i>=0; i--){
        if(lis[i]>maxlength){
            maxlength=lis[i];
            index=i;
        }
    }
    vector<int> sol;
    cout<<"Longes increasing subsequence length: "<<maxlength<<endl;
    for(int i=index; i>=0; i--){
        if(lis[i]==maxlength) {
            sol.insert(sol.begin(),v[i]);
            maxlength--;
        }
    }
    cout<<"The subsequence: ";
    for(int i:sol){
        cout<<i<<" ";
    }
}

int main()
{
    int n;
    vector<int> v;
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    LIS(v);
    return 0;
}
