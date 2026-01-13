#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        int penalty=INT_MAX;
        vector<int> csum(n,0);
        for(int i=0;i<n;i++){
            if(customers[i]=='N'){
                csum[i]=1;
            }

            if(i-1>=0){
                csum[i]+=csum[i-1];
            }
        }

        penalty=csum[n-1];
        int ans=n;

        int cnt_y=0;
        for(int i=n-1;i>=0;i--){
            int prev=0;
            if(customers[i]=='Y'){
                cnt_y++;
            }

            if(i-1>=0){
                prev=csum[i-1];
            }
            if(cnt_y+prev<=penalty){
                penalty=cnt_y+prev;
                ans=i;
            }
        }

        return ans;
    }
};