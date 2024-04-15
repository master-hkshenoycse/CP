#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int ans=0;
        int lo=0,hi=n-1,left_max=0,right_max=0;

        while(hi>=lo){

            if(height[lo] < height[hi]){

                if(height[lo]<left_max){    
                    ans=ans+left_max-height[lo];
                }else{
                    left_max=height[lo];
                }

                lo++;

            }else{

                if(height[hi]<right_max){
                    ans=ans+right_max-height[hi];
                }else{
                    right_max=height[hi];
                }

                hi--;
            }
            
        }

        return ans;
    }
};