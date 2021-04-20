#include <bits/stdc++.h>
using namespace std;
int main()
{
    int min=INT_MIN,max=INT_MAX;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    min=arr[0];
    max=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]<min){
            min = arr[i];
        }
        if(arr[i]>max){
            max=arr[i];
        }
    }
    cout << min << " " << max;
    return 0;
}