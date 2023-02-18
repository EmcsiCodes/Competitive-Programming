#include <iostream>
#include <vector>
#include <map>
using namespace std;

/// @brief 
/// @return 
int main()
{
    int k;
    cin>>k;
    map< pair<int,int>, pair<int,int> > startDay, endDay;
    vector< vector< pair<int,int> > > v;
    for(int i=0; i<k; i++){
        int n;
        cin>>n;
        vector< pair<int,int> > curr;
        for(int j=0; j<n; j++){
            int x,y;
            cin>>x>>y;
            curr.push_back(make_pair(x,y));
        }
        v.push_back(curr);
    }
    for(int i=0; i<k; i++){
        if(v[i].size()>1){
            startDay[{v[i][0].first,i}] = {i,0};
            endDay[{v[i][0].second,i}] = {i,0};        
        }
    }
    pair<int,int> best={0,1000000};
    bool possible = true;
    int j;
//    cout<<"szevasz";
//    for(auto p=startDay.begin(); p!=startDay.end(); p++) cout<<(p->first).first<<"("<<(p->first).second<<"); ";
//    cout<<endl;
//    for(auto p=endDay.begin(); p!=endDay.end(); p++) cout<<(p->first).first<<"("<<(p->first).second<<"); ";
//    cout<<endl;
    while(possible){
        auto hi = startDay.rbegin()->first.first;
        auto lo = endDay.begin()->first.first;
        if(hi - lo < 0) {
            best = {hi,hi};
            break;
        } else if(hi - lo < best.second - best.first){
            best = {lo,hi};
//            cout<<best.first<<" "<<best.second<<endl;
//            for(auto p=startDay.begin(); p!=startDay.end(); p++) cout<<(p->first).first<<"("<<(p->first).second<<"); ";
//            cout<<endl;
//            for(auto p=endDay.begin(); p!=endDay.end(); p++) cout<<(p->first).first<<"("<<(p->first).second<<"); ";
//            cout<<endl;
        }
        pair<int,int> index;
        index = startDay.begin()->second;
        endDay.erase({v[index.first][index.second].second,index.first});
        startDay.erase({v[index.first][index.second].first,index.first});
        j = index.second + 1;
        if(j<v[index.first].size()){
            startDay[{v[index.first][j].first,index.first}] = {index.first,j};
            endDay[{v[index.first][j].second,index.first}] = {index.first,j};
        } else possible = false;
    }
    cout<<best.first<<" "<<best.second;
    return 0;
}