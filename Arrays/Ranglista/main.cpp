#include <iostream>
#include <set>
#include <map>

using namespace std;
/*
This problem involves calculating the wealth and origin of the top L individuals from a merged ranking based on wealth across different countries.

Here's a detailed explanation of the problem:

Input:

The first line of the input contains two integers: K, the number of countries (2 ≤ K ≤ 10), and L, the number of individuals to consider (1 ≤ L ≤ 100,000).
The following K lines each contain two integers: Mi, the population of the i-th country (1 ≤ Mi ≤ 100,000), and Vi,j, the wealth of the j-th individual in that country (1 ≤ Vi,j ≤ 100,000,000), in decreasing order of wealth within each country.
Objective:

The goal is to determine the wealth and the origin country of the top L individuals from the merged ranking based on wealth.
Output:

The program should output:
The number of the country that has the most individuals among the top L in terms of wealth.
The wealth of the top L individuals in decreasing order.
Example:

For example, given the populations and wealth of individuals in each country, the program should determine the country with the most individuals among the top L and the wealth of those individuals in descending order.
Constraints:

The time limit for the program is 0.2 seconds.
The memory limit for the program is 32 MB.
In 30% of the tests, N ≤ 100.
*/
int main()
{
    int n,l,k=1;
    cin>>n>>l;
    set< pair<int,int> > s;  // A set to store pairs of wealth and the country they belong to.
    
    // Input the wealth for each individual in each country and add them to the set.
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        for(int j=1; j<=x; j++){
            int y;
            cin>>y;
            s.insert(make_pair(y,k));  // Each pair consists of wealth and country number.
        }
        k++;
    }
    
    map<int,int> m;  // A map to count the number of individuals from each country among the top L.
    int l1=l;
    
    // Iterate through the sorted set (highest wealth first) and count individuals from each country in the top L.
    for(auto it=s.rbegin(); it!=s.rend(); it++){
        m[it->second]++;
        l1--;
        if(l1==0) break;
    }
    
    int o=0,index=0;
    for(auto it:m) {
        if(it.second>o){
            index=it.first;  // The country with the most individuals among the top L in terms of wealth.
            o=it.second;
        }
    }
    
    cout<<index<<endl;  // Output the country with the most individuals among the top L.
    
    // Output the wealth of the top L individuals in descending order.
    for(auto it=s.rbegin(); it!=s.rend(); it++){
        cout<<it->first<<endl;
        l--;
        if(l==0) break;
    }
    
    return 0;
}
/*
Input Reading:

Read the number of countries n and the number of individuals to consider l.
Data Storage:

Use a set s to store pairs of wealth and the country they belong to.
Input Wealth Data:

For each country, read the population x and then read x wealth values. Insert each wealth with its corresponding country into the set.
Count Top Individuals from Each Country:

Use a map m to count the number of individuals from each country among the top l.
Iterate through the sorted set (highest wealth first) and count individuals from each country in the top l.
Find Country with Most Individuals:

Find the country with the most individuals among the top l and store its index in the variable index.
Output:

Output the index of the country with the most individuals among the top l.
Output the wealth of the top l individuals in descending order.
This program processes the wealth data and finds the top individuals across countries, taking into account the given constraints and objectives of the problem.
*/