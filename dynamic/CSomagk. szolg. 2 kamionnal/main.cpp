#include <iostream>
#include <vector>

using namespace std;

void part(vector<int> v, int k){
    int check[1001][1001]={false};
    vector < pair<int,int> > sol;
    sol.push_back(k,k);
    int i=0;

}

int main()
{
    int k,n;
    cin>>k>>n;
    vector<int> v;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    part(v,k);
    return 0;
}
