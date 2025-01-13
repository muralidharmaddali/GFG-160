//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        if(arr.size()<=1)
        {
            return arr;
        }
        
        sort(arr.begin(),arr.end());
        vector<vector<int>> temp;
        temp.push_back(arr[0]);
        for(int i=1;i<arr.size();i++)
        {
            vector<int>& right = temp.back();
            if(arr[i][0]<=right[1])
            {
                right[1] = max(right[1],arr[i][1]);
            }
            else
            {
                temp.push_back(arr[i]);
            }
        }
        return temp;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        Solution obj;
        vector<vector<int>> ans = obj.mergeOverlap(arr);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
