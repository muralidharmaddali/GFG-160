//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& arr) {
    int n = arr.size();
    vector<int> sol;
    unordered_map<int,int> mp;
    
    for(int cnt:arr)
    {
        mp[cnt]++;
    }
    
    for(auto it:mp)
    {
        int first = it.first;
        int second = it.second;
        
        if(second>n/3)
        {
            sol.push_back(first);
        }
    }
    
    int m = sol.size();
    if (m == 2 && sol[0] > sol[1])
        swap(sol[0], sol[1]);
    return sol;
    
}
       
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto &i : ans)
                cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
