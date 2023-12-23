#include <iostream>
#include <set>

using namespace std;
/*
This problem involves identifying the countries whose representatives have completed the entire marathon in the order they crossed the finish line.

Here's a detailed explanation of the problem:

Input:

The first line of the input contains an integer N, representing the number of participants in the marathon (1 ≤ N ≤ 10,000).
The following N lines each contain a 3-letter country code for a participant (uppercase English alphabet). The total number of unique country codes is at most 200.
Objective:

The goal is to determine the countries whose representatives have completed the marathon.
Output:

The program should output:
The number of countries whose representatives completed the marathon.
The country codes of these countries in ascending order.
Example:

For example, given the participants' country codes, the program should determine the countries whose representatives completed the marathon.
Constraints:

The time limit for the program is 0.1 seconds.
The memory limit for the program is 32 MB.
*/
int main()
{
    int n;
    string s;
    cin>>n;
    set<string> p;
    for(int i=1; i<=n; i++){
        string s;
        cin>>s;
        p.insert(s);
    }
    cout<<p.size()<<endl;
    for(auto it : p) cout<<it<<" ";
    return 0;
}
/*
Problem Overview:
The problem requires finding the countries whose representatives completed the marathon.

Approach:
The program follows these steps to determine the countries whose representatives completed the marathon:

Input Reading:

Read the number of participants in the marathon (N).
Read the country codes of each participant and insert them into a set to get unique codes.
Find Unique Country Codes:

Use a set (p) to store the unique country codes of the participants.
Output:

Output the number of unique country codes.
Output the unique country codes in ascending order.
Detailed Explanation:
The program first reads the input value for the number of participants in the marathon (N).
It then processes the country codes of each participant, storing them in a set (p) to ensure uniqueness.
The set automatically handles uniqueness, ensuring that each country code is unique.
Finally, the program prints the number of unique country codes and the country codes in ascending order.
*/