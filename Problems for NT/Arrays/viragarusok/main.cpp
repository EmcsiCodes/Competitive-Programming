#include <iostream>
#include <unordered_map>
using namespace std;
/*
In this problem, a class is planning to decorate the school's dance hall with flowers for a special event. They have determined how many of each type of flower they need. There are two flower vendors nearby from whom they can purchase flowers. Both vendors have specific quantities of different types of flowers in their shops. The class needs to decide which vendor to choose in order to minimize the number of missing flowers for their decoration.

Write a program that determines which vendor to buy the flowers from in order to minimize the number of missing flowers compared to their plan.

Input:

The first line of the input contains the number of flower types they plan to buy (1 ≤ N ≤ 10,000).
The next N lines contain the name of each flower type and the quantity they need (in alphabetical order).
The following line specifies the number of flower types available at the first vendor (1 ≤ A1 ≤ 10,000).
The next A1 lines describe the types of flowers available at the first vendor, along with the quantity they have (in alphabetical order).
The final group specifies the number of flower types available at the second vendor (1 ≤ A2 ≤ 10,000).
The next A2 lines describe the types of flowers available at the second vendor, along with the quantity they have (in alphabetical order).
Output:

The program should output the vendor number from whom they should buy the flowers (if there are multiple correct answers, any valid answer is acceptable).
The second line should specify the minimum number of flowers that will be missing from their plan if they follow this vendor's inventory.
Example:

Input:
3
ibolya 5
kankalin 2
orgona 3
4
ibolya 4
kankalin 1
liliom 20
orgona 2
3
amarillisz 3
kankalin 2
orgona 3
1
3

Output:
2
3

Explanation: In this example, choosing the second vendor (2) results in a total of 3 missing flowers, which is the minimum number of missing flowers they can achieve.

Constraints:

Time limit: 0.2 seconds
Memory limit: 32 MB
*/
unordered_map<string,int> flowers,seller1,seller2;
void be(){    
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        string flower;
        int flower_num;
        cin>>flower>>flower_num;
        flowers[flower]=flower_num;
    }
    cin>>n;
    for(int i=1; i<=n; i++){
        string flower;
        int flower_num;
        cin>>flower>>flower_num;
        seller1[flower]=flower_num;
    }
    cin>>n;
    for(int i=1; i<=n; i++){
        string flower;
        int flower_num;
        cin>>flower>>flower_num;
        seller2[flower]=flower_num;
    }
}

int main()
{
    be();
    int sol1=0;
    for(auto i:flowers){
        int c = i.second;
        if(seller1.find(i.first)!=seller1.end()){
            c -= seller1[i.first];
            if(c<0) c = 0;
        }
        sol1 += c;
    }
    int sol2 = 0;
    for(auto i:flowers){
        int c = i.second;
        if(seller2.find(i.first)!=seller2.end()){
            c -= seller2[i.first];
            if(c<0) c = 0;
        }
        sol2 += c;
    }
    if(sol1<sol2) cout<<1<<endl<<sol1;
    else cout<<2<<endl<<sol2;
    return 0;
}
/*
Program Explanation:
The program aims to minimize the number of missing flowers for decorating the school's dance hall. It does this by comparing the quantities of flowers needed (from the flowers map) with the quantities available from two vendors (seller1 and seller2). The program follows these steps:

Input Processing:

The program reads the input data and extracts the quantities of flowers needed and the available quantities for each type of flower at both vendors.
Calculating Missing Flowers:

For each type of flower needed:
It calculates the difference between the required quantity and the quantity available at the first vendor (seller1).
It calculates the difference between the required quantity and the quantity available at the second vendor (seller2).
If the available quantity is greater than or equal to the required quantity, the difference is zero; otherwise, it's the required quantity minus the available quantity.
The program accumulates the missing flowers for each vendor.
Determining the Optimal Vendor:

After calculating the missing flowers for both vendors, the program compares these totals.
It selects the vendor that results in the minimum missing flowers.
If both vendors have the same number of missing flowers, it doesn't matter which vendor is chosen, so the program can output either vendor (1 or 2).
Outputting the Result:

The program outputs the selected vendor number (1 or 2) and the corresponding minimum missing flowers.
How and Why the Program Works:
The program works by carefully calculating and comparing the missing flowers for each vendor, ensuring that the required quantities for each type of flower are met as closely as possible.

It starts by processing the input data and creating maps for the quantities needed and available at each vendor.

For each type of flower needed, the program calculates how many more of that flower type are required to meet the needs. If the vendor has more than enough of a particular flower, the difference is zero; otherwise, it's the quantity needed minus the quantity available.

By iterating through all the flower types, the program accumulates the total missing flowers for each vendor.

Finally, it compares the total missing flowers for both vendors and selects the vendor with the minimum missing flowers as the optimal choice. If both vendors have the same number of missing flowers, it outputs either vendor as the solution.

This approach effectively minimizes the number of missing flowers for decorating the dance hall by considering the availability of each type of flower at both vendors and making the best possible choice.
*/