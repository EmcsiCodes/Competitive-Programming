#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,m,k,v_num;
    vector<int> v, people, store;
    cin>>v_num>>m>>n;
    for(int i=0; i<v_num; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    for(int i=0; i<m; i++){
        int x;
        cin>>x;
        store.push_back(v[x-1]);
    }
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        people.push_back(v[x-1]);
    }
    cin>>k;
    int count=0;
    int i=0,j=0;
    while(i<n && j<m){
        if(people[i] >= store[j] - k  && people[i] <= store[j] + k){
            count++;
            i++;
            j++;
        } else if(people[i] < store[j] - k) i++;
        else j++;
    }
    cout<<count<<endl;
    return 0;
}