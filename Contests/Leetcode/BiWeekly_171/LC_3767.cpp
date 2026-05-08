#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        ll n=technique1.size();
        vector<ll> gains_1;
        ll ret=0;
        for(ll i=0;i<n;i++){
            ret+=technique2[i];
            gains_1.push_back(technique1[i]-technique2[i]);
        }

        sort(gains_1.begin(),gains_1.end());
        reverse(gains_1.begin(),gains_1.end());

        for(ll i=0;i<n;i++){
            if(i<k){
                ret+=gains_1[i];
            }else{
                ret+=max(0ll,gains_1[i]);
            }
        }

        return ret;
    }
};