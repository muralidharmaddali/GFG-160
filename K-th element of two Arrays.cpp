//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        int m = a.size();
        int n = b.size();
        int left = k;
        if(m>n) return kthElement(b,a,k);
        int low = max(0,k-n), high = min(k,m);
        while(low<=high)
        {
            int b1 = (low+high)>>1;
            int b2 = left - b1;
            int l1 = INT_MIN, l2=INT_MIN;
            int r1 = INT_MAX, r2=INT_MAX;
            if(b1<m) r1 = a[b1];
            if(b2<n) r2 = b[b2];
            if(b1 - 1 >=0) l1 = a[b1 - 1];
            if(b2 - 1 >=0) l2 = b[b2 - 1];
            
            if(l1 <=r2 && l2<=r1){
                return max(l1,l2);
            }
            
            else if(l1>r2) high = b1-1;
            else low = b1+1;
        }
        return 0;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> a, b;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            b.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(a, b, k) << endl << "~\n";
    }
    return 0;
}
// } Driver Code Ends
