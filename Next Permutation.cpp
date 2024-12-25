//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        // code here
        int n = arr.size();
        int init = -1; 
        for (int i = n - 2;i >= 0;i--)
        {
            if (arr[i] < arr[i + 1]) {
                init = i;
                break;
            }
        }
        
        if (init == -1) {
        reverse(arr.begin(), arr.end());
        return;
    }

        for (int i = n - 1;i > init;i--) {
            if (arr[i] > arr[init]) {
                swap(arr[i], arr[init]);
                break;
            }
        }
        
    reverse(arr.begin() + init + 1, arr.end());
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int n = arr.size();
        ob.nextPermutation(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
