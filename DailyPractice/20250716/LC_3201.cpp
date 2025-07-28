class Solution {
    public:
        int maximumLength(vector<int>& nums) {
            int i=0,n=nums.size(),segs=0,c1=0,c0=0;
            while(i<n){
                segs++;
                int j=i;
                while(j<n and (nums[i]-nums[j])%2==0){
                    if(nums[i]%2){
                        c1++;
                    }else{
                        c0++;
                    }
                    j++;
                }
    
                i=j;
            }
    
            return max(segs,max(c1,c0));
    
        }
    };