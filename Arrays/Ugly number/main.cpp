#include <iostream>
//leetcode problem
using namespace std;
    bool isUgly(int n) {
        if(n==0) return true;
        if(n == INT_MIN) return false;
        if(n<0) n *= -1;
        cout<<n<<endl;
        while(n>1) n /= 5;cout<<n<<endl;
        while(n>1) n /= 3;cout<<n<<endl;
        while(n>1) n /= 2;cout<<n<<endl;
        if(n!=1) return false;
        return true;
    }

int main()
{
    int n;
    cin>>n;
    if(isUgly(n)) cout<<true;
    else cout<<false;
}