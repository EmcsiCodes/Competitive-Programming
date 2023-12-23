#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
Here's a summary of the problem "Szemtanúk" (Witnesses):

- **Problem Description**:
  The police are seeking witnesses for suspicious events that occurred during an event. The organizers of the event recorded the arrival and departure times of every guest. The police want to select the minimum number of guests in such a way that for every suspicious event, there is at least one selected guest who was present at that time.

- **Task**:
  Create a program that calculates the minimum number of guests that need to be selected by the police, ensuring that for every suspicious event, there is at least one selected guest who was present.

- **Input**:
  - The first line of standard input contains the number of guests M (1 ≤ M ≤ 1000) and the number of suspicious events N (1 ≤ N ≤ 300), separated by a space.
  - The next M lines each contain the arrival time E and departure time T of a guest (1 ≤ E < T ≤ 20,000), in non-decreasing order of their arrival times.
  - The last line contains N positive integers separated by spaces, representing the time of the suspicious events, in increasing order.

- **Output**:
  - The program should output the minimum number of selected guests K in the first line.
  - In the second line, it should output the indices of the selected guests separated by spaces, in any order.
  - If there is no solution, output 0 in the first line.

- **Example**:
  - **Input**:
    ```
    5 4
    1 3
    2 5
    2 8
    3 10
    4 9
    2 5 7 10
    ```
  - **Output**:
    ```
    2
    1 4
    ```

- **Constraints**:
  - The constraints ensure that the computation can be performed within a reasonable time frame.
*/
struct guest
{
    int kezd;
    int veg;
    int index;
};

bool comp(guest &p1, guest &p2)
{
    return p1.kezd < p2.kezd;
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<guest> a(m);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        a[i].kezd = x;
        a[i].veg = y;
        a[i].index = i + 1;
    }
    vector<int> e(n);
    for (int j = 0; j < n; j++)
    {
        cin >> e[j];
    }
    sort(a.begin(), a.end(), comp);
    vector<int> solve;
    int i = 0;
    int j = 0;
    while (i < m && j < n)
    {
        int maxx = -1;
        int ind;
        while (a[i].kezd <= e[j] && i < m)
        {
            if (a[i].veg > maxx)
            {
                maxx = a[i].veg;
                ind = i;
            }
            i++;
        }

        if (maxx == -1)
        {
            cout << 0 << endl;
            return 0;
        }

        solve.push_back(a[ind].index);

        while (maxx >= e[j] && j < n)
        {
            j++;
        }
    }

    if(j<n)
    {
        cout<<0<<endl;
        return 0;
    }

    cout << solve.size() << endl;
    for (int i:solve)
        cout << i << " ";
    return 0;
}
/*
This program solves the problem of selecting the minimum number of guests to serve as witnesses for suspicious events. Here's a step-by-step explanation:

1. **Understanding the Problem**:
   - The program takes input for the number of guests `M`, the number of suspicious events `N`, and the time intervals of guest arrivals and departures.
   - It also takes input for the times of suspicious events.

2. **Approach**:
   - It sorts the guests based on their arrival times in non-decreasing order.
   - It initializes two pointers `i` and `j` to 0.
   - It iterates through the guests and suspicious events using the pointers.
   - While `i` is less than the number of guests `M` and `j` is less than the number of suspicious events `N`, it does the following:
     - It finds the guest who arrived earliest among those who were present during the current suspicious event. It keeps track of the guest with the latest departure time (`maxx`) during that event.
     - If there is no such guest, it means there is no solution, and it outputs 0.
     - Otherwise, it adds the index of the selected guest to the `solve` vector.
     - It then moves the `j` pointer to the next suspicious event that occurs after the current guest's departure time.
   - If `j` is less than `N`, it means there are suspicious events left with no selected guest to witness them, so it outputs 0.
   - Finally, it outputs the number of selected guests and their indices.

3. **Output**:
   - The program outputs the minimum number of selected guests `K` in the first line.
   - In the second line, it outputs the indices of the selected guests separated by spaces, in any order.

4. **Explanation**:
   - The program efficiently selects witnesses for suspicious events by considering the arrival and departure times of guests and iterating through the events.
   - It ensures that each suspicious event has at least one selected guest as a witness.

5. **Time Complexity**:
   - The time complexity of the algorithm is O(M + N) since it processes both guests and suspicious events linearly, where M is the number of guests and N is the number of suspicious events.

This approach effectively finds the minimum number of witnesses needed to cover all suspicious events.
*/