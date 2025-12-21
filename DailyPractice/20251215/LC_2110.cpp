#include<bits/stdc++.h>
using namespace std;

#define ll long long
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        ll ans=0;
        ll i=0,n=prices.size();
        while(i<n){
            ll j=i+1,c=1;
            
            while(j<n and prices[j-1]-prices[j]==1){
                j++;
                c++;
            }
            
            ans=ans+(c*c+c)/2ll;
            
           // cout<<i<<" "<<c<<endl;
            i=j;
            
        }
        
        return ans;
    }
};