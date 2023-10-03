#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    ifstream in("soricei.in");
    ofstream out("soricei.out");
    int testNum;
    in>>testNum;
    for(int i=1; i<=testNum; i++){
        double b,h,n;
        in>>b>>h>>n;
        double curr, prev = 0;
        for(int i=1; i<n; i++){
            curr = (h - prev)*(1 - sqrt((n - i)/(n - i + 1))) + prev;
            out<<fixed<<setprecision(6)<<curr<<" ";
            prev = curr;
        }
    }
    return 0;
}