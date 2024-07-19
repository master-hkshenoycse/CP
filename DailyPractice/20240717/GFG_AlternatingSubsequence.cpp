#include<bits/stdc++.h>
using namespace std;
int alternatingMaxLength(vector<int>& arr) {
        // Code here
        int n=arr.size(),dec_len=1,inc_len=1;
        
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1]){
                inc_len=max(inc_len,dec_len+1);
            }else if(arr[i-1]>arr[i]){
                dec_len=max(dec_len,inc_len+1);
            }
        }
        
        return max(dec_len,inc_len);
    }