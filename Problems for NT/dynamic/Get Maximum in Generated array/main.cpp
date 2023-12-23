#include <iostream>
#include <vector>

using namespace std;

int getMaximumGenerated(int n) {
        int maxNum = 0;
        vector<int> v(n+10,0);
        v[1] = 1;
        int index = 0;
        for(int i = 1; i<n/2 + n%2; i++){
            v[i*2] = v[i];
            v[i*2+1] = v[i] + v[i+1];
            maxNum = max(maxNum,v[i*2+1]);
            index = max(index,i*2+1);
        }
        return maxNum;
}

int main()
{
    int n;
    cin>>n;
    cout<<getMaximumGenerated(n);
    return 0;
}