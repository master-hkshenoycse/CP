import java.util.*;
import java.io.*;
import java.lang.*;


class Solution
{
    public int firstElementKTime(int n, int k, int[] a) { 
        HashMap<Integer,Integer> help=new HashMap<>();
        
        
        for(int i=0;i<n;i++){
            Integer count=help.get(a[i]);
            if(count==null){
                help.put(a[i],1);
            }else{
                help.put(a[i],count+1);
            }
            
            if(help.get(a[i])>=k){
                return a[i];
            }
        }
        
        return -1;
        
        
        
    } 
}