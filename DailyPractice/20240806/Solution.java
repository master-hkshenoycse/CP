
import java.util.*;

public class Solution {
    public int minimumPushes(String word) {
        int n=word.length(),pos_1_rem=8,pos_2_rem=8,pos_3_rem=8,pos_4_rem=2;
        Integer freqChar[]=new Integer[26];
        for(int i=0;i<26;i++){
            freqChar[i]=new Integer(0);
        }
        for(int i=0;i<n;i++){
            freqChar[word.charAt(i)-'a']++;
        }

        Arrays.sort(freqChar,Collections.reverseOrder());

        int ans=0;

        for(int i=0;i<26;i++){
            if(pos_1_rem>0){
                ans=ans+freqChar[i];
                pos_1_rem--;
            }else if(pos_2_rem>0){
                ans=ans+freqChar[i]*2;
                pos_2_rem--;
            }else if(pos_3_rem>0){
                ans=ans+freqChar[i]*3;
                pos_3_rem--;
            }else{
                ans=ans+freqChar[i]*4;
                pos_4_rem--;
            }
        }


        return ans;
    }
} {
    
}
