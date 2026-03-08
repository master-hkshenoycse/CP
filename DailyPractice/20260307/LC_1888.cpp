#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int csum_0[500005],csum_1[500005];
    int minFlips(string s) {
        int n=s.size();
        string y=s+s;
        
        for(int i=1;i<=2*n;i++){
            csum_0[i]=csum_0[i-1];
            csum_1[i]=csum_1[i-1];
            if(i%2){
                csum_0[i]+=(y[i-1]=='1');
                csum_1[i]+=(y[i-1]=='0');
            }
            if(i%2==0){
                csum_0[i]+=(y[i-1]=='0');
                csum_1[i]+=(y[i-1]=='1');
            }
            
        }

        
        int ans=n;
        for(int i=1;i<=n;i++){
            ans=min(ans,csum_0[i+n-1]-csum_0[i-1]);
            ans=min(ans,csum_1[i+n-1]-csum_1[i-1]);
        }
        return ans;
        
    
        
    }
};