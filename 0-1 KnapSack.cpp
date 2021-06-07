#include <bits/stdc++.h>
using namespace std;

int knapsack_dp(int *weights, int *values, int n, int maxWeight){

    int dp[n+1][maxWeight+1];
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int j=0;j<=maxWeight;j++){
        dp[0][j] = 0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=maxWeight;j++){
            if(weights[i-1] <= maxWeight){
                dp[i][j] = max(dp[i-1][j],values[i-1] + dp[i-1][maxWeight-weights[i-1]];
            }
            else{        
                dp[i][j] = dp[(i-1)][j];
            }
        }
    }
    return dp[n][maxWeight];
}


int knapsack(int *weights, int *values, int n, int maxWeight){
    if(n==0 || maxWeight == 0){
        return 0;
    }

    if(weights[0] > maxWeight){
        return knapsack(weights+1,values+1,n-1,maxWeight);
    }
    int x = values[0]+knapsack(weights+1,values+1,n-1,maxWeight-weights[0]);
    int y = knapsack(weights+1,values+1,n-1,maxWeight);
    return max(x,y);
}

int main(){
    int n;
    cin >> n;
	int *weights = new int[n];
	int *values = new int[n];
	for (int i = 0; i < n; i++){
		cin >> weights[i];
	}
	for (int i = 0; i < n; i++){
		cin >> values[i];
	}
	int maxWeight;
	cin >> maxWeight;
    cout << knapsack(weights, values, n, maxWeight) << endl;
    cout << knapsack_dp(weights, values, n, maxWeight) << endl;
}

/*
5
10 3 2 5 20
5 7 1 0 8
16
*/