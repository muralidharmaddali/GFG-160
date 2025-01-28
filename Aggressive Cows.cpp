//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:

    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(),stalls.end());
        int low = 1,high = stalls.back()-stalls.front(),mid;
        while(low<=high)
        {
            mid = low + (high-low)/2;
            int cnt=1,las=stalls[0];
            for(int i=1;i<stalls.size();i++)
            {
                if(stalls[i] - las>=mid) {
                    cnt++;
                    las = stalls[i];
                }
            }
            if(cnt>=k) low = mid+1;
            else high = mid-1;
        }
        return high;
        // Write your code here
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends