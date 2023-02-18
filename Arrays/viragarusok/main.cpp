#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string,int> flowers,seller1,seller2;
void be(){    
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        string flower;
        int flower_num;
        cin>>flower>>flower_num;
        flowers[flower]=flower_num;
    }
    cin>>n;
    for(int i=1; i<=n; i++){
        string flower;
        int flower_num;
        cin>>flower>>flower_num;
        seller1[flower]=flower_num;
    }
    cin>>n;
    for(int i=1; i<=n; i++){
        string flower;
        int flower_num;
        cin>>flower>>flower_num;
        seller2[flower]=flower_num;
    }
}

int main()
{
    be();
    int sol1=0;
    for(auto i:flowers){
        int c = i.second;
        if(seller1.find(i.first)!=seller1.end()){
            c -= seller1[i.first];
            if(c<0) c = 0;
        }
        sol1 += c;
    }
    int sol2 = 0;
    for(auto i:flowers){
        int c = i.second;
        if(seller2.find(i.first)!=seller2.end()){
            c -= seller2[i.first];
            if(c<0) c = 0;
        }
        sol2 += c;
    }
    if(sol1<sol2) cout<<1<<endl<<sol1;
    else cout<<2<<endl<<sol2;
    return 0;
}
/*3
ibolya 5
kankalin 2
orgona 3
4
ibolya 4
kankalin 1
liliom 20
orgona 2
3
amarillisz 3
kankalin 2
orgona 3*/