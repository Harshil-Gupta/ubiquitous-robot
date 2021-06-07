#include<iostream>
using namespace std;

void sol(){
    int m,n;
    cin>>n>>m;
    int arr[n+1][m+1];
    int dp[n+1][m+1];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int i=1;i<=m;i++){
        dp[0][i] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int a = dp[i-1][j];
            int b = dp[i-1][j-1];
            int c = dp[i][j-1];
            dp[i][j] = arr[i-1][j-1] + min(a,min(b,c)); 
        }
    }
    cout << arr[0][0] + dp[n][m] << endl;    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        sol();
    }
    return 0;
}