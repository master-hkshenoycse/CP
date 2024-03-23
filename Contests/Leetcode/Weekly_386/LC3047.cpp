/*https://leetcode.com/contest/weekly-contest-386/problems/find-the-largest-area-of-square-inside-two-rectangles/*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        ll n=bottomLeft.size();
        ll ans=0;
        
        for(ll i=0;i<n;i++){
            for(ll j=i+1;j<n;j++){
                ll x_len=max(0ll,min(topRight[i][0],topRight[j][0])*1ll-max(bottomLeft[i][0],bottomLeft[j][0])*1ll);
                ll y_len=max(0ll,min(topRight[i][1],topRight[j][1])*1ll-max(bottomLeft[i][1],bottomLeft[j][1])*1ll);
                
                //cout<<i<<" "<<j<<" "<<max(bottomLeft[i][0],bottomLeft[j][0])<<" "<<y_len<<endl;
                ans=max(ans,min(x_len,y_len)*min(x_len,y_len));
            }
        }
        
        return ans;
    }
};