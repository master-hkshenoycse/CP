import java.util.*;

public class LC_624 {

    class Solution {
        public int maxDistance(List<List<Integer>> arrays) {
            int lo=arrays.get(0).get(0);
            int hi=arrays.get(0).get(arrays.get(0).size()-1);
            int m=arrays.size(),ans=0;
            for(int i=1;i<arrays.size();i++){
                int len=arrays.get(i).size();
                ans=Math.max(ans,Math.abs(arrays.get(i).get(0)-hi));
                ans=Math.max(ans,Math.abs(arrays.get(i).get(0)-lo));
    
                ans=Math.max(ans,Math.abs(arrays.get(i).get(len-1)-hi));
                ans=Math.max(ans,Math.abs(arrays.get(i).get(len-1)-lo));
    
                lo=Math.min(lo,arrays.get(i).get(0));
                hi=Math.max(hi,arrays.get(i).get(len-1));
            }
    
            return ans;
        }
    }
    
}
