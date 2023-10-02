#include <iostream>
#include <vector>
using namespace std;

/*
You are on the side of the river. You are given a m liter jug and a n liter jug where 0 < m < n. Both the jugs are initially empty. The jugs don’t have markings to allow measuring smaller quantities. You have to use the jugs to measure d liters of water where d < n. Determine the minimum no of operations to be performed to obtain d liters of water in one of jug. 
The operations you can perform are: 

Empty a Jug
Fill a Jug
Pour water from one jug to the other until one of the jugs is either empty or full.
*/

// Function to calculate the greatest common divisor
int greatestCommonDiviser(int n, int m) {
    if (m == 0) return n;
    return greatestCommonDiviser(m, n % m);
}

// Function to pour water from jug A to jug B
vector<string> pourAB(int fromCap, int toCap, int d) {
    int from = fromCap;
    int to = 0;
    vector<string> res;
    res.push_back("fromFill");

    while (from != d && to != d) {
        int pourCap = min(from, toCap - to);
        to += pourCap;
        from -= pourCap;
        res.push_back("fromTo");

        if (from == d || to == d) {
            if (from == d && to != d) {
                res.push_back("toClear");
                res.push_back("fromFill");
            }
            break;
        }

        if (from == 0) {
            from = fromCap;
            res.push_back("fromFill");
        }

        if (to == toCap) {
            to = 0;
            res.push_back("toClear");
        }
    }

    return res;
}

// Function to pour water from jug B to jug A
vector<string> pourBA(int fromCap, int toCap, int d) {
    int from = fromCap;
    int to = 0;
    vector<string> res;
    res.push_back("fromFill");

    while (from != d && to != d) {
        int pourCap = min(from, toCap - to);
        to += pourCap;
        from -= pourCap;
        res.push_back("fromTo");

        if (from == d || to == d) {
            if (to == d && from != d) {
                res.push_back("toClear");
                res.push_back("fromFill");
            }
            break;
        }

        if (from == 0) {
            from = fromCap;
            res.push_back("fromFill");
        }

        if (to == toCap) {
            to = 0;
            res.push_back("toClear");
        }
    }

    return res;
}

// Function to calculate the minimum number of operations
void twoJug(int n, int m, int d) {
    if ((d > n && d > m) || d % greatestCommonDiviser(n, m) != 0) {
        cout << "NINCS";
        return;
    }

    vector<string> res1, res2, res;
    res1 = pourAB(n, m, d);
    res2 = pourBA(m, n, d);

    if (res1.size() < res2.size()) {
        for (auto i : res1) {
            if (i == "fromFill") {
                res.push_back("TA");
                continue;
            }
            if (i == "fromTo") {
                res.push_back("AB");
                continue;
            }
            if (i == "toClear") {
                res.push_back("UB");
                continue;
            }
        }

        cout << res.size() << '\n';
        for (auto i : res) {
            cout << i << '\n';
        }

        return;
    } else {
        for (auto i : res2) {
            if (i == "fromFill") {
                res.push_back("TB");
                continue;
            }
            if (i == "fromTo") {
                res.push_back("BA");
                continue;
            }
            if (i == "toClear") {
                res.push_back("UA");
                continue;
            }
        }

        cout << res.size() << '\n';
        for (auto i : res) {
            cout << i << '\n';
        }
    }
}

int main() {
    int d, n, m;
    cin >> d >> n >> m;
    twoJug(n, m, d);
    return 0;
}
/*
Problem Overview:
The problem is about finding the minimum number of operations required to measure a specific amount of water using two jugs of different capacities.

Approach:
The program implements two functions pourAB and pourBA to simulate pouring water from one jug to another. It calculates the minimum operations needed to achieve the desired amount of water using two jugs.

Input Reading:
The program starts by reading three integers d, n, and m, where d is the desired amount of water to be measured, and n and m are the capacities of the two jugs.

Pouring Water Simulations:
The functions pourAB and pourBA simulate pouring water from one jug to another until the desired amount d is achieved.

Greatest Common Divisor Check:
It checks if the desired amount d is achievable based on the greatest common divisor of the jug capacities.

Output:
The program then outputs the sequence of operations to achieve the desired amount of water in one of the jugs.

Detailed Explanation:
The pourAB and pourBA functions simulate the pouring of water from one jug to another while keeping track of the steps involved.
The twoJug function calculates the minimum operations needed to achieve the desired amount of water using the two jugs.
It checks if the desired amount is achievable based on the greatest common divisor of the jug capacities.
Conclusion:
The program effectively determines the minimum number of operations required to measure a specific amount of water using two jugs of different capacities. It employs pouring simulations and considers the greatest common divisor of jug capacities to achieve the desired amount.
*/