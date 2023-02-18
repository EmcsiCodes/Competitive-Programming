#include <iostream>
#include <vector>

using namespace std;

void LIS(vector <int> v){
    int lo=1;
    int hi=1;
    //cout<<v[0][0]<<"("<<v[0][1]<<", "<<v[0][2]<<") ";
    vector <int> sol;
    sol.push_back(1);
    for(int i=1; i<v.size(); i++){
        if(v[i]<v[i-1]){
            if(hi!=lo+1){
                sol.push_back(i+1);
            }
            hi = lo + 1;

        } else if(v[i]>v[i-1]){
            if(lo!=hi+1){
                sol.push_back(i+1);
            }
            lo = hi + 1;
        }
        //cout<<v[i][0]<<"("<<v[i][1]<<", "<<v[i][2]<<") ";
    }
    //cout<<endl<<endl;
    cout<<max(lo,hi)<<endl;
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
    //for(int i=0; i<v.size(); i++) cout<<v[i][0]<<" ";
    //cout<<endl;
    LIS(v);
    return 0;
}
/*
10
3 2 1 9 2 1 3 6 8 2
*/
