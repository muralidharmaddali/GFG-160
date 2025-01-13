//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count inversions in the array.
    long long mergedCnt(vector<int>& arr,vector<int>& target,int left,int mid,int right)
    {
     
        int i=left,j=mid+1,k=left;
        long long cnt=0;
        while(i<=mid && j<=right)
        {
            if(arr[i]<=arr[j])
            {
                target[k++]=arr[i++];
            }
            else
            {
                target[k++]=arr[j++];
                cnt+=(mid-i+1);
            }
        }
        
        while(i<=mid) target[k++] = arr[i++];
        while(j<=right) target[k++]=arr[j++];
        for(int i=left;i<=right;i++)
        {
            arr[i]=target[i];
        }
        return cnt;
    }
    
    long long mergedCount(vector<int>& arr,vector<int>& target,int left,int right)
    {
        long long cnt=0;
        if(left<right)
        {
            int mid = left+(right - left)/2;
            cnt += mergedCount(arr,target,left,mid);
            cnt += mergedCount(arr,target,mid+1,right);
            cnt += mergedCnt(arr,target,left,mid,right);
        }
        return cnt;
    }
    long long inversionCount(vector<int> &arr) {
        // Your Code Here
        vector<int> temp(arr.size());
        return mergedCount(arr,temp,0,arr.size()-1);
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
