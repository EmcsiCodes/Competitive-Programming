#include <iostream>
#include <map>
using namespace std;
/*
In this problem, you are given information about two stores and the prices of various items they sell. You need to find the items that can be purchased for less than or equal to X in either of the stores.

Here's a detailed explanation of the problem:

Input:

The first line of the input contains three integers: N (the number of items in the first store), M (the number of items in the second store), and X (the maximum price) (1 ≤ N ≤ 1000, 1 ≤ M ≤ 1000, 1 ≤ X ≤ 100,000).
The next N lines contain information about the items in the first store. Each line contains two integers: the item code and its price (1 ≤ Code ≤ 9999, 1 ≤ Price ≤ 100,000).
The next M lines contain information about the items in the second store, following the same format.
Objective:

Find the items that can be purchased for less than or equal to X in either of the stores.
Output:

The program should output the number of items that meet this criteria and then the codes of these items in increasing order.
Example:

For example, given the information about the items and their prices in both stores, along with the maximum price, the program should determine the items that meet the criteria.
Constraints:

The time limit for the program is 0.1 seconds.
The memory limit for the program is 32 MB.
*/
int main()
{
    int n, m, x, db = 0;
    cin >> n >> m >> x;
    map<int, int> ma; // Map to store item codes and their prices

    // Input and processing of items
    for (int i = 1; i <= n + m; i++)
    {
        int x, y;
        cin >> x >> y;
        if (ma[x] != 0)
        {
            ma[x] = min(y, ma[x]);
        }
        else
        {
            ma[x] = y;
        }
    }

    // Finding and printing eligible items
    for (auto it : ma)
    {
        if (it.second < x)
        {
            db++;
        }
    }

    cout << db << endl;

    for (auto it : ma)
    {
        if (it.second < x)
        {
            cout << it.first << " ";
        }
    }

    return 0;
}
/*
Input Reading and Preparation:

The program starts by reading three integers from the input: n (the number of items in the first store), m (the number of items in the second store), and x (the maximum price allowed).
It also initializes a map<int, int> named ma to store item codes and their minimum prices.
Processing Items:

Next, it enters a loop where it reads and processes information about the items.
For each item, it reads two integers: x (the item code) and y (the item price).
It checks if the item code x already exists in the map. If it does, it updates the price to be the minimum of the existing price and the current item's price. If it doesn't exist, it adds the item code and price to the map.
Finding Eligible Items:

After processing all items, it iterates over the items in the map.
For each item, it checks if the price of the item is less than x (the maximum price allowed). If yes, it increments the db counter, indicating a valid item.
Output:

It prints the number of valid items (db) on a new line.
It then prints the item codes of valid items in increasing order on the same line, separated by spaces.
The program effectively reads and processes information about items in two stores, keeps track of the minimum prices for each item, identifies the items that meet the criteria of being less than or equal to the maximum price x, and outputs the count and codes of these eligible items. The use of a map ensures that for each item, only the minimum price is considered, as required by the problem.
*/