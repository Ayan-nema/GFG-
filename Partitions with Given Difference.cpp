

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countPartitions(vector<int>& arr, int d) {
        int n = arr.size();
        int sum = 0;
        
        for (auto it : arr) {
            sum += it;
        }

        // If (sum + d) is odd, partition is not possible
       // if ((sum + d) % 2 != 0 || sum < d) return 0;

        int req = (sum + d) / 2;
        int t[n + 1][req + 1];

        // Initializing the table
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= req; j++) {
                if (i == 0) 
                    t[i][j] = 0; 
                if (j == 0) 
                    t[i][j] = 1; 
            }
        }

        // Filling the table
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= req; j++) {  // Fixed loop to start from j = 0
                if (arr[i - 1] <= j) {
                    t[i][j] = t[i - 1][j] + t[i - 1][j - arr[i - 1]];
                } else {
                    t[i][j] = t[i - 1][j];
                }
            }
        }

        return t[n][req];
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countPartitions(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends