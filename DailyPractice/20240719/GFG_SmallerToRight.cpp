#include<bits/stdc++.h>
using namespace std;
void merge_sort(vector<pair<int,int> > &values,int l,int r,vector<int> &sol){
        
        if(l>r){
            return;
        }
        
        if(l==r){
            return;
        }
        
        int mid=(l+r)/2;
        merge_sort(values,l,mid,sol);
        merge_sort(values,mid+1,r,sol);
        
        
        vector<pair<int,int> > tmp;
        
        
        int i=l,j=mid+1;
        
        while(i<=mid and j<=r){
            if(values[j].first < values[i].first){
                tmp.push_back(values[j++]);
            }else{
                tmp.push_back(values[i]);
                sol[values[i].second]+=(j-mid-1);
                i++;
            }    
        }
        
        while(i<=mid){
            tmp.push_back(values[i]);
            sol[values[i].second]+=(j-mid-1);
            i++;
        }
        
        while(j<=r){
            tmp.push_back(values[j++]);
        }
        
        for(int i=l;i<=r;i++){
            values[i]=tmp[i-l];
        }
        
        
    }
    vector<int> constructLowerArray(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int> sol(n,0);
        
        vector<pair<int,int> > values;
        for(int i=0;i<n;i++){
            values.push_back({arr[i],i});
        }
        
        merge_sort(values,0,n-1,sol);
        
        return sol;
    }