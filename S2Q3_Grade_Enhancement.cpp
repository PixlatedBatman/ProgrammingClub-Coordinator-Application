// Section 2 Question 3
// Grade Enhancement

// This code increases the marks of students from roll numbers l to r
// without manually doing it(Which takes O(n^2+q) time complexity).
// Instead we use difference arrays and prefix sum them to get the resultant
// array, which can be implemented in O(n+q) time complexity.

// Input format:
// t : number of test cases
// n : number of students in Prof. Dhumketu's class
// n integers : Initial marks of each student
// q : number of queries
// l, r, x : x marks increased for students from roll numbers l to r

// Output format:
// n integers : The final marks of all the students after TA Kalia's magic

// Can be downloaded from the git repository:
// https://github.com/PixlatedBatman/ProgrammingClub-Coordinator-Application

#include <bits/stdc++.h>
#define llt long long int
#define vllt vector<llt>        // Defined for easy and quick writing
#define cinv(v) for(auto &iz:v) cin>>iz       
#define L(i, j, k) for(int i=(j);i<(k);i++)
#define endl "\n"
using namespace std;

void Main(){
    llt n, q, l, r, x, s=0;
    cin >> n;
    vllt v(n), d(n+1);
    cinv(v);                    // Taking in the initial marks of the students
    
    cin >> q;                   // Processing the q queries
    L(i, 0, q){
        cin >> l >> r >> x;
        d[l-1] += x;        // All elements from (l-1)th to (r-1)th index to be added by x
        d[r] -= x;          // And from rth element, there is no addition
    }

    L(i, 0, n){             // Now, applying prefix sum to get the resultant marks
        s += d[i];
        //v[i] += s;                This appends vector v, but we dont need to
        //cout << v[i] << ' ';      do that to increase efficiency
        cout << v[i] + s << ' ';
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t; while(t--) Main();     // Running it for t times
    return 0;
}