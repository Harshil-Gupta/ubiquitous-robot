// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int mcm_mem(int *arr, int left, int right, int **dp)
    {
        if (left == right)
        {
            return 0;
        }
        if (dp[left][right] != -1)
        {
            return dp[left][right];
        }

        dp[left][right] = INT_MAX;

        for (int i = left; i < right; i++)
        {

            int l = mcm_mem(arr, left, i, dp);
            int r = mcm_mem(arr, i + 1, right, dp);

            int cost = l + r + arr[left - 1] * arr[i] * arr[right];

            dp[left][right] = min(dp[left][right], cost);
        }
        return dp[left][right];
    }
    int matrixMultiplication(int n, int arr[])
    {
        int **dp = new int *[n + 1];
        for (int i = 0; i <= n; i++)
        {
            dp[i] = new int[n + 1];
            for (int j = 0; j <= n; j++)
            {
                dp[i][j] = -1;
            }
        }
        return mcm_mem(arr, 1, n - 1, dp);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.matrixMultiplication(N, arr) << endl;
    }
    return 0;
} // } Driver Code Ends
