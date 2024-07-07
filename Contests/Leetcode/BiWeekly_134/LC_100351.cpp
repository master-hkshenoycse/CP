#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int ans=0,i=0,n=colors.size();

        for(int i=0;i<k-1;i++){
            colors.push_back(colors[i]);
        }
        n+=(k-1);
        while(i<n){
            int c=1,j=i+1;
            while(j<n){
                if(colors[j] == colors[j-1]){
                    break;
                }

                j++;
                c++;
            }

            if(c>=k){
                ans=ans+c-k+1;
            }
            i=j;
        }

        return ans;
    }
};