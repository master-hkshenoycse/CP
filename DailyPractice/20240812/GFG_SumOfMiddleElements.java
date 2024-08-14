import java.util.*;


public class GFG_SumOfMiddleElements {
    public int SumofMiddleElements(int[] arr1, int[] arr2) {
        // code here
        
        
        int n=arr1.length,m=arr2.length;
    
        if(n>m){
            return SumofMiddleElements(arr2,arr1);
        }
        
        int req=(n+m+1)/2;
        int lo=0,hi=Math.min(n,req);
        
        while(hi>=lo){
            int mid=(hi+lo)/2;
            
            int ind_p1=mid;
            int ind_p2=req-ind_p1;
            
            int p1_left_max=(ind_p1 > 0)?arr1[ind_p1-1]:Integer.MIN_VALUE;
            int p1_right_min=(ind_p1 < n)?arr1[ind_p1]:Integer.MAX_VALUE;
            int p2_left_max=(ind_p2 >0 )? arr2[ind_p2-1]:Integer.MIN_VALUE;
            int p2_right_min=(ind_p2 < m)? arr2[ind_p2]:Integer.MAX_VALUE;
            
            if(p1_left_max <= p2_right_min && p2_left_max <= p1_right_min){
                return Math.max(p1_left_max,p2_left_max)+Math.min(p1_right_min,p2_right_min);
            }
            
            if(p1_left_max > p2_right_min){
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        
        return -1;
    }
}