#include <iostream>
#include <vector>
#include <set>
using namespace std;
/*
In the vault of the Grumbler Bank, only two employees can enter at a time. The security system logs every entry. The records of the past N days have been received, but for privacy reasons, only the identifier of the entrant and the entry date are known (an employee may enter multiple times on the same day).

Write a program to determine the days when both employees did not enter the vault.

Input:

The first line of the standard input contains the number of days (N) and the number of entries (B).
The following B lines contain the data for each entry. The first number in each line is the identifier of the entrant (Azi=1 or 2), and the second number is the entry date (1≤Napi≤N), listed in increasing order of days.
Output:

The output should first list the number M of days when neither employee entered the vault.
The second line should contain the numbers of these days in ascending order.
Example:

Given the number of days and entries, determine the days when neither employee entered the vault.
Constraints:

Time limit for input processing: 0.1 seconds
Memory limit: 32 MB
*/

int main()
{
    int n, b;
    cin >> n >> b;
    bool emp1[10001], emp2[10001];

    // Step 1: Initialize arrays for both employees
    for (int i = 1; i <= n; i++)
    {
        emp1[i] = false;
        emp2[i] = false;
    }

    // Step 2: Process entry data
    for (int i = 1; i <= b; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x == 1)
        {
            emp1[y] = true;
        }
        else
        {
            emp2[y] = true;
        }
    }

    set<int> res;

    // Step 3: Determine days when neither employee entered
    for (int i = 1; i <= n; i++)
    {
        if (emp1[i] != emp2[i] || (emp1[i] == false && emp2[i] == false))
            res.insert(i);
    }

    // Step 4: Output the result
    cout << res.size() << endl;
    for (auto i : res)
        cout << i << " ";

    return 0;
}
/*
Explanation of the Program's Approach:

The program aims to determine the days when neither of the two employees entered the vault based on the provided entry records. It follows these steps:

Input Reading:

Reads the number of days (N) and the number of entries (B).
Reads the data for each entry, which includes the identifier of the entrant and the entry date.
Initialize Arrays:

Initializes boolean arrays for both employees to keep track of their entry days.
Process Entry Data:

Processes the entry data, marking the entry days for each employee in the respective arrays.
Determine Days with No Entry:

Checks each day and determines if neither employee entered or if their entries were conflicting (only one entered on that day).
Records these days in a set (res).
Output:

Prints the count and the days when neither employee entered the vault, in ascending order.
Overall, the program efficiently determines the days when neither of the two employees entered the vault, considering the provided entry records and following the specified constraints.
*/