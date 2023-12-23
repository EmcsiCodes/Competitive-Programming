#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v(n,0);
    if(n==1) {
        cout<<1;
        return 0;
    }
    if(n==3 || n==2) {
        cout<<"NO SOLUTION";
        return 0;
    }
    if(n == 4) {
        cout<<2<<" "<<4<<" "<<1<<" "<<3;
        return 0;
    }
    else {
        int mid = n/2 - !(n%2);
        int l = mid - 1;
        int r = mid + 1;
        v[mid] = n;
        int last = mid+1 + !(n%2), turn = -1;
        while(l>=0 && r<n){
            v[l] = last + turn;
            v[r] = n - v[l] + !(n%2);
            last = v[r]; l--; r++; turn *= -1;
        }
        if(n%2 == 0) {
            v.pop_back();
            if(v[v.size()-1] == 2) cout<<1<<" ";
            else v.push_back(1);
        }
        for(int i = 0; i<v.size(); i++){
            cout<<v[i]<<" ";
        }
    }
}