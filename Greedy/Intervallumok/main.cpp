#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
Here's a summary of the problem "Intervallumok" (Intervals):

- **Problem Description**:
  Guests arrive and depart at different time intervals at an event. We want to announce a piece of news to all guests. To do this, we select some guests who can convey this to everyone who is present with them at least once during the event. This means there should be a selected interval [A, B] for any interval [K, V] such that K ≤ X ≤ V and A ≤ X ≤ B.

- **Task**:
  Create a program that calculates the minimum number of people to select so that the news reaches every guest (i.e., each guest has at least one common time interval with one of them).

- **Input**:
  - The first line of standard input contains the number of people N (0 < N ≤ 10,000).
  - The following N lines each contain two integers separated by a space: the arrival and departure times of a person (1 ≤ E ≤ T ≤ 10,000).

- **Output**:
  - The program should output the number of selected people M in the first line.
  - The second line should contain M integers, the indices of the selected people.

- **Example**:
  - **Input**:
    ```
    6
    1 3
    2 4
    1 4
    3 5
    3 6
    4 7
    ```
  - **Output**:
    ```
    1
    3
    ```

- **Constraints**:
  - Time Limit: 0.1 seconds
  - Memory Limit: 32 MB
*/
struct Vendeg
{
    int kezd;
    int vegez;
    int index;
};

bool comp(const Vendeg &p1, const Vendeg &p2)
{
    return p1.vegez < p2.vegez;
}
bool comp2(const Vendeg &p1, const Vendeg &p2)
{
    return p1.kezd < p2.kezd;
}

int main()
{
    int n;
    cin >> n;
    vector<Vendeg> a(n);
    vector<Vendeg> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].kezd >> a[i].vegez;

        a[i].index = i + 1;

        b[i].kezd = a[i].kezd;
        b[i].vegez = a[i].vegez;
        b[i].index = i + 1;
    }
    sort(a.begin(), a.end(), comp);
    sort(b.begin(), b.end(), comp2);
    vector<int> solve;
    int end;
    for (int i = 0; i < n; i++)
    {
        end = a[i].vegez;
        int maxx = 0;
        int ind;
        for (int j = 0; j < n; j++)
        {
            if (b[j].kezd <= end)
            {
                if(b[j].vegez > maxx)
                {
                    maxx = b[j].vegez;
                    ind = j;
                }
            }
            else
                break;
        }
        solve.push_back(b[ind].index);
        end = b[ind].vegez;
        while (a[i + 1].kezd <= end && i < n - 1)
        {
            i++;
        }
    }
    cout << solve.size() << endl;
    for (int i : solve)
        cout << i << " ";
    return 0;
}
/*
### Program: "Intervals"

1. **Understanding the Problem**:
   - Guests arrive and depart at different time intervals at an event.
   - We want to select some guests such that each guest has at least one common time interval with one of them.

2. **Approach**:
   - Sort the guests based on their departure times.
   - Iterate through the sorted list and greedily choose guests such that they have a common interval.
   - Output the selected guests.

3. **Algorithm**:
   - Read input values for the number of people N and their arrival and departure times.
   - Create a structure to store guest information: arrival time, departure time, and index.
   - Sort the guests based on their departure times.
   - Initialize a variable to keep track of the end time of the common interval.
   - Iterate through the guests and greedily select guests that have a common interval with the current end time.
   - Output the selected guests.

4. **Explanation**:
   - We sort the guests based on departure times.
   - We iterate through the guests and greedily choose guests that have a common interval.
   - We output the number of selected guests and their indices.

5. **Time Complexity**:
   - Sorting the guests based on departure times: O(N log N)
   - Iterating through the guests and selecting guests: O(N)
   - Total: O(N log N)

This approach calculates the minimum number of people to select so that the news reaches every guest, satisfying the problem requirements.
*/