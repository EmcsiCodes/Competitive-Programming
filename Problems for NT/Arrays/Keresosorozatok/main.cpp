#include <iostream>
#include <vector>
using namespace std;

/*
A binary search tree is a data structure where for every node, all elements to the left are smaller, and all elements to the right are larger. An element can be efficiently found in such a data structure by starting from the root and utilizing the property of the search tree to determine whether to continue the search in the left or right subtree.

A search sequence is the listing of elements that are examined during the search for a particular element.

Create a program that determines if a given sequence is a possible search sequence for a binary search tree.

Input:

The first line of the standard input contains the number of sequences (1≤K≤100).
The next K lines provide the sequences: the first number is the length of the sequence (1≤Hi≤1000), followed by Hi numbers which represent the sequence elements (1≤Si,j≤1 000 000).
Output:

Output K lines, where each line contains either "IGEN" (YES) if the corresponding sequence can be a search sequence, or "NEM" (NO) if it cannot.
Example:

Given a number of sequences and the sequences themselves, determine if each sequence is a possible search sequence for a binary search tree.
Constraints:

Time limit for input processing: 0.2 seconds
Memory limit: 32 MB
*/

bool searchTree(vector<int> v) {
    if (v.size() < 3) return true;

    int hi = 1000001, lo = 0, mid = v[1];

    if (mid > v[0]) {
        lo = v[0];
    } else {
        hi = v[0];
    }

    for (int i = 2; i < v.size(); i++) {
        if (v[i] > mid && v[i] < hi) {
            lo = mid;
            mid = v[i];
            continue;
        }

        if (v[i] < mid && v[i] > lo) {
            hi = mid;
            mid = v[i];
            continue;
        }

        return false;
    }

    return true;
}

int main() {
    int k;
    cin >> k;
    vector<bool> sol;

    for (int i = 1; i <= k; i++) {
        int n;
        cin >> n;
        vector<int> v;

        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            v.push_back(x);
        }

        if (searchTree(v)) sol.push_back(true);
        else sol.push_back(false);
    }

    for (auto i : sol) {
        if (i) cout << "IGEN" << endl;
        else cout << "NEM" << endl;
    }

    return 0;
}
/*Problem Overview:
The problem requires determining if a given sequence can be a possible search sequence for a binary search tree.

Approach:
Input Reading:
The program starts by reading the number of sequences (k). Then, for each sequence, it reads the length of the sequence (n) and the elements of the sequence.

Searching in a BST:
The searchTree function checks whether a given sequence is a valid search sequence for a binary search tree. It iterates through the sequence and verifies if the sequence follows the properties of a binary search tree, where for every node, all elements to the left are smaller, and all elements to the right are larger.

Output:
The program calls the searchTree function for each sequence and prints "IGEN" if the sequence can be a search sequence or "NEM" if it cannot.

Detailed Explanation:
The searchTree function performs a binary search tree property check on the given sequence. It iterates through the sequence elements, maintaining the lo, mid, and hi pointers to ensure that each element follows the binary search tree properties.

Conclusion:
The program effectively determines whether a given sequence can be a search sequence for a binary search tree. It efficiently processes the input data and utilizes a function to validate the binary search tree property.
*/




