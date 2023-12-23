#include <iostream>
#include <map>

using namespace std;
/*
In the Bergengócia army, candidates are accepted based on successfully passing three tests. However, very few candidates managed to pass all three tests. To give more candidates a chance to complete the three successful tests, an additional test will be held for those who have not yet achieved this feat.

Write a program to determine the candidates who can participate in the fourth test.

Input:

The first line of the standard input contains the number of candidates (N) (1≤N≤100,000).
The next 3*2 lines contain the individuals who passed each of the three tests.
In each pair of lines, the first line contains the number of individuals who passed the test (0≤Pi≤N), and the second line contains the IDs of those Pi individuals who passed the test, listed in increasing order.
Output:

The output should first list the number M of candidates who can participate in the fourth test (i.e., those who have a chance to complete the three successful tests).
The second line should contain the IDs of these M candidates in ascending order.
Example:

Given the number of candidates and the individuals who passed each of the three tests, determine the candidates eligible for the fourth test (and hence the chance to pass all three tests).
Constraints:

Time limit for input processing: 0.1 seconds
Memory limit: 32 MB
*/
int main()
{
    int n;
    map<int, int> m;

    // Step 1: Read the number of candidates (N) and the individuals who passed each test
    cin >> n;

    for (int i = 1; i <= 3; i++)
    {
        int x;
        cin >> x;

        // Step 2: Count the number of individuals who passed each test and their IDs
        for (int j = 1; j <= x; j++)
        {
            int y;
            cin >> y;
            m[y]++;
        }
    }

    int c = 0;

    // Step 3: Count candidates who passed exactly two tests (can participate in the fourth test)
    for (auto i : m)
    {
        if (i.second == 2)
            c++;
    }

    // Step 4: Output the count and IDs of candidates who can participate in the fourth test
    cout << c << endl;
    for (auto i : m)
    {
        if (i.second == 2)
            cout << i.first << " ";
    }

    return 0;
}
/*
Explanation of the Program's Approach:

Input Reading:

The program starts by reading the number of candidates (n).
Counting Passed Candidates:

For each of the three tests, it reads the number of individuals who passed the test (x), and their corresponding IDs. It uses a map to count how many times an ID appears, indicating how many tests a candidate passed.
Count Candidates for the Fourth Test:

It then counts the number of candidates who passed exactly two tests, indicating they can participate in the fourth test.
Output:

Finally, it prints the count of eligible candidates and their IDs who can participate in the fourth test.
The program efficiently determines the candidates who have a chance to complete all three successful tests and hence participate in the fourth test.
*/
