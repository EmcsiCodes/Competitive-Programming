#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int n,p,q;
    cin>>n>>p>>q;
    string friend1,friend2;
    cin>>friend1>>friend2;
    unordered_map<char,int> a,b;
    for(int i=0; i<friend1.size(); i++){
        a[friend1[i]]+=1;
    }
    for(int i=0; i<friend2.size(); i++){
        b[friend2[i]]+=1;
    }
    cout<<min(a['J'],b['J']) + min(a['B'],b['B']) + 1;
    return 0;
}