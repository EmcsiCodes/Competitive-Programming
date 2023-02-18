#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int n,b;
    cin>>n>>b;
    bool emp1[10001],emp2[10001];
    for(int i=1; i<=n; i++){
        emp1[i] = false;
        emp2[i] = false;
    }
    for(int i=1; i<=b; i++){
        int x,y;
        cin>>x>>y;
        if(x==1){
            emp1[y] = true;
        } else {
            emp2[y] = true;
        }
    }
    set<int> res;
    for(int i=1; i<=n; i++){
        if(emp1[i]!=emp2[i] || (emp1[i]==false && emp2[i]==false)) res.insert(i);
    }
    cout<<res.size()<<endl;
    for(auto i:res) cout<<i<<" ";
    return 0;
}