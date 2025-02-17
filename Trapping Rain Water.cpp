//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int left = 0,right=arr.size() - 1, ans=0,lefma=0,rima=0;
        while(left<right)
        {
            arr[left]<arr[right]? (lefma = max(lefma,arr[left]), ans+=lefma - arr[left++]) : (rima = max(rima,arr[right]), ans+=rima - arr[right--]); 
        }
        return ans;
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
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
