//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {

        // your code here
        int total_sum = 0,curr_sum1=0,curr_sum2=0,maxi_sub=INT_MIN,mini_sub=INT_MAX;
        for(auto i:arr)
        {
            total_sum+=i;
            curr_sum1+=i;
            curr_sum2+=i;
            maxi_sub=max(maxi_sub,curr_sum1);
            if(curr_sum1<0) curr_sum1=0;
            mini_sub = min(curr_sum2,mini_sub);
            if(curr_sum2>0) curr_sum2=0;
        }
        return (total_sum==mini_sub)?maxi_sub:max(maxi_sub,total_sum-mini_sub);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends
