#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
       
        int lo=1,hi=1e6,ans=1e6;
        
        while(hi>=lo){
            int m=(hi+lo)/2;
            
            int c=0;

            for(auto q:quantities){
                c=c+(q+m-1)/m;
            }
 //         cout<<c<<endl;
            
            if(c<=n){
                ans=min(ans,m);
                hi=m-1;
            }else{
                lo=m+1;
            }
        }
        
        return ans;
    }
};