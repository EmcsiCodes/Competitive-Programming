#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
    int n;
    //ifstream f("be.txt");
    cin>>n;
    vector<int> v;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    pair<int,int> index = {0,0};
    int maxSell = 0;
    int currSell = 0;
    int currIndex = 0;
    int start = 0;
    for(int i=0; i<v.size()-1; i++){
        //cout<<v[i]<<" "<<v[i+1]<<endl;
        if(v[start]<=v[i+1]){
            if(currSell<v[i+1] - v[start]){
                currSell = v[i+1] - v[start];
                currIndex = i+1;
            }
        } else {
            if(currSell>maxSell){
                maxSell = currSell;
                index = {start,currIndex};
            }
            currSell = 0;
            currIndex = 0;
            start = i+1;
        }
    }
    if(currSell!=0){
        if(currSell>maxSell){
            maxSell = currSell;
            index = {start,currIndex};
        }
    }
    cout<<index.first+1<<" "<<index.second+1;
    return 0;
}