#include <iostream>
#include <vector>
using namespace std;

/*
Summary of the Programming Problem "Sequence Halving":

In a game, the number of elements in a sequence is a power of two. In each step, you can halve the sequence and discard one of the halves.

Write a program to determine the minimum number of halvings required so that the remaining sequence consists of identical numbers and what is the value of these numbers. If the sequence already consists of identical numbers, it can be solved in 0 steps.

Input:

The first line of the standard input contains the number of elements in the sequence (1≤N≤220).
The next line contains the elements of the sequence (1≤Si≤100).

Output:

The output should first indicate the minimum number of halvings needed to keep the remaining sequence consisting of identical values.
The second line should contain any element from such a sequence (since there can be multiple valid outputs).

Example:

Given the number of elements in the sequence and the sequence itself, determine the minimum number of halvings required to achieve a sequence consisting of identical elements and one such element.

Constraints:

Time limit for input processing: 0.15 seconds
Memory limit: 32 MB
*/

int p;

// Function to check if a specific pattern of elements exists in the sequence
bool found(int n, vector<int> v)
{
    int j = 0;
    while (j < v.size())
    {
        p = v[j];
        bool curr = true;
        for (int i = j; i <= j + n - 1; i++)
        {
            if (v[i] != p)
            {
                curr = false;
                break;
            }
        }
        j += n;
        if (curr)
            return true;
    }
    return false;
}

int main()
{
    int n, x;
    vector<int> v;
    bool first = true;

    // Step 1: Read the number of elements in the sequence and the sequence itself
    cin >> n >> x;
    v.push_back(x);

    for (int i = 1; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
        if (v[i] != v[i - 1])
            first = false;
    }

    // Step 2: If the sequence already consists of identical numbers, print 0 steps
    if (first)
        cout << 0 << endl << v[0];
    else
    {
        // Step 3: Determine the minimum number of halvings needed
        int res = 1;
        n = n / 2;
        while (!found(n, v))
        {
            res++;
            n = n / 2;
        }

        // Step 4: Output the minimum number of halvings and one such element from the sequence
        cout << res << '\n' << p;
    }

    return 0;
}
/*
Reading Input:

The program begins by reading the input, including the number of elements in the sequence (n) and the elements themselves.
Checking for Identical Sequence:

It first checks if the sequence already consists of identical numbers (i.e., all elements are the same). If this is the case, it prints 0 steps needed and outputs any element from the sequence. This is because no further halvings are required if all elements are the same.
Finding Minimum Halvings:

If the sequence has different elements, it needs to determine the minimum number of halvings required to get a sequence with identical elements.
It starts by attempting to find a pattern in the sequence by halving it. It tries halving the sequence in half, then in quarters, then in eighths, and so on, checking if the remaining sequence consists of identical numbers after each halving.
It uses a function found to check if a specific pattern of elements exists in the sequence. It iterates through the sequence, checking if elements repeat in a specific pattern.
Outputting Results:

Once it finds the minimum number of halvings needed (denoted by res) and a suitable element from such a sequence (denoted by p), it outputs this information.
In summary, the program determines the minimum number of halvings required to obtain a sequence consisting of identical elements by iteratively halving the sequence and checking for patterns. If the sequence already has identical elements, it outputs the solution directly.
*/