// Section 2 Question 2
// Binary Exponentiation

// Implementing Binary Exponentiation Algorithm to find the 
// nth power of any integer a in the most time efficient way.

// Input format:
// t : number of test cases
// a, n : integers, to find a^n

// Output format:
// m : Number of multiplications done to obtain the power

// Can be downloaded from the git repository: 
// https://github.com/PixlatedBatman/ProgrammingClub-Coordinator-Application

#include <bits/stdc++.h>
#define llt long long int
#define vllt vector<llt>
#define pb push_back        // Defined for easy and quick writing
#define mp make_pair
#define endl "\n"
using namespace std;

llt m=0;        // Global variable for finding number of multiplications

llt Sqr(llt a){                 // Function for squaring a number
    return a*a;
}

llt Mul(llt a, llt n){          // Function to implement Binary Exponentiation
    if(n==0) return 1;     
    if(n==1) return a;          // Termination points for recursion

    if(n%2 == 1){
        m+=2;                   // 2 multiplications : One for squaring and other for multiplying a
        return Sqr(Mul(a, n/2))*a;
    }
    else{
        m++;                    // 1 multiplication : Squaring
        return Sqr(Mul(a, n/2));
    }
}

llt Manual(llt n){
    m=0;
    while(n>1){                 // This function is made to calculate number
        if(n%2==1) n--;         // of multiplications manually
        else n /= 2;
        m++;
    }
    return m;
}

void Main(){
    llt a, n, power;
    cin >> a >> n;

    m=0;
    //cout << Mul(a, n) << endl;    // If the actual power was to be output
    
    power = Mul(a, n);              // Running the function
    cout << m << endl;              // Giving m as output

    cout << Manual(n) << endl;      // Giving number of multiplications by manual method
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t; while(t--) Main();     // Running for t times
    return 0;
}
