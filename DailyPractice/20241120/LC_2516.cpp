#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int takeCharacters(string s, int k) {
        
        if(k==0){
            return 0;
        }
        int n=s.size();
        vector<int> pref_a(n,0),pref_b(n,0),pref_c(n,0),suff_a(n,0),suff_b(n,0),suff_c(n,0);
        
        int ans=n+1;
        for(int i=0;i<n;i++){
            pref_a[i]=(s[i]=='a');
            pref_b[i]=(s[i]=='b');
            pref_c[i]=(s[i]=='c');
            
            if(i-1>=0){
                pref_a[i]+=pref_a[i-1];
                pref_b[i]+=pref_b[i-1];
                pref_c[i]+=pref_c[i-1];
            }
            
            if(pref_a[i]>=k and pref_b[i]>=k and pref_c[i]>=k){
                ans=min(ans,i+1);
            }
        }
        
        if(pref_a[n-1]<k or pref_b[n-1]<k or pref_c[n-1]<k){
            return -1;
        }
        
        for(int i=n-1;i>=0;i--){
            suff_a[i]=(s[i]=='a');
            suff_b[i]=(s[i]=='b');
            suff_c[i]=(s[i]=='c');
            
            if(i+1<n){
                suff_a[i]+=suff_a[i+1];
                suff_b[i]+=suff_b[i+1];
                suff_c[i]+=suff_c[i+1];
            }
            
            if(suff_a[i]>=k and suff_b[i]>=k and suff_c[i]>=k){
                ans=min(ans,n-i);
            }
        }
        
        
        
        
        
        for(int i=0;i<n-1;i++){
            int r_a=k-pref_a[i];
            int r_b=k-pref_b[i];
            int r_c=k-pref_c[i];
            
            int lo=i+1,hi=n-1,r=i+1;
            
            while(hi>=lo){
                int mid=(hi+lo)/2;
                
                if(suff_a[mid]>=r_a and suff_b[mid]>=r_b and suff_c[mid]>=r_c){
                    r=max(r,mid);
                    lo=mid+1;
                }else{
                    hi=mid-1;
                }
            }
            
            //cout<<i<<" "<<r<<endl;
            ans=min(ans,i+1+n-r);
            
        }
        
        
        
        
        return ans;
    }
};