//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  int space(int n)
        {
            return(n<=1) ? 0 :(n/2) + (n%2);
        }
    void mergeArrays(vector<int>& a, vector<int>& b) {
        // code here
        int n = a.size(),m=b.size(),k=n+m;
        for(k=space(k);k>0;k=space(k))
        {
            int i,j;
            for(i=0;i+k<n;i++)
            {
                if(a[i]>a[i+k]) swap(a[i],a[i+k]);
            }
            
            for(j=(k>n ? k-n:0);i<n && j<m;i++,j++){
                if(a[i]>b[j]) swap(a[i],b[j]);
            }
            
            for(j=0;j+k<m;j++)
            {
                if(b[j]>b[j+k]) swap(b[j],b[j+k]);
            }
        }
        
    }
};

//{ Driver Code Starts.

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Inputting the test cases

    while (t--) {
        vector<int> a, b;

        // Reading the first array as a space-separated line
        string arr1;
        getline(cin >> ws, arr1); // Use ws to ignore any leading whitespace
        stringstream ss1(arr1);
        int num;
        while (ss1 >> num) {
            a.push_back(num);
        }

        // Reading the second array as a space-separated line
        string arr2;
        getline(cin, arr2);
        stringstream ss2(arr2);
        while (ss2 >> num) {
            b.push_back(num);
        }

        Solution ob;
        ob.mergeArrays(a, b);

        // Output the merged result
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < b.size(); i++) {
            cout << b[i] << " ";
        }
        cout << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends
