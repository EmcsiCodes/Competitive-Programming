#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n,k,l;
    cin>>n>>k>>l;
    int KH,HH,NH,OH;
    cin>>KH>>HH>>NH>>OH;
    vector<int> v;
    vector<int> grades;
    grades.push_back(KH);
    grades.push_back(HH);
    grades.push_back(NH);
    grades.push_back(OH);
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    for(auto i:grades){
        auto it = lower_bound(v.begin(),v.end(),i) - v.begin();
        it--;
        int last = i;
        int currl = 0;
        while(it>=0 && (v[it] == last - 1 || v[it] == last ) && currl<=l){
            if(v[it] == last - 1) {
                last = v[it];    
            }
            it--;
            currl++;
        }
        it++;
        if(currl>l) v[it] = i;
        cout<<v[it]<<'\n';
    }
    return 0;
}
/*
7 100 2
20 40 60 80
37 38 39 19 59 78 79
*/