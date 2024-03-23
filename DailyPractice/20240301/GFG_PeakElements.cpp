#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int peakElement(int arr[], int n)
    {
       // Your code here
       int lo=1,hi=n-1,ans=0;
       while(hi>=lo){
           int mid=(hi+lo)/2;
           if(arr[mid]>=arr[mid-1]){
               ans=max(ans,mid);
               lo=mid+1;
           }else{
               hi=mid-1;
           }
       }
       
       return ans;
    }
};