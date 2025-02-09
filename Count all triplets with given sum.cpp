//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        // Code Here
        int n = arr.size(),ans = 0;
        for(int i=0;i<n-2;++i)
        {
            int j = i+1,k=n-1;
            while(j<k)
            {
                int sum = arr[i]+arr[j]+arr[k];
                if(sum<target)
                {
                    ++j;
                }
                else if(sum>target)
                {
                    --k;
                }
                else
                {
                    if(arr[j]==arr[k])
                    {
                        int res = k - j + 1;
                        ans+= (res * (res-1)) /2;
                        break;
                    }
                    else
                    {
                        int cnt1 = 1,cnt2=1;
                        while(j+1<k && arr[j] == arr[j+1]) ++j,++cnt1;
                        while(k-1>j && arr[k] == arr[k-1]) --k,++cnt2;
                        ans+=cnt1*cnt2;
                        ++j;
                        --k;
                    }
                }
            }
        }
        return ans;
    }
};
    
    


//{ Driver Code Starts.

vector<int> lineArray() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr = lineArray();
        int target;
        cin >> target;
        cin.ignore();

        Solution ob;
        int res = ob.countTriplets(arr, target);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends
