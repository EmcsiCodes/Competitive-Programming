#include <iostream>
#include <unordered_map>

using namespace std;
/*
This problem involves determining the cheapest and most expensive prices of apples
that are sold at the lower and upper markets.

Here's a detailed explanation of the problem:

Input:

The first line of the input contains two integers: N, the number of apple sellers at the lower market, and M, the number of apple sellers at the upper market (1 ≤ N, M ≤ 100).
The second line contains N prices of apples at the lower market.
The third line contains M prices of apples at the upper market.
Prices are integers between 1 and 1000.
Objective:

The goal is to find the cheapest and most expensive prices of apples that are available at both markets.
Output:

The program should output a single line containing the cheapest and most expensive apple prices that can be found at both markets. If no such apples exist, output "0 0".
Example:

For example, given the number of sellers and the respective prices of apples at the lower and upper markets, the program should calculate and output the cheapest and most expensive apple prices available at both markets.
Constraints:

The time limit for the program is 0.1 seconds.
The memory limit for the program is 16 MiB.
*/
int main()
{
    int n, m;
    cin >> n >> m;

    unordered_map<int, int> p1, p2;

    // Read and store the prices of apples at the lower market
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        p1[x] = 1;
    }

    // Read and store the prices of apples at the upper market
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        p2[x] = 1;
    }

    int maxx = 0, minn = 1001;

    // Check prices that are available at both markets and find the cheapest and most expensive
    for (auto it : p1) {
        if (p2[it.first] == 1) {
            maxx = max(maxx, it.first);
            minn = min(minn, it.first);
        }
    }

    if (minn == 1001)
        cout << 0 << " " << 0 << endl;
    else
        cout << minn << " " << maxx;

    return 0;
}

/*
Problem Overview:
The problem requires finding the cheapest and most expensive prices of apples that are available at both the lower and upper markets.

Approach:
The program takes inputs for the number of apple sellers at the lower and upper markets, and the respective prices of apples at these markets. It then processes the prices to find the cheapest and most expensive prices that are common to both markets.

Input Reading:
The program starts by reading the number of apple sellers at the lower market (n) and the number of apple sellers at the upper market (m).

Processing Prices:
The program reads the prices of apples at the lower market and stores them in an unordered map (p1) with the price as the key and a value of 1. It then reads the prices of apples at the upper market and stores them in another unordered map (p2) similarly.

Finding Common Prices:
The program iterates through the prices at the lower market (p1) and checks if a price is also present in the prices at the upper market (p2). If a price is found in both markets, it updates the minimum and maximum prices accordingly.

Output:
Finally, the program outputs the cheapest and most expensive common apple prices. If no such apples exist, it outputs "0 0".

Detailed Explanation:
The program first reads the input values for the number of apple sellers at the lower market (n) and the number of apple sellers at the upper market (m).
It then processes the prices of apples at both markets, storing them in unordered maps (p1 and p2).
The program then iterates through the prices of apples at the lower market and checks if a price is also present at the upper market. If a common price is found, it updates the minimum and maximum prices accordingly.
Finally, it prints the cheapest and most expensive common apple prices, or "0 0" if no common apples exist.
*/
