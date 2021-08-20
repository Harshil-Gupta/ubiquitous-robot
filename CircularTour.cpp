// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


 // } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    
    int tour(petrolPump p[],int n) {
        
        // Petrol sum < dist sum return -1
        
        int psum=0,dsum=0;
        for(int i=0;i<n;i++){
            psum += p[i].petrol;
            dsum += p[i].distance;
        }
        if(dsum>psum){
            return -1;
        }
        
        int ans = 0;
        int carry = 0;
        int temp = 0;
        for(int i=0;i<n;i++){
            temp = 0;
            temp+=p[i].petrol;
            temp-=p[i].distance;
            if(temp<0){
                continue;
            }
            carry+=temp;
            int j=i+1;
            for(;j<n;j++){
                temp+=(p[j].petrol - p[j].distance);
                if(temp<0){
                    break;
                }
            }
            if(j==n){
                ans = i;
                break;
            }
        }
        return ans;
    }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}
  // } Driver Code Ends
