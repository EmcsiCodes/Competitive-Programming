#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    vector< pair<int,int> > v,vec;
    cin>>n;
    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }
    sort(v.begin(),v.end());
    vec.push_back(make_pair(v[0].first,v[0].second));
    int k=0;
    for(int i=1; i<n; i++){
        if(v[i].first>vec[k].second+1){
            k++;
            vec.push_back(make_pair(v[i].first,v[i].second));
        } else vec[k].second=max(vec[k].second,v[i].second);
    }
    int dbnap=0;
    int p=vec.size()-1;
    if(vec[0].first>1) dbnap++;
    if(vec[p].second<365) dbnap++;
    dbnap+=p;
    cout<<dbnap<<endl;
    if(vec[0].first>1) cout<<1<<" "<<vec[0].first-1<<endl;
    for(int i=0; i<p; i++){
        cout<<vec[i].second+1<<" "<<vec[i+1].first-1<<endl;
    }
    if(vec[p].second<365) cout<<vec[p].second+1<<" "<<365<<endl;
    return 0;
}
