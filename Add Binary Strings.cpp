//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    
    string addBinary(string& s1, string& s2) {
        // your code here
        int i=s1.size()-1,j=s2.size()-1;
        int res=0;
        string ans;
        
        while(i>=0 || j>=0 || res>0){
            int sum = res;
            if(i>=0) sum+=s1[i--] - '0';
            if(j>=0) sum+=s2[j--] - '0';
            ans.push_back((sum%2) + '0');
            res = sum/2;
        }
        reverse(ans.begin(),ans.end());
        size_t first = ans.find_first_not_of('0');
        return (first!=string::npos)? ans.substr(first) : "0";
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
