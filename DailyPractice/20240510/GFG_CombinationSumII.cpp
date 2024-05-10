#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    void rec(int ind,vector<int> &arr,int k,vector<int> &curr,vector<vector<int> >&sol){
        

        
        if(k<0){
            return;
        }
        if(ind==arr.size()){
            if(k==0){
                sol.push_back(curr);
            }   
            
            
            
            return;
        }
        
        int nx=ind;
        
        while(nx<arr.size() and arr[nx]==arr[ind]){
            nx++;
        }
        
        rec(nx,arr,k,curr,sol);
        
        for(int i=ind;i<nx;i++){
            
            k-=arr[ind];
            curr.push_back(arr[ind]);
            
            
            rec(nx,arr,k,curr,sol);
            
        
        }
        
        for(int i=ind;i<nx;i++){
            k+=arr[ind];
            curr.pop_back();
        }
    }
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        //code here
        sort(arr.begin(),arr.end());
        
        vector<int> curr;
        vector<vector<int> > sol;
        
        rec(0,arr,k,curr,sol);
        
        sort(sol.begin(),sol.end());
        
        return sol;
    }
};