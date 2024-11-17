class Solution {
    public int[] resultsArray(int[] nums, int k) {
        int n=nums.length;
        int suff_len[]=new int[n];
        int res[]=new int[n-k+1];
        
        for(int i=n-1;i>=0;i--){
            suff_len[i]=1;
            if(i+1<n && nums[i+1]==nums[i]+1){
                suff_len[i]=suff_len[i+1]+1;
            }

        }

        for(int i=0;i+k-1<n;i++){
            if(suff_len[i]>=k){
                res[i]=nums[i+k-1];
            }else{
                res[i]=-1;
            }
        }
        return res;
    }
}