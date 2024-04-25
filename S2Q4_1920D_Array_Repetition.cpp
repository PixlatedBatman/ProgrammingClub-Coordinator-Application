// 1920D : Array Repetition
// Successful Submission

// Section 2 Question 4
// Array Repetition

// This Question has been chosen because it is a very good logic, and was 
// found without the help of any editorial or any other documentation.

// Link to the question in Codeforces:
// https://codeforces.com/contest/1920/problem/D

// Input format:
// t : number of test cases
// n, q : number of operations and number of queries respectively
// (n lines) b, x : the type of operation and the integer used for the operation
// (q integers) k : The index of the value in the total array 

// Output format:
// q outputs : The value at the kth index of the total array

// Can be downloaded from the git repository:
// https://github.com/PixlatedBatman/ProgrammingClub-Coordinator-Application

// Video editorial is also made, explaining in detail how the code works,
// using OneNote notes, both of which can be found in the same repository

#include <bits/stdc++.h>
#define llt unsigned long long int
#define vllt vector<llt>            // Adding these for easy and quick function writing
#define pb push_back       
#define L(i, j, k) for(int i=(j);i<(k);i++)
#define endl "\n"
using namespace std;

void Main(){
    llt n, q;
    cin >> n >> q;
    map <llt, llt> mp;          // Map for storing the appended element
    vllt sbm;                   // Vector for storing the size before multiplication
    llt s=0, b, x, k;
    L(i, 0, n){
        cin >> b >> x;
        if(b == 1){
            s++;                // size increases by 1 when appended
            mp[s] = x;
        }
        else{
            if(s==2e18) continue;   // Skipping unnecessary cases
            sbm.pb(s);
            if(s<2e18/(x+1)) s*=x+1;// Size increases by a factor of x+1
            else{
                s=2e18;
                continue;
            }
        }
    }
    
    L(i, 0, q){
        cin >> k;
        //auto it = lower_bound(sbm.begin(), sbm.end(), k); This is using binary search
        //x= it - sbm.begin()-1;                            to reduce the number of remainders found
        x = sbm.size()-1;        // If binary search not used, we take sbm.size() number of remainders
        while(true){    
            if(mp[k] != 0){             //If element found in map, break
                cout << mp[k] << ' ';
                break;
            }
            else{
                k = k%sbm[x];           //Else continue finding remainders
                if(k==0) k = sbm[x];
                x--;
            }
        }
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t; while(t--) Main(); // Run for t test cases
    return 0;
}