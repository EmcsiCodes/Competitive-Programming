#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Along a road, there are N people who want to engage in watermelon selling.
M watermelon selling spots have been designated along the road.
Each person can sell watermelons at only one spot, and each spot can have only one watermelon seller.
Nobody wants to work more than K kilometers away from their home.

Write a program that determines the maximum number of people who can go to sell watermelons under these conditions.

Input:

The first line of the standard input contains the number of people (N) (1≤N≤100,000).
The second line contains the distances of individual people from the starting point of the road (1≤LTi≤1,000,000), in increasing order.
The third line contains the number of watermelon selling spots (M) (2≤M≤100,000).
The fourth line contains the distances of the individual watermelon selling spots from the starting point of the road (1≤HTi≤1,000,000), in increasing order.
The fifth line contains the distance K (0≤K≤1000).
Output:

The output should indicate the maximum number of people who can go to sell watermelons under these conditions.
Example:

Given the number of people, their distances from the starting point of the road, the number of watermelon selling spots, the distances of the spots, and the maximum distance allowed, determine the maximum number of people who can sell watermelons.
Constraints:

Time limit for input processing: 0.1 seconds
Memory limit: 32 MB
In 50% of the tests, N≤100.
*/
int main()
{
    int n, m, k;
    vector<int> people, store;
    cin >> n;

    // Step 1: Read distances of individual people from the starting point
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        people.push_back(x);
    }

    cin >> m;

    // Step 2: Read distances of individual watermelon selling spots from the starting point
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        store.push_back(x);
    }

    cin >> k;

    int count = 0;
    int i = 0, j = 0;

    // Step 3: Compare distances to determine the maximum number of people who can sell watermelons
    while (i < n && j < m)
    {
        if (people[i] >= store[j] - k && people[i] <= store[j] + k)
        {
            count++;
            i++;
            j++;
        }
        else if (people[i] < store[j] - k)
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    // Step 4: Output the maximum number of people who can sell watermelons
    cout << count;
}
/*
Explanation of the Program's Approach:

Input Reading:

The program starts by reading the number of people (n).
Read People's Distances:

For each person, it reads the distance from the starting point of the road and stores these distances in the people vector.
Read Watermelon Selling Spots and Compare Distances:

It then reads the number of watermelon selling spots (m) and their distances from the starting point, storing them in the store vector.
The program compares the distances of people and selling spots to determine the maximum number of people who can sell watermelons within a certain distance k from their homes.
Comparing Distances:

It uses a while loop to compare the distances.
If a person's distance falls within the range of a selling spot (within k kilometers), it increments the count of people who can sell watermelons and moves to the next person and selling spot.
If a person's distance is less than the lower range of a selling spot, it moves to the next person.
If a person's distance is greater than the upper range of a selling spot, it moves to the next selling spot.
Output:

Finally, the program outputs the maximum number of people who can sell watermelons within the specified distance k.
The program efficiently determines the maximum number of people who can sell watermelons based on the given conditions and constraints.
*/