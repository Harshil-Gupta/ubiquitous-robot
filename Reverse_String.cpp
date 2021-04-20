#include<bits/stdc++.h>
using namespace std;

string reverseWord(string str);

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin >> s;
	
	cout << reverseWord(s) << endl;
	}
	return 0;
	
}

string reverseWord(string str){
    for(int i=0;i<str.length()/2;i++){
        char temp;
        int len = str.length();
        temp = str[i];
        str[i] = str[len-1-i];
        str[len-1-i] = temp;
    }
    return str;

}
