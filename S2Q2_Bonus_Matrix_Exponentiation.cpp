// Section 2 Question 2 Bonus
// Fibonacci Numbers using Matrix Exponentiation

// We use the Binary Exponentiation on Matrices, to easily
// find the nth number of Fibonacci sequence.

// Input format:
// t : number of test cases
// n : index of the number in Fibonacci sequence to be found

// Output format:
// f(n) : nth number of Fibonacci sequence

// Can be downloaded from the git repository:
// https://github.com/PixlatedBatman/ProgrammingClub-Coordinator-Application

#include <bits/stdc++.h>
#define llt long long int
#define vllt vector<llt>            // Defined for easy and quick writing
#define endl "\n"
using namespace std;

llt Mul(llt a, llt n){              // The General Binary Exponentiation function
    if(n==0) return 1;              // Taken here for reference
    else if(n==1) return a;

    return Mul(a, (n+1)/2)*Mul(a, n/2);
}

vllt I = {1, 0, 0, 1};              // Identity Matrix definition

vllt Matrix_Mult(vllt Matrix1, vllt Matrix2){
    vllt Mul_Mat(4);                // Function for multiplication of Matrices               

    Mul_Mat[0] = Matrix1[0]*Matrix2[0] + Matrix1[1]*Matrix2[2];
    Mul_Mat[1] = Matrix1[0]*Matrix2[1] + Matrix1[1]*Matrix2[3];
    Mul_Mat[2] = Matrix1[2]*Matrix2[0] + Matrix1[3]*Matrix2[2];
    Mul_Mat[3] = Matrix1[2]*Matrix2[1] + Matrix1[3]*Matrix2[3];

    return Mul_Mat;
}

vllt Matrix_Sq(vllt Matrix){        // Function to square a matrix
    return Matrix_Mult(Matrix, Matrix);
}

vllt Matrix_Exp(vllt Matrix, llt n){    // Function for Matrix Exponentiation
    if(n==0) return I;              
    else if(n==1) return Matrix;    //Termination points for recursion

    else if(n%2==0) return Matrix_Sq(Matrix_Exp(Matrix, n/2));
    else return Matrix_Mult(Matrix_Sq(Matrix_Exp(Matrix, n/2)), Matrix);   
}

void Main(){
    llt n;
    cin >> n;
    if(n==0) n=1;       // 0th number cant be found by this method, hence n=1 set as both have the same value
    
    vllt Matrix_i = {1, 1, 1, 0};   // The matrix obtained for easily obtaining Fibonacci numbers
    
    vllt Res_Mat = Matrix_Exp(Matrix_i, n-1);   // Raised to (n-1)th power for finding nth Fibonacci number
    
    cout << Res_Mat[0] + Res_Mat[1] << endl;    // The sum of the elements of first row is the nth element
}                                               // of the Fibonacci sequence, hence the output we need

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t; while(t--) Main();         // Run for t test cases
    return 0;
}