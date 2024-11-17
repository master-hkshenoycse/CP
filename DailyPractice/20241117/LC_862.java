import java.util.ArrayDeque;

class Solution {
    public int shortestSubarray(int[] nums, int k) {
        long cs=0;
        int n=nums.length;
        long csum[]=new long[n+1];
        csum[0]=0;
        
        for(int i=1;i<=n;i++){
            csum[i]=csum[i-1]+nums[i-1]*1L;
        }

        ArrayDeque<Integer> dq=new ArrayDeque<>();
        dq.addLast(0);
        int ans=n+1;

        for(int i=1;i<=n;i++){
            
            while(!dq.isEmpty() && csum[i]<=csum[dq.getLast()]){
                dq.removeLast();
            }

            while(!dq.isEmpty() && csum[i]-csum[dq.getFirst()]>=k){
                ans=Math.min(ans,i-dq.getFirst());
                dq.removeFirst();
            }


            dq.addLast(i);
        }

        if(ans==n+1){
            ans=-1;
        }
        
        return ans;
    }
}