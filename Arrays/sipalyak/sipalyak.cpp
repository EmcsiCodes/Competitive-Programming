#include <iostream>
#include <vector>
using namespace std;
#define LL long long

int main()
{
    int n, k;
    cin >> n >> k;
    vector<LL> v;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    LL next = v[0] - 1;
    LL currSum = v[0];
    int ground = 0;
    for (int i = 1; i < k; i++) {
        currSum += v[i];
        if (v[i] <= next) next--; //setben el kell menteni a abs(next - v[i])-t.
        //ha elhagyjuk a groundot akkor uj ground = regi lepcso - min(abs ertekek)
        else {
            next = v[i] - 1;
            ground = i;
        }
    }
    LL neededSum = ((next + k) * (next + k + 1) / 2) - (next * (next + 1) / 2);
    LL best = neededSum - currSum;
    LL l = 0, r = k;
    
    while (r < v.size()) {
        currSum = currSum - v[l] + v[r];
        if (v[r] <= next) next--;
        else next = v[r] - 1;
        neededSum = ((next + k) * (next + k + 1) / 2) - (next * (next + 1) / 2);
        //cout << best << " " << neededSum << "-" << currSum << endl;
        best = min(best, neededSum - currSum);
        r++;
        l++;
    }
    cout << best;
    return 0;
}
