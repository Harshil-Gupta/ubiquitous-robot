// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int solvedp(int n, int arr[], int target){
        int dp[n+1][target+1];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<=target;j++){
                dp[i][j] = 0;
            }
        }
        
        for(int i=0;i<n;i++){
            dp[i][0] = 1;
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=target;j++){
                dp[i][j] = dp[i-1][j];
                
                if(j-arr[i-1]>=0){
                    dp[i][j] = max(dp[i][j],dp[i-1][j-arr[i-1]]);
                }
            }
        }
        return dp[n-1][target];
    }

    int solve(int n, int arr[], int target){
        if(n<0){
            return 0;
        }
        if(target == 0){
            return 1;
        }
        int temp1 = 0;
        int temp2 = 0;
        if(target-arr[n-1]>=0){
            temp1 = solve(n-1,arr,target-arr[n-1]);
        }
        temp2 = solve(n-1,arr,target);
        return temp1 || temp2;
    }

    int equalPartition(int N, int arr[])
    {
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        if(sum%2 !=0){
            return 0;
        }
        return solvedp(N,arr,sum/2);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends
