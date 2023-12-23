#include <iostream>
#include <vector>

using namespace std;
/*
The task involves finding the longest alternating subsequence in a given sequence. An alternating subsequence is defined such that for any three consecutive elements a, b, c, either a < b > c or a > b < c.

Input: The input consists of the number of elements in the sequence, N (1≤N≤10,000), and the actual sequence of positive integers.

Output: Output the length of the longest alternating subsequence and provide the indices of the elements that form this subsequence.

Example:

Input:
10
3 2 1 9 2 1 3 6 8 2

Output:
4
1 2 4 6

Explanation:
For the given input, the longest alternating subsequence is [3, 2, 9, 1], and their indices are [1, 2, 4, 6].
*/
void LIS(vector <int> v){
    int lo=1;
    int hi=1;
    vector <int> sol;
    sol.push_back(1);
    for(int i=1; i<v.size(); i++){
        if(v[i]<v[i-1]){
            if(hi!=lo+1){
                sol.push_back(i+1);
            }
            hi = lo + 1;

        } else if(v[i]>v[i-1]){
            if(lo!=hi+1){
                sol.push_back(i+1);
            }
            lo = hi + 1;
        }
    }
    cout<<max(lo,hi)<<endl;
    for(int i:sol){
        cout<<i<<" ";
    }
}


int main()
{
    int n;
    vector<int> v;
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    LIS(v);
    return 0;
}

/*
This program aims to find the longest alternating subsequence in a given sequence. An alternating subsequence is defined such that for any three consecutive elements a, b, c, either a < b > c or a > b < c.

Input:

The input consists of two parts:
The number of elements in the sequence, N (1 ≤ N ≤ 10,000).
The actual sequence of positive integers.
Output:

The program outputs:
The length of the longest alternating subsequence.
The indices of the elements that form this subsequence.
Algorithm and Approach:

Define a function LIS that takes a vector v representing the given sequence as input.

Initialize two variables, lo and hi, both set to 1.

Initialize an empty vector sol to store the indices of the elements that form the longest alternating subsequence.

Iterate through the sequence starting from the second element (index 1):

If the current element is less than the previous element, it's a candidate for the alternating subsequence.
If hi is not equal to lo + 1, push the index of the current element plus 1 into the sol vector.
Update hi to lo + 1.
If the current element is greater than the previous element, it's another candidate for the alternating subsequence.
If lo is not equal to hi + 1, push the index of the current element plus 1 into the sol vector.
Update lo to hi + 1.
Print the maximum of lo and hi as the length of the longest alternating subsequence.

Print the indices stored in the sol vector, representing the longest alternating subsequence.

In the main function:

Read the number of elements in the sequence, n.
Read the actual sequence of positive integers and store them in a vector v.
Call the LIS function with the vector v.
*/
