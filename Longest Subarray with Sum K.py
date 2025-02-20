# User function Template for python3

class Solution:
    def longestSubarray(self, arr, k):  
        # code here
        ump,sum,ans={},0,0
        for i,num in enumerate(arr):
            sum+=num
            if sum==k:
                ans = i+1
            if sum-k in ump:
                ans=max(ans,i-ump[sum-k])
            ump.setdefault(sum,i)
        return ans
    



#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input().strip())
    while tc > 0:
        arr = list(map(int, input().strip().split()))
        k = int(input().strip())
        ob = Solution()
        print(ob.longestSubarray(arr, k))
        tc -= 1
        print("~")
# } Driver Code Ends
