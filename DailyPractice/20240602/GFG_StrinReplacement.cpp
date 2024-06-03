#include<bits/stdc++.h>
using namespace std;
/*https://practice.geeksforgeeks.org/contest/gfg-weekly-157-rated-contest/problems*/
class Solution {
  public:
    int countOperations(string s) {
        // code here
        int ans=0,mod=1e9+7,cnt_b=0,n=s.size();
        for(int i=n-1;i>=0;i--){
            if(s[i]=='b'){
                cnt_b++;
            }else if(cnt_b>0){
                ans=(ans+cnt_b)%mod;
                //cout<<ans<<" "<<cnt_b<<endl;
                cnt_b=(cnt_b*2)%mod;
            }
        }
        
        return ans;

    }
};