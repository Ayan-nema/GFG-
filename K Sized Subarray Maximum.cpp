// Bruteforce approach
// Time complexity: O(n*k)
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      vector<int> maxOfSubarrays(vector<int>& arr, int k) {
          // code here
          int n=arr.size();
          vector<int> maxarr(n-k+1);
          for(int i=0;i<=n-k;i++)
          {
           int maxx=*max_element(arr.begin()+i, arr.begin()+i+k);
           maxarr[i]=maxx;
          }
          return maxarr;
      }
  };
//Optimal approach
//Time complexity: O(n)

#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
      vector<int> maxOfSubarrays(vector<int>& arr, int k) {
          // code here
            int n = arr.size();
          vector<int> result;
          deque<int> dq; // Stores indices of useful elements
          
          for (int i = 0; i < n; i++) {
              // Remove elements not in the current window
              if (!dq.empty() && dq.front() == i - k)
                  dq.pop_front();
  
              // Remove smaller elements from back
              while (!dq.empty() && arr[dq.back()] <= arr[i])
                  dq.pop_back();
  
              // Add current element index
              dq.push_back(i);
  
              // Add maximum of current window to result
              if (i >= k - 1)
                  result.push_back(arr[dq.front()]);
          }
  
          return result;
      }
  };