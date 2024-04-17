#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void merge(vector<int> &vals,int l,int mid,int r,int &ans){
        
        vector<int> sorted_v;
        int i=l,j=mid+1;
        
        while(i<=mid and j<=r){
            if(vals[i]<=vals[j]){
                sorted_v.push_back(vals[i]);
                i++;
            }else{
                ans=ans+(mid-i+1);
                sorted_v.push_back(vals[j]);
                j++;
            }
        }
        
        while(i<=mid){
            sorted_v.push_back(vals[i++]);
        }
        
        while(j<=r){
            sorted_v.push_back(vals[j++]);
        }
        
        int sz=sorted_v.size();
        for(int i=0;i<sz;i++){
            vals[l+i]=sorted_v[i];
        }
        
        
    }
    void mergesort(vector<int> &vals,int l,int r,int &ans){
        if(l>=r){
            return;
        }
        int mid=(l+r)/2;
        mergesort(vals,l,mid,ans);
        mergesort(vals,mid+1,r,ans);
        merge(vals,l,mid,r,ans);
    }
    int countPairs(int arr[] , int n ) 
    {
        // Your code goes here 
        vector<int> vals;
        for(int i=0;i<n;i++){
            vals.push_back(arr[i]*i);
        }
        int ans=0;
        mergesort(vals,0,n-1,ans);
        
        return ans;
    }
};