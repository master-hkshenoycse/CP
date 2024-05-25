#include<bits/stdc++.h>
using namespace std;
#define dd double
class Solution {
  public:
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
        int n=stations.size();
        dd lo=0.0001,hi=1e9,ans=hi;
        for(int i=0;i<=200;i++){
            
            if(abs(hi-lo)<1e-9){
                break;
            }
            dd mid=(hi+lo)/2.00;
            double req=00.0;
            for(int i=0;i+1<n;i++){
                dd dist=stations[i+1]-stations[i];
                req=req+ceil(dist/mid)-1;
            }
            
            if(req<=k*1.00){
                ans=min(ans,mid);
                hi=mid;
            }else{
                lo=mid;
            }
        }
        
        return ans;
        
        
        
    }
};
