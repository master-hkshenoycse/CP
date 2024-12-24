#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans=0,n=arr.size();
        int prev_max=-1,curr_max=-1,curr_min=n+1,len=0;

        for(int i=0;i<n;i++){
            curr_max=max(curr_max,arr[i]);
            curr_min=min(curr_min,arr[i]);
            len++;
            
            if(curr_min==prev_max+1 and curr_min+len-1==curr_max){
                //cout<<len<<" "<<curr_min<<" "<<curr_max<<endl;
                ans++;
                len=0;
                prev_max=curr_max;
                curr_min=n+1;
                curr_max=-1;
            }
        }


        return ans;


    }
};