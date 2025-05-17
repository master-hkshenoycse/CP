#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        ll s=0,ma=-1e10,mi=1e10;
        int n=differences.size();
        for(int i=0;i<n;i++){
            s=s+differences[i]*1ll;
            ma=max(ma,s);
            mi=min(mi,s);
        }
        ll hi=upper-ma;
        ll lo=lower-mi;
        
        if(hi>upper)hi=upper;
        if(lo<lower)lo=lower;
        cout<<hi<<" "<<lo<<endl;
        ll ans=max(0ll,hi-lo+1);
        
        return ans;
        
        
    }
};