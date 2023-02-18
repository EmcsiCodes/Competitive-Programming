#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int p,n,m;
    cin>>p>>n;
    vector< pair<int,string> > v,s;
    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,"xa"});
        v.push_back({y,"ya"});
    }
    cin>>m;
    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,"xe"});
        v.push_back({y,"ye"});
    }
    sort(v.begin(),v.end());
    int count = 0;
    int val = 0;
    vector< pair<int,int> > res;
    for(int i=0; i<v.size()-1; i++){
        if(v[i].second[0] == 'x') {
            if(v[i].second[1] == 'a') val++;
            else val--;
            count++;
        }
        else count--;
        if(count == 1 && val == 1){
            res.push_back({v[i].first, v[i+1].first});
        }
    }
    if(v[v.size()-2].second == "ye") res.push_back({v[v.size()-2].first, v[v.size()-1].first});
    cout<<res.size()<<endl;
    for(auto i:res){
        cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
}        /*

if(v[i].second == "aFirst"){
            res.push_back({v[i].first, v[i+1].first});
            while(i<v.size() && v[i].second!="aLast"){
                if(v[i].second == "eFirst"){
                    while(i<v.size() && v[i].second!="eLast") i++;
                }
                if(i<v.size() && v[i].second == "eLast") res.push_back({v[i].first, v[i+1].first});
                i++;
            }
        }*/
        /*
50
455 1070
1800 2566
4668 5115
5494 6853
7363 8030
9094 9745
10236 12422
14195 14934
15374 16493
18069 18339
20065 21529
21556 22868
22994 23838
23961 24355
25074 25370
25518 27626
27650 27773
28205 29201
31386 32645
32819 33216 eddig jo
35453 37552
37678 38293
38590 38975
42533 45173
45510 45750
46032 46165
47380 48851
49154 49298
50371 50648
50936 53454
57620 58888
59238 59323
59415 59711
60119 60947
60976 62480
63289 64679
67767 68346
68552 70043
73256 73280
74423 75136
79057 79262
81810 82611
84914 85894
86286 86739
88013 88193
88389 89935
90356 91087
91226 91278
92634 93613
93709 95756
        */