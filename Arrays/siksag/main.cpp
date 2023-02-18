#include <iostream>

using namespace std;

void window(int n,int a[]){
    int h_max_i=1;
    int h_min_i=1;
    int h_max=a[1];
    int h_min=a[1];
    int maxlength_index=0;
    int maxlength=0;
    int l=1,r=2;
    bool go = true;
    while(go){
        if(a[r]>=h_max){
            h_max = a[r];
            h_max_i = r;
            if(h_max - h_min >= 2){
                if(maxlength < r - l){
                    maxlength = r - l;
                    maxlength_index = l;
                }
                h_min_i++;
                l = h_min_i;
                h_min = a[l];
                //cout<<"nagyobb a kov "<<l<<"-"<<r<<" max:"<<h_max_i<<"="<<h_max<<" es min:"<<h_min_i<<"="<<h_min<<endl;

            }
        }
        if(a[r]<=h_min){
            h_min = a[r];
            h_min_i = r;
            if(h_max - h_min >= 2){
                if(maxlength < r - l){
                    maxlength = r - l;
                    maxlength_index = l;
                }
                h_max_i++;
                l = h_max_i;
                h_max = a[l];
                //cout<<"kisebb a kov "<<l<<"-"<<r<<" max:"<<h_max_i<<"="<<h_max<<" es min:"<<h_min_i<<"="<<h_min<<endl;
            }
        }
        if(r==n) go = false;
        r++;
        //cout<<maxlength<<" "<<maxlength_index<<": "<<l<<" - "<<r<<endl;

    }
    cout<<maxlength<<" "<<maxlength_index<<endl;
}
/*
16
2 3 3 4 3 5 5 4 3 3  2  3  2  2  1  3

10
2 3 3 4 10 23 23 3 4 6
*/


int main()
{
    int n,a[100000];
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    /*for(int i=1; i<=n; i++){
        cout<<i<<" ";
    }
    cout<<endl;*/
    window(n,a);
    return 0;
}
