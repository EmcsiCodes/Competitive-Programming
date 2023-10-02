#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
This problem involves a art collector who wants to purchase two paintings from a list within a given budget.

Here's a detailed explanation of the problem:

Input:

The first line of the input contains two integers: N, the number of paintings (1 ≤ N ≤ 200,000), and P, the collector's budget (1 ≤ P ≤ 400,000).
The following N lines each contain an integer Ki, representing the price of a painting (1 ≤ Ki ≤ 200,000).
Objective:

The goal is to determine which two paintings the collector should purchase such that the total cost is exactly P.
Output:

The program should output two arbitrary painting numbers (sorszám), whose prices sum up to P.
If there is no such pair of paintings, output -1.
Example:

For example, given the number of paintings and their respective prices, the program should determine which two paintings to purchase such that their prices sum up to P.
Constraints:

The time limit for the program is 0.2 seconds.
The memory limit for the program is 32 MB.
*/
int main()
{
    int n,p;
    cin>>n>>p;
    vector< pair<int,int> > v;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(make_pair(x,i));
    }
    sort(v.begin(),v.end());
    pair<int,int> sol;
    sol.first=0;
    sol.second=0;
    for(int i=0; i<v.size(); i++){
        pair<int,int> q={p-v[i].second,0};
        auto k=lower_bound(v.begin(),v.end(),q);
        if(k!=v.end() && k->first+v[i].first==p) {
            sol.first=v[i].second+1;
            sol.second=k->second+1;
            break;
        }
    }
    if(sol.first==0) cout<<-1;
    else cout<<sol.first<<" "<<sol.second;
    return 0;
}
/*
Input Reading:

The program starts by reading the number of paintings (N) and the collector's budget (P) from the input. These values are essential for the subsequent steps in the program.
Creating a Vector of Pairs for Paintings:

A vector of pairs called v is created to store information about each painting. Each pair contains the price of a painting (Ki) and its index (i).
A loop iterates through each painting, and for each painting, it reads its price (Ki) and pushes a pair containing the price and the painting's index into the vector.
The use of pairs is helpful as it associates each painting's index with its corresponding price.
Sorting the Paintings by Price:

The vector of pairs is sorted based on the first element of each pair, which is the price of the painting. This is done in ascending order, which aids in efficiently finding pairs that sum up to the budget later.
Finding a Pair with Desired Sum:

A pair q is initialized, where the first element is calculated as the difference between the desired budget (P) and the index of the current painting in consideration.
lower_bound is used to find the first occurrence of the pair q or a pair with a higher price in the sorted vector of paintings.
If a valid pair is found (i.e., the sum of the prices matches the budget), their indices are stored, and the loop breaks.
This approach leverages the sorted nature of the vector to efficiently find a valid pair that meets the budget requirement.
Output:

If a valid pair of paintings is found, the program outputs their indices.
If no such pair is found, indicating it's not possible to buy two paintings within the budget, -1 is outputted.
By breaking down the process into these steps, the program efficiently searches for a pair of paintings within the given budget and provides the desired output accordingly.
*/