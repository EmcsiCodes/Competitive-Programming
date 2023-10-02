#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;
/*
We are given the products sold by two fruit merchants. Create a program that determines the fruits that are available at only one of the two merchants.

Input:

The first line of the standard input contains the number of fruits sold by the first merchant (1≤N≤1000).
The next N lines each contain the name of a fruit sold by the first merchant (written in lowercase English alphabet), in alphabetical order.
The following line contains the number of fruits sold by the second merchant (1≤M≤1000).
This is followed by M lines, each containing the name of a fruit sold by the second merchant (written in lowercase English alphabet), in alphabetical order. If a merchant sells multiple varieties of a fruit, the name appears multiple times in the input.
Output:

The output should start with a line containing the number of fruits (K) available at only one of the two merchants.
This is followed by K lines, each containing the name of a fruit that is available at only one of the two merchants, in alphabetical order. Each fruit name should only appear once.
Example:

Given the number of fruits, their names, and the merchants they are sold by, determine the fruits that are available at only one of the two merchants.
Constraints:

Time limit for input processing: 0.2 seconds
Memory limit: 32 MB
*/
int main()
{
    int n, m;
    unordered_map<string, int> fruits;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        fruits[s] = 1;
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        string s;
        cin >> s;
        if (fruits[s] != 1)
            fruits[s] = 1;
        else
            fruits[s] = 0;
    }
    set<string> fruits_sol;
    for (auto i : fruits)
    {
        if (i.second == 1)
            fruits_sol.insert(i.first);
    }
    cout << fruits_sol.size() << endl;
    for (auto i : fruits_sol)
    {
        cout << i << " ";
    }
    return 0;
}
/*
Problem Overview:
The problem requires finding fruits that are available at only one of the two merchants given the fruits they sell.

Approach:
Input Reading:
The program starts by reading the number of fruits (n), followed by the names of fruits sold by the first merchant. It then reads the number of fruits sold by the second merchant (m), followed by the names of fruits sold by the second merchant.

Fruit Tracking:
The program uses an unordered_map to track the occurrence of fruits. Initially, all fruits from the first merchant are added to the map with a value of 1 (indicating they are from the first merchant). When reading fruits from the second merchant, if the fruit is already present (indicating it's from the first merchant), its value is set to 0, indicating it's available at both merchants.

Identifying Unique Fruits:
After processing both merchants, the program creates a set called fruits_sol to identify fruits that are unique to one of the merchants (i.e., the ones with a value of 1 in the map).

Output:
The program prints the count of unique fruits and then the names of these fruits in alphabetical order.

Detailed Explanation:
The program reads and processes the fruits sold by both merchants, tracking which fruits are available in both and which are unique to a particular merchant. It then prints the count and names of unique fruits.

Conclusion:
The program effectively identifies the fruits available at only one of the two merchants, providing a solution to the problem. It efficiently processes the input data and utilizes appropriate data structures to track and display the desired information.
*/