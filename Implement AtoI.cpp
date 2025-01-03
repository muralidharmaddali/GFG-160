//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int myAtoi(char *s) {
        // Your code here
        int sign=1,res=0,ind=0;
        while(s[ind]==' ')
        {
            ind++;
        }
        if(s[ind]=='-' || s[ind]=='+')
        {
            if(s[ind++]=='-')
            {
                sign=-1;
            }
        }
        
        while(s[ind]>='0' && s[ind]<='9')
        {
            if(res>INT_MAX/10 || (res==INT_MAX/10 && s[ind]-'0'>7))
            {
                return sign== 1 ? INT_MAX:INT_MIN;
            }
            
            res=10*res+(s[ind++]-'0');
        }
        return res*sign;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[20];
        cin >> s;
        Solution ob;
        int ans = ob.myAtoi(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends
