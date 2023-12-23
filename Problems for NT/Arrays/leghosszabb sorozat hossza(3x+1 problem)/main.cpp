#include <iostream>

using namespace std;

/*
The task involves generating a sequence of positive numbers starting from a given N using a specific rule: if the current number is even, the next number is obtained by dividing the current number by 2; if the current number is odd, the next number is obtained by multiplying the current number by 3 and adding 1. The sequence always ends with 1.

The objective is to find the length of the longest sequence where every element is less than or equal to a given value K.

Input: The input consists of a value K (1≤K≤1,000,000).

Output: Output the length of the longest sequence where every element is less than or equal to K.

Example:

Input:
16

Output:
10

Explanation:
For the given input, the longest sequence with elements less than or equal to 16 is: 12 6 3 10 5 16 8 4 2 1.
*/

int best = 1;

// Function to solve the problem recursively
void solve(int n, int k, int count) {
    if (n <= k && n != 1) {
        double p = double(double(n - 1) / 3);
        if (int(p) == p) {
            solve(int(p), k, count + 1);
        }
        solve(n * 2, k, count + 1);
    } else
        best = max(best, count);
}

int main() {
    int k;
    cin >> k;
    solve(2, k, 1);
    cout << best;
    return 0;
}
/*
This program calculates the length of the longest sequence generated using the given rule, where each element in the sequence is less than or equal to a given value K.

Input:

The input consists of a single integer K (1 ≤ K ≤ 1,000,000) representing the maximum value allowed in the sequence.
Output:

The program outputs an integer representing the length of the longest sequence where every element is less than or equal to K.
Algorithm and Approach:

Initialize a global variable best to 1. This variable will store the length of the longest sequence found.

Define a recursive function solve with three parameters:

n: the current number in the sequence.
k: the maximum value allowed in the sequence.
count: the length of the current sequence.
Inside the solve function, check if n is less than or equal to k and not equal to 1. If both conditions are met, proceed to the next steps; otherwise, return from the function.

Check if (n - 1) / 3 is an integer (i.e., (n - 1) / 3 has no fractional part). If it is, recursively call the solve function with the new value int((n - 1) / 3) as n, keeping k and incrementing count by 1.

Recursively call the solve function with the new value n * 2 as n, keeping k and incrementing count by 1.

In each recursive step, compare the current count with the global best and update best to the maximum of the two values.

In the main function, read the input value k.

Start the sequence with the initial number 2 and call the solve function with 2, k, and an initial count of 1.

Finally, output the value of best as the length of the longest sequence.
*/