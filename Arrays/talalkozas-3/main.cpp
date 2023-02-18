#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int n,p,q;
    cin>>n>>p>>q;
    string first,second;
    cin>>first>>second;
    unordered_map<char,int> fi,se;
    for(int i=0; i<first.size(); i++){
        fi[first[i]]+=1;
    }
    for(int i=0; i<second.size(); i++){
        se[second[i]]+=1;
    }
    if(fi['K']>se['K']){
        while(fi['K']>1 && fi['K']>se['K']){
            fi['K']-=2;
            fi['J']+=1;
            fi['B']+=1;
        }
    }
    cout<<min(fi['B'],se['B']) + min(fi['J'], se['J']) + min(fi['K'],se['K']) + 1;
    return 0;
}