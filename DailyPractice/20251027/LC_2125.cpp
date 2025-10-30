#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int c=0,ans=0,n=bank.size();
        for(int i=n-1;i>=0;i--){
            int x=0;
            for(int j=0;j<bank[i].size();j++){
                x+=(bank[i][j]=='1');
            }
            if(x>0){
                ans=ans+x*c;
                c=x;
            }
        }
        return ans;
        
    }
};