#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool valid(int mid,int k,vector<int> v){
    int subSecNum = 1;
    int curr = 0;
    for(int i=0; i<v.size(); i++){
        curr += v[i];
        if(curr > mid){
            curr = v[i];
            subSecNum++;
            if(curr > mid) return false;
        }
    }
    if(subSecNum <= k) return true;
    return false;
}

int main()
{
    ifstream in("sume3.in");
    ofstream out("sume3.out");
    int n;
    int testNum = 1;
    while(in>>n && n!=0){
        int k;
        in>>k;
        vector<int> v;
        int sum = 0;
        for(int i=1; i<=n; i++){
            int x;
            in>>x;
            sum += x;
            v.push_back(x);
        }
        int r = sum;
        int l = 0;
        int res = sum;
        while(l<=r){
            int mid = (l + r) / 2;
            if(valid(mid,k,v)){
                res = min(res, mid);
                r = mid - 1;
            } else l = mid + 1;
        }
        out<<testNum<<":"<<res<<'\n';
        testNum++;
    }
    return 0;
}