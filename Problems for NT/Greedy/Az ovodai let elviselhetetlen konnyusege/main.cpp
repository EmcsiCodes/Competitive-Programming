#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct in{
    int role;
    int cryTime;
    int i;
};

struct Compare{
    bool operator()(in const& p1,in const& p2){
        return p1.cryTime>p2.cryTime;
    }
};

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> roleNum;
    vector<int> cap(k+1,0);
    vector<in> kids;
    roleNum.push_back(0);
    for(int i=1; i<=k; i++){
        int x;
        cin>>x;
        roleNum.push_back(x);
    }
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        kids.push_back({x,0,i});
    }
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        kids[i-1].cryTime = x;
    }
    sort(kids.begin(),kids.end(),Compare());
    vector<int> totalCryKids;
    vector<int> neededRoles;
    int totalCry = 0;
    vector<int> res(n+1,0);

    for(int i=0; i<kids.size(); i++){
        cap[kids[i].role]++;
        res[kids[i].i] = kids[i].role;
        if(cap[kids[i].role]>roleNum[kids[i].role]){

            cap[kids[i].role]--;
            totalCry += kids[i].cryTime;
            totalCryKids.push_back(kids[i].i);

        }
    }
    for(int i=1; i<=k; i++){
        if(cap[i] == 0){
            neededRoles.push_back(i);
        }
    }

    if(neededRoles.size() < totalCryKids.size()){
        int i=0, j=0;
        while(i<neededRoles.size()){
            res[totalCryKids[j]] = neededRoles[i];
            i++;
            j++;
        }
        int p = 1;
        while(j<totalCryKids.size()){
            while(j<totalCryKids.size() && cap[p]<=roleNum[p]) {
                res[totalCryKids[j]] = p;
                cap[p]++;
                j++;
            }
            p++;
        }
        cout<<totalCry<<'\n';
        for(int i=1; i<=n; i++){
            cout<<res[i]<<" ";
        }
        return 0;
    }
    if(neededRoles.size() > totalCryKids.size()){
        int i=0, j=0;
        while(j<totalCryKids.size()){
            res[totalCryKids[j]] = neededRoles[i];
            i++;
            j++;
        }
        j = n;
        while(i<neededRoles.size()){
            while(i<neededRoles.size() && cap[kids[j].role]>1){
                totalCry += kids[j].cryTime;
                cap[kids[j].role]--;
                res[kids[j].i] = neededRoles[i];
                i++;
            }
            j--;
        }
        cout<<totalCry<<'\n';
        for(int i=1; i<=n; i++){
            cout<<res[i]<<" ";
        }
        return 0;
    }
    if(neededRoles.size() == totalCryKids.size()){
        int i=0, j=0;
        while(j<totalCryKids.size()){
            res[totalCryKids[j]] = neededRoles[i];
            i++;
            j++;
        }
        cout<<totalCry<<'\n';
        for(int i=1; i<=n; i++){
            cout<<res[i]<<" ";
        }
        return 0;
    }
    return 0;
}
/*
6 4
2 2 2 2
1 2 4 1 2 2
1 4 2 1 2 3
*/