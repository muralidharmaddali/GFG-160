//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> search(string& pat, string& txt) {
        // code here
        int m = pat.size();
        int k = txt.size();
        vector<int> vc(m,0);
        vector<int> res;
        int n=0;
        for(int i=1;i<m;)
        {
            if(pat[i]==pat[n])
            {
                n++;
                vc[i] = n;
                i++;
            }
            else
            {
                if(n!=0)
                {
                    n = vc[n-1];
                }
                else
                {
                    vc[i]=0;
                    i++;
                }
            }
        }
        int i=0;
        int j=0;
        while(i<k){
            if(txt[i] == pat[j])
            {
                i++;
                j++;
            }
            if(j==m)
            {
                res.push_back(i-j);
                j = vc[j-1];
            }
            else if(i<k && txt[i]!=pat[j])
            {
                if(j!=0)
                {
                    j=vc[j-1];
                }
                else
                {
                    i++;
                }
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        if (res.size() == 0)
            cout << "[]" << endl;
        else {
            for (int i : res)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends
