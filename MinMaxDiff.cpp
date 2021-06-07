#include<bits/stdc++.h>
using namespace std;
int smallestRangeII(vector<int>& A, int K) {
        sort(A.begin(),A.end());
        int dp1[A.size()],dp2[A.size()];
        for(int i=0;i<A.size();i++)
        {
                dp1[i]=A[i]+K;
                dp2[i]=A[i]-K;
            
        }
        if(A.size()==1)
            return 0;
        int sum=A[A.size()-1]-A[0];
        int n=A.size();
        for(int i=0;i<A.size()-1;i++)
        {
            int m1=max(dp2[n-1],dp1[i]);
            int m2=min(dp1[0],dp2[i+1]);
            sum=min(sum,m1-m2);
        }
        return sum;
    }
int main(){
    int n;cin>>n;
    vector<int>v(n);
    int k;cin>>k;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        v.push_back(a);
    }
    cout << smallestRangeII(v,k) << endl;
    return 0;
}
