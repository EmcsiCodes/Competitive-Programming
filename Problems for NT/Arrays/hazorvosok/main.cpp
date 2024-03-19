#include <iostream>
#include <vector>

using namespace std;

/*
Along a road, there are V cities. M general practitioner positions have been advertised in these cities,
and N doctors have applied for these positions.
No one wants to work more than K kilometers away from their place of residence.

Write a program that determines the maximum number of fillable positions!

Input:

The first line of the standard input contains the number of cities (1≤V≤100 000), the number of job positions (1≤M≤100 000), and the number of applicants (1≤N≤100 000).
The second line contains the distance of each city from the first city (1≤LTi≤1 000 000), in ascending order.
The distance of the first city is always 0.
The third line contains the city numbers for the advertised positions (1≤Álli≤V), in ascending order.
The fourth line contains the city numbers for the applicants' places of residence (1≤Laki≤V), in ascending order.
The fifth line contains the distance K (0≤K≤1000).
Output:

The output should be a single line indicating the maximum number of fillable positions.
Example:

Given the number of cities, positions, applicants, distances of cities, advertised position cities, applicant residence cities, and the maximum distance, determine the maximum number of fillable positions.
Constraints:

Time limit for input processing: 0.1 seconds
Memory limit: 32 MB
In 50% of the tests, N≤100.
*/

int main()
{
    int n, m, k, v_num;
    vector<int> v, people, store;
    cin >> v_num >> m >> n;
    for (int i = 0; i < v_num; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        store.push_back(v[x - 1]);
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        people.push_back(v[x - 1]);
    }
    cin >> k;
    int count = 0;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (people[i] >= store[j] - k && people[i] <= store[j] + k)
        {
            count++;
            i++;
            j++;
        }
        else if (people[i] < store[j] - k)
            i++;
        else
            j++;
    }
    cout << count << endl;
    return 0;
}
/*
Problem Overview:
The problem involves determining the maximum number of fillable positions for general practitioners in various cities based on their locations and the applicants' residence cities.

Approach:
Input Reading:
The program starts by reading the number of cities (v_num), the number of job positions (m), the number of applicants (n), and the distances of cities from the first city. It also reads the advertised position cities (store), the applicant residence cities (people), and the maximum distance allowed (k).

Position and Applicant Matching:
The program iterates through the positions and applicants, checking if the distance between a position and an applicant is within the allowed maximum distance (k). If it is, a fillable position is found, and the count is incremented.

Output:
The program prints the count, indicating the maximum number of fillable positions.

Detailed Explanation:
The program reads the input data, including city distances, advertised positions, applicant residence cities, and the maximum distance. It then iterates through the positions and applicants, comparing their distances with the allowed maximum distance (k). If a position and an applicant are within the allowed distance, it's considered a fillable position, and the count is incremented.

Conclusion:
The program effectively determines the maximum number of fillable positions based on the given conditions, efficiently utilizing the provided information about cities, positions, and applicants. It adheres to the problem's constraints to provide a valid solution.
*/