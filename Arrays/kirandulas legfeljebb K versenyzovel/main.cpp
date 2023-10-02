#include <iostream>
#include <set>
#include <vector>
using namespace std;
/*
This problem involves organizing a field trip for a maximum of K participants based on the results of academic competitions held in various subjects.

Here's a detailed explanation of the problem:

Input:

The first line of the input contains three integers: T (1 ≤ T ≤ 10) representing the number of academic competitions, N (1 ≤ N ≤ 1000) representing the total number of students, and K (T ≤ K ≤ N) representing the maximum number of participants for the field trip.
The following T lines each describe the results of a competition. Each line contains:
Indi (1 ≤ Indi ≤ N), the number of participants in the competition.
Indi space-separated numbers representing the order in which the students participated in the competition.
Objective:

The goal is to determine the students eligible for the field trip based on the competition results.
The number of eligible students should not exceed K.
Output:

The program should output:
The number of students eligible for the field trip (at most K).
The list of eligible students' numbers in ascending order.
Example:

For example, given three academic competitions and the respective results, the program should determine the eligible students for the field trip considering the specified constraints.
Constraints:

The time limit for the program is 0.1 seconds.
The memory limit for the program is 32 MB.
In 33% of the tests, T = 2.
*/
int main()
{
    int t, n, k;
    cin >> t >> n >> k;
    int u = n;  // u is initialized to the total number of students n
    vector<vector<int>> vec;  // vector to store competition results

    // Input competition results
    for (int i = 0; i < t; i++) {
        int x;
        cin >> x;
        vector<int> v;
        u = min(u, x);  // Update the minimum of u and x
        for (int j = 0; j < x; j++) {
            int y;
            cin >> y;
            v.push_back(y);
        }
        vec.push_back(v);
    }

    set<int> s, s1;  // Sets to store eligible students

    // Iterate through the students in each competition
    for (int i = 0; i < u; i++) {
        for (int j = 0; j < vec.size(); j++) {
            s1.insert(vec[j][i]);  // Insert students into temporary set
        }
        if (s1.size() + s.size() <= k) {
            // If the total number of students doesn't exceed the limit K, add them to the final set
            for (auto it = s1.begin(); it != s1.end(); it++)
                s.insert(*it);
            s1.clear();
        } else
            break;
    }

    // Output the number of eligible students and their numbers
    cout << s.size() << endl;
    for (auto it = s.begin(); it != s.end(); it++)
        cout << *it << " ";

    return 0;
}
/*
Problem Overview:
The problem involves organizing a field trip for a maximum of K participants based on the results of academic competitions held in various subjects. Each academic competition yields a list of participants, and the objective is to select at most K students who participated in each competition, ensuring they don't exceed the total limit of K.

Approach:
The program takes inputs for the number of academic competitions, the total number of students, and the maximum number of participants for the field trip. It then processes the competition results to find the eligible students for the trip.

Input Reading:
The program starts by reading the number of academic competitions (t), the total number of students (n), and the maximum participants allowed (k).

Processing Competition Results:
The program reads the competition results, which are the order of students who participated in each competition. It iterates through the participants in each competition and selects the eligible students based on the maximum allowed.

Output:
Finally, the program outputs the number of eligible students and their respective student numbers in ascending order.

Detailed Explanation:
The program first reads the input values for the number of academic competitions, the total number of students, and the maximum participants for the field trip.
It then processes the competition results, storing them in a vector of vectors, where each vector represents a competition and contains the student numbers.
The program uses sets to keep track of the eligible students, ensuring that each student is only considered once and the set properties ensure uniqueness.
For each competition, it inserts the students into a temporary set and checks if adding these students to the final set keeps the total count within the maximum allowed (K). If it does, it adds them to the final set.
Finally, it prints the count of eligible students and their numbers in ascending order.
*/
