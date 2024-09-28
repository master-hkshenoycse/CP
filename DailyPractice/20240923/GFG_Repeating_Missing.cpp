#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int repeating=-1,n=arr.size(),missing=-1;
        ll curr_sum=0,exp_sum=(n*1ll*(n*1ll+1))/2ll;
        
        for(int i=0;i<n;i++){
            int v=abs(arr[i]);
            curr_sum+=v*1ll;
            if(arr[v-1] < 0 and repeating==-1){
                repeating=v;
            }
            
            arr[v-1]*=-1;
        }
        
        missing=exp_sum-curr_sum+repeating;
        
        return {repeating,missing};
    }