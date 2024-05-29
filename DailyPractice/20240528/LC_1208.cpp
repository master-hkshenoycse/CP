#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans=0,j=0,curr_cost=0,n=s.size();

        for(int i=0;i<n;i++){
            curr_cost=curr_cost+abs(s[i]-t[i]);
            while(curr_cost > maxCost){
                curr_cost-=abs(s[j]-t[j]);
                j++;
            }

            ans=max(ans,i-j+1);
        }

        return ans;

    }
};