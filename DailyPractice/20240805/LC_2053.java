import java.util.*;

class Solution {
    public String kthDistinct(String[] arr, int k) {
        Map<String,Integer> cntString=new HashMap<String,Integer>();

        for(String curr:arr){
            if(cntString.containsKey(curr) ==  false){
                cntString.put(curr,0);
            }
            cntString.put(curr,cntString.get(curr)+1);
        }

        List<String> distinctList=new ArrayList<String> ();
        for(String curr:arr){
            if(cntString.get(curr) == 1){
                distinctList.add(curr);
            }
        }

        String sol="";
        if(distinctList.size()>=k){
            sol=distinctList.get(k-1);
        } 

        return sol;


    }
}