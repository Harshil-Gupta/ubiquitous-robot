#include<unordered_map>
#include <iostream>
using namespace std;
int getPairsWithDifferenceK(int *arr, int n, int k) {
	
    unordered_map<int,int> mp;
    int count = 0;

    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    for(int i=0;i<n;i++){
        if(mp[arr[i]]>0){
        if(mp.count(arr[i]+k)>0){
            if(arr[i]+k==0){
                count++;
            }else
            count+=mp[arr[i]+k];
        }
        if(mp.count(arr[i]-k)>0){
            if(arr[i]-k==0){
                count++;
            }else
            count+=mp[arr[i]-k];
        }
            mp[arr[i]] = 0;
        }
    }
    return count;    
}

int main() {
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int k;
    cin >> k;

    cout << getPairsWithDifferenceK(input, n, k);

    delete[] input;
}