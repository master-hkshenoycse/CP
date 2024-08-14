

public class LC_719 {

    class Solution {
        public int smallestDistancePair(int[] nums, int k) {
            
            int n=nums.length;
            Arrays.sort(nums);
            int lo=0,hi=1000000,ans=hi;
    
            while(hi>=lo){
                int mid=(hi+lo)/2;
                int j=0,cnt=0;
    
                for(int i=0;i<n;i++){
                    while(j<i && nums[i]-nums[j]>mid){
                        j++;
                    }
                    cnt=cnt+(i-j);
                }
    
    
                if(cnt>=k){
                    ans=Math.min(ans,mid);
                    hi=mid-1;
                }else{
                    lo=mid+1;
                }
    
            }
    
            return ans;
    
        }
    }
    
}
