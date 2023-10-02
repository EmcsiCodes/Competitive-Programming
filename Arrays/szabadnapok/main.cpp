//ez nem a leghatekonyabb megoldas.
//lehet ehhez hasznalni trie-okat hogy hatekonyabb legyen

#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>
using namespace std;
/*
This problem involves determining the number of people who have at least one day off that differs from all the other people.

Here's a detailed explanation of the problem:

Input:

The first line of the input contains an integer N, the number of people (1 ≤ N ≤ 5000), and an integer M, the number of days (1 ≤ M ≤ 61).
The following N lines each contain an integer Si, the number of days off for the i-th person (1 ≤ Si ≤ M).
For each person, Si lines follow, each containing the day number of their days off (1 ≤ Sij ≤ M).
Objective:

The goal is to determine the number of people who have at least one day off that differs from all the other people.
Output:

The program should output the number of people who have at least one day off that differs from all the other people.
Example:

For example, given the days off for each person, the program should determine the number of people who have at least one different day off from all the others.
Constraints:

The time limit for the program is 0.2 seconds.
The memory limit for the program is 32 MB.
*/
int main()
{
    int n,m;
    unordered_map < set<int>, int > occurDays;  // Track occurrences of sets of days off.
    set< set<int> > days, sol;  // Sets to store unique sets of days off and the solution set.
    cin>>n>>m;  // Input the number of people and the total number of days.
    
    // Input the days off for each person and track their occurrences.
    for(int i=0; i<n; i++){
        int size;
        cin>>size;
        set<int> currSet;
        for(int j=0; j<size; j++){
            int x;
            cin>>x;
            currSet.insert(x);
        }
        if(occurDays.find(currSet)==occurDays.end()){
            occurDays[currSet] = 1;
        } else occurDays[currSet]++;
    }
    
    // Find unique sets of days off where only one person has that set.
    for(auto i:occurDays){
        if(i.second==1){
            days.insert(i.first);
        }
    }
    
    auto p = prev(days.end());
    sol.insert(*p);
    
    // Iterate through the unique sets of days off and find the ones that are distinct.
    for(auto s=days.rbegin(); s!=days.rend(); s++){
        set<int> curr = *s;
        for(auto p=sol.begin(); p!=sol.end(); p++){
            set<int> cont = *p;
            if(!includes(cont.begin(), cont.end(), curr.begin(), curr.end())){
                sol.insert(curr);
                break;
            }
        }
    }
    
    // Output the number of people with at least one different day off from all the others.
    cout<<sol.size();
    return 0;
}
/*
Step-by-Step Explanation:
Input Reading:

n and m are read from input, representing the number of people and the total number of days.
Data Storage:

A map occurDays is used to track occurrences of sets of days off for each person.
A set days is used to store unique sets of days off where only one person has that set.
A set sol is used to store the solution set.
Processing Days Off:

The code iterates over each person's days off and counts occurrences using occurDays.
Finding Unique Sets:

Unique sets of days off (where only one person has that set) are stored in days.
Finding Distinct Sets:

The code iterates through the unique sets of days off and finds the ones that are distinct from the sets already in sol.
Output:

Finally, the code outputs the number of people who have at least one different day off from all the others.
Complexity Analysis:
The time complexity is influenced by the loops over the number of people and the sets of days off, making it approximately O(NM), where N is the number of people and M is the maximum number of days off for any person.
The space complexity is influenced by the sets and maps used, making it approximately O(NM) due to the worst case of unique sets.
*/