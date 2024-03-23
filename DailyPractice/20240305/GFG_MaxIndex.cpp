#include<bits/stdc++.h>
using namespace std;

/*Binary serach on prefix minimum array*/

int maxIndexDiff(int a[], int n) 
    { 
        // Your code here
        vector<int> prefix_min(n);
        for(int i=0;i<n;i++){
            prefix_min[i]=a[i];
            if(i>0){
                prefix_min[i]=min(prefix_min[i],prefix_min[i-1]);
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            int lo=0,hi=i,r=i;
            
            
            while(hi>=lo){
                int mid=(hi+lo)/2;
                if(prefix_min[mid] <= a[i]){
                    r=min(r,mid);
                    hi=mid-1;
                }else{
                    lo=mid+1;
                }
            }
            
            
            ans=max(ans,i-r);
        }
        
        return ans;
    }