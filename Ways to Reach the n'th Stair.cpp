#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int countWaysRec(int n, vector<int>& t) {
            if (n == 0 || n == 1) return 1;
            
            if (t[n] != -1) return t[n];
            
            return t[n] = countWaysRec(n - 1, t) + countWaysRec(n - 2, t); // ✅ Corrected
        }   
      
        int countWays(int n) {
            vector<int> t(n + 1, -1);
            return countWaysRec(n, t);   
        }
    };