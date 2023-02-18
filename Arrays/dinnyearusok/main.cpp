#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n,m,k;
    vector<int> people,store;
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        people.push_back(x);
    }
    cin>>m;
    for(int i=0; i<m; i++){
        int x;
        cin>>x;
        store.push_back(x);
    }
    cin>>k;
    int count=0;
    int i=0,j=0;
    while(i<n && j<m){
        if(people[i] >= store[j] - k && people[i] <= store[j] + k){
            count++;
            i++;
            j++;
        }
        else if(people[i] < store[j] - k) i++;
                else j++;
    }
    cout<<count;
}