//User function Template for Java
import java.util.*;
import java.io.*;

class CusomStringComparator implements Comparator<String> {

    @Override
    public int compare(String a,String b) {
        
        String x=a+b;
        String y=b+a;
        return y.compareTo(x);

    }

}
class Solution {
    
    
    String printLargest(int n, String[] arr) {
        // code here
        Arrays.sort(arr,new CusomStringComparator());
        
        String sol="";
        
        for(String s:arr){
            sol=sol+s;
        }
        
        return sol;
        
        
    }
}

