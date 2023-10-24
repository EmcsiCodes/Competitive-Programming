#include <iostream>
#include <vector>
using namespace std;
/*
In the police evidence storage, only three police officers have the right to enter. Records of the past N days have been received,
but for privacy reasons, only the identifier of the entrant and the entry date are known (an officer may enter multiple times on the same day).

Write a program to determine the days when someone entered the evidence storage, but not all three officers did.

Input:

The first line of the standard input contains the number of days (N) and the number of entries (B).
The following B lines contain the data for each entry. The first number in each line is the identifier of the entrant (Azi=1, 2, or 3),
and the second number is the entry date (1≤Napi≤N), listed in increasing order of days.
Output:

The output should first list the number M of days when not all three officers entered the evidence storage.
The second line should contain the numbers of these days in ascending order.
Example:

Given the number of days and entries, determine the days when someone entered the evidence storage, but not all three officers did.
Constraints:

Time limit for input processing: 0.1 seconds
Memory limit: 32 MB
*/
int main()
{
    int n,b;
    bool v1[10001],v2[10001],v3[10001];
    cin>>n>>b;
    for(int i=1; i<=n; i++){
        v1[i]=false;
        v2[i]=false;
        v3[i]=false;
    }
    for(int i=0; i<b; i++){
        int x,y;
        cin>>x>>y;
        if(x==1) v1[y] = 1;
        if(x==2) v2[y] = 1;
        if(x==3) v3[y] = 1;
    }
    vector<int> res;
    for(int i=1; i<=n; i++){
        if(!(v1[i]==true && v2[i]==true && v3[i]==true) && (v1[i]==true || v2[i]==true || v3[i]==true)) res.push_back(i);
    }
    cout<<res.size()<<endl;
    for(auto i:res) cout<<i<<" ";
    return 0;
}
/*
Explanation of the Program's Approach:

Input Reading:

The program starts by reading the number of days (N) and the number of entries (B) from the user.
Initialize Arrays:

Three boolean arrays v1, v2, and v3 are initialized to keep track of entries for each officer for each day.
Process Entry Data:

The program then iterates through the given entries (B times).
For each entry, it reads the officer's identifier (x) and the entry date (y).
Depending on the officer's identifier, it marks the respective day as an entry for that officer by setting the corresponding value to true in the respective array (v1, v2, or v3).
Determine Days with Partial Entry:

Next, the program iterates through each day (1 to N) and checks if at least one officer entered but not all three officers entered on that day.
It uses the conditions !(v1[i] == true && v2[i] == true && v3[i] == true) and (v1[i] == true || v2[i] == true || v3[i] == true) to determine these days.
If these conditions are met, it records the day in a vector named res.
Output:

Finally, the program prints the count of days where someone, but not all three officers, entered the evidence storage (res.size()) and the days themselves in ascending order.
Overall, the program effectively processes the given entry data, keeps track of each officer's entries for each day, and determines the days when someone entered the evidence
storage but not all three officers did.
It then prints the count and the days that meet these criteria, following the specified constraints of the problem.
*/