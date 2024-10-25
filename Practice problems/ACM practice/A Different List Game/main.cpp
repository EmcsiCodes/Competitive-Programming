#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define LL long long
vector<int> gaussum;

void precalc(){
    int sum = 0;
    gaussum.push_back(sum);
    for(int i=1; i<=10; i++){
        sum += i;
        gaussum.push_back(sum);
    }
}

int solve(LL x){
    int res = 0;
    for(int i=2; i<=x; i++){
        if(x%i == 0){
            int num = 0;
            while(x%i == 0){
                num++;
                x/=i;
            }
            auto curr = upper_bound(gaussum.begin(), gaussum.end(), num);
            res += (curr - gaussum.begin());
            res--;
        }
    }
    return res;
}

int main(){
    LL x;
    cin>>x;
    precalc();
    for(int i=0; i<gaussum.size(); i++){
        cout<<i<<": "<<gaussum[i]<<endl;
    }
    cout<<solve(x);
}