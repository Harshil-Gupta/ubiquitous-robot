#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int editDistance(string s1, string s2, int **output) {  
    // BASE CASE
    
    if(s1.size()<=0 || s2.size()<=0){
        return max(s1.size(),s2.size());
    }
    int i = s1.size()-1;
    int j = s2.size()-1;
    // Ans exists or not
    if(output[i][j]!=-1){
        return output[i][j];
    }
    
    int ans=INT_MAX;
    
    if(s1[0]==s2[0]){
        ans = editDistance(s1.substr(1),s2.substr(1),output);
    }
    else{
    	int a = editDistance(s1,s2.substr(1),output)+1;
    	int b = editDistance(s1.substr(1),s2.substr(1),output)+1;
    	int c = editDistance(s1.substr(1),s2,output)+1;
    	ans = min(a,min(b,c));
	}
	output[i][j] = ans;
    return ans;
}

int editDistance(string s1, string s2) {
    int ** output = new int*[s1.size()+1];
    for(int i=0;i<s1.size();i++) {
        output[i] = new int[s2.size()+1];
        for(int j=0;j<s2.size();j++) {
            output[i][j]=-1;
        }
    }   
    return editDistance(s1,s2,output);
}