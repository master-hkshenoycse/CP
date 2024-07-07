#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n=colors.size(),ans=0;

        for(int i=0;i<n;i++){
            int prev=-1,f=1;
            for(int j=0;j<3;j++){
                int ind=(i+j)%n;
                if(prev!=-1){
                    if(colors[ind] == prev){
                        f=0;
                        break;
                    }
                }
                prev=colors[ind];
            }
            ans=ans+f;
        }

        return ans;
    }
};