#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream in("coarde.in");
    ofstream out("coarde.out");
    int testNum = 1;
    int n;
    while(in>>n && n!=0){
        vector<long long> v(n+1,0);
        v[0] = 1;
        v[1] = 1;
        v[2] = 2;
        for(int i=3; i<=n; i++){
            long long curr = 0;
            for(int k=1; k<=i/2; k++){
                curr += (v[i - k] * v[k - 1])%9999991;
            }
            v[i] = ((curr%9999991) * 2)%9999991;
            if(i%2 == 1) v[i] += (v[i/2] * v[i/2])%9999991;
        }
        out<<testNum<<':'<<v[n]%9999991<<'\n';
        testNum++;
    }
    return 0;
}