#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n,k,l;
    cin>>n>>k>>l;
    vector < pair < int, char > > days;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        days.push_back(make_pair(x,'n'));
    }
    for(int i=1; i<days.size()-1; i++){
        if(days[i].first>days[i-1].first && days[i].first>days[i+1].first)
        {
            days[i].second='k';
        }
        if(days[i].first<days[i-1].first && days[i].first<days[i+1].first)
        {
            days[i].second='l';
        }
    }
    int hi=0,lo=0,kdb=0,ldb=0;
    int res1=0;
    return 0;
}