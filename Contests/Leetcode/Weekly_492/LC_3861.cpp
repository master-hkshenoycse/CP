#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int ret_ind=-1,ret_max=INT_MAX;

        for(int i=0;i<capacity.size();i++){
            if(capacity[i]>=itemSize){
                if(ret_max>capacity[i]){
                    ret_max=capacity[i];
                    ret_ind=i;
                }
            }
        }

        return ret_ind;
    }
};