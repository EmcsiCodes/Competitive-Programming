#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;
/*
This problem involves calculating the maximum quantity of each product that can be purchased under two conditions: A) from one store only, and B) from both stores.

Here's a detailed explanation of the problem:

Input:

The first line of the input contains two integers: N, the number of products in the first store (1 ≤ N ≤ 10,000), and M, the number of products in the second store (1 ≤ M ≤ 10,000).
The following N lines each describe a product in the first store. Each line contains:
The product code (up to a 12-digit integer).
The product inventory in the first store (1 ≤ A ≤ 1000).
The following M lines each describe a product in the second store. Each line contains:
The product code (up to a 12-digit integer).
The product inventory in the second store (1 ≤ A ≤ 1000).
Objective:

The goal is to determine the maximum quantity of each product that can be purchased under the specified conditions.
Output:

The program should output:
The maximum quantity of each product that can be purchased from one store only (A).
The maximum quantity of each product that can be purchased from both stores (B).
The product codes and the corresponding quantities in ascending order of the product code.
Example:

For example, given the inventory of products in both stores, the program should determine the maximum quantity of each product that can be purchased according to the specified conditions.
Constraints:

The time limit for the program is 0.1 seconds.
The memory limit for the program is 32 MB.
*/
int main()
{
    int n, m;
    cin >> n >> m;
    set<long long> s;  // Set to store unique product codes
    unordered_map<long long, int> u1, u2;  // Maps to store product code and quantity pairs for the first and second stores

    // Input for the first store products
    for (int i = 1; i <= n; i++) {
        long long x;
        int y;
        cin >> x >> y;
        u1[x] = y;  // Store product code and quantity in the first store
        s.insert(x);  // Add the product code to the set
    }

    // Input for the second store products
    for (int i = 1; i <= m; i++) {
        long long x;
        int y;
        cin >> x >> y;
        u2[x] = y;  // Store product code and quantity in the second store
        s.insert(x);  // Add the product code to the set
    }

    // Output the maximum quantity for each product for both conditions
    for (auto it : s) {
        cout << max(u1[it], u2[it]) << " ";  // Maximum quantity from one store
    }
    cout << endl;

    for (auto it : s) {
        cout << u1[it] + u2[it] << " ";  // Maximum quantity from both stores
    }

    return 0;
}
/*
Problem Overview:
The problem involves calculating the maximum quantity of each product that can be purchased under two conditions: purchasing from one store only and purchasing from both stores.

Approach:
The program follows these steps to determine the maximum quantity of each product:

Input Reading:

Read the number of products in the first store (N) and the number of products in the second store (M).
Read the product codes and corresponding inventories for each store, storing them in appropriate data structures.
Finding Unique Product Codes:

Use a set (s) to store unique product codes from both stores.
Calculating Maximum Quantity:

Iterate through the set of product codes.
For each product code, calculate the maximum quantity that can be purchased from one store and from both stores.
Output the maximum quantities for each product code.
Detailed Explanation:
The program uses sets and maps to keep track of unique product codes and their quantities in each store.
For each product, it calculates the maximum quantity that can be purchased from one store and from both stores, using the max() function.
The output displays the maximum quantities for each product in the order of product codes.
*/
