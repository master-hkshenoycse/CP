#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n=nums.size(),ans=0;
        vector<int> sorted_arr=nums;
        sort(sorted_arr.begin(),sorted_arr.end());
        for(int i=1;i<=n;i++){
            if(n%i==0){
                vector<int> tmp=nums;
                int chunks_size=i;
                int no_of_chunks=n/i;
                int f=1;
                
                for(int ch=0;ch<no_of_chunks;ch++){
                    int min_index=-1;
                    int start_index=ch*chunks_size;
                    for(int ind=1;ind<chunks_size;ind++){
                        if(nums[ind+start_index-1]>nums[ind+start_index])
                            min_index=ind;
                    }

                    
                    for(int ind=0;ind<chunks_size;ind++){
                        if(min_index != -1)
                            tmp[start_index+ind]=nums[start_index+((min_index+ind)%chunks_size)];
                        
                        if(sorted_arr[start_index+ind] != tmp[start_index+ind]){
                            f=0;
                            break;
                        }
                    }



                    if(f==0)
                        break;
                }
                ans=ans+i*f;
            }
        }
        return ans;
    }
};