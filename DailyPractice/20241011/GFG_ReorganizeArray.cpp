#include<bits/stdc++.h>
using namespace std;
vector<int> rearrange(vector<int>& arr) {
        // Code here
        int n=arr.size();
        int z=0;
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                z=1;
            }else if(arr[i]==-1){
                arr[i]=0;
            }
        }
        
        for(int i=0;i<n;i++){
            if(arr[i] !=0){
                arr[arr[i]%n]+=n;
            }
        }
        
        if(z){
            arr[0]=0;
        }else{
            arr[0]=-1;
        }
        
        for(int i=1;i<n;i++){
            if(arr[i]>=n){
                arr[i]=i;
            }else{
                arr[i]=-1;
            }
        }
        
        return arr;
    }