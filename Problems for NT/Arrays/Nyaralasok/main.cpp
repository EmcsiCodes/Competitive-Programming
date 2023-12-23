#include <iostream>
#include <vector>
using namespace std;

/*
This problem involves selecting three weeks out of N available weeks for vacation, considering a given budget, aiming to spend the budget as accurately as possible.

Here's a detailed explanation of the problem:

Input:

The first line of the input contains two integers: N, the number of weeks (3 ≤ N ≤ 5000), and F, the budget (1 ≤ F ≤ 1,000,000).
The following N lines each contain an integer Ki, representing the cost of a week's vacation (1 ≤ Ki ≤ 1,000,000), in non-decreasing order.
Objective:

The goal is to determine which three weeks to choose for vacation so that the total cost is as close to F as possible without exceeding it.
Output:

The program should output:
The indices of three chosen weeks in increasing order.
If there is no solution, output -1.
Example:

For example, given the costs of vacations for each week and the budget, the program should determine which three weeks to choose to spend the budget as accurately as possible.
Constraints:

The time limit for the program is 0.1 seconds.
The memory limit for the program is 32 MB.
*/

void threeSumClosest(vector<int> v, int p){
    int best=p;
    vector<int> sol={0,0,0};
    if(v[0]>p) cout<<-1;
    for(int i=0; i<v.size()-2; i++){
        int l=i+1,r=v.size()-1;
        if(p-v[i]-v[i+1]-v[i+2]<0) break;
        while(l<r){
            int sum=v[i]+v[l]+v[r];
            if(p-sum<best && sum<=p){
                best=p-sum;
                sol[0]=i+1;
                sol[1]=l+1;
                sol[2]=r+1;
                if(best==0) break;
            }
            if(sum<p){
                l++;
            }
            if(sum>p){
                r--;
            }
        }
    }
    if(sol[0]==0) cout<<-1;
    else cout<<sol[0]<<" "<<sol[1]<<" "<<sol[2]<<endl;
}

int main()
{ 
    int n,p;
    cin>>n>>p;
    vector<int> v;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    threeSumClosest(v,p);
    return 0;
}
/*
Program Explanation:
This program aims to solve a problem where the goal is to determine which three weeks to choose for vacation from a given set of weeks, such that the total cost is as close to a given budget as possible without exceeding it. It uses a three-pointer approach to efficiently find the solution.

Function threeSumClosest:
This function takes a vector of integers v representing the costs of weeks and an integer p representing the budget. It finds the best combination of three weeks that is closest to the budget p without exceeding it.

Initialization:

Initialize best to p, which will store the difference between the chosen vacation cost and the budget.
Initialize a vector sol to store the indices of the three chosen weeks.
Check if the first week's cost exceeds the budget (p), if yes, return -1.
Three-pointer Approach:

Iterate through the vector from the beginning to the third last element.
For each iteration i, set two pointers l and r to i + 1 and n - 1 respectively, where n is the size of the vector.
Use a while loop to find the best combination of three weeks.
Calculate the sum of the costs of weeks at indices i, l, and r.
Update the best solution if this combination is closer to the budget.
Adjust the pointers l and r accordingly to minimize the difference.
Output:

If a valid solution is found (i.e., sol[0] is not zero), output the indices of the chosen three weeks.
If no valid solution is found, output -1.
Main Function:
Read the number of weeks n and the budget p.
Read the costs of each week and store them in a vector v.
Call the function threeSumClosest with the vector v and the budget p.
The program finds and prints the indices of three chosen weeks such that their costs are as close to the budget as possible without exceeding it. If no valid combination is found, it prints -1.
*/