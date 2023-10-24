#include <iostream>
using namespace std;

int main(){
   int f1, f2, f3, n;
   cout<<"n=";
   cin>>n;
   f1=1;
   f2=0;
   for(int i=0; i<n; i++)
   {
    f3=f1+f2;
    f1=f2;
    f2=f3;
    cout<<f3<<" ";
   }
return 0;
}
