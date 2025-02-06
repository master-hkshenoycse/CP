package Contests.Leetcode.Weekly_435;

import java.util.HashMap;


class Solution {
    public int maxDifference(String s) {
        HashMap<Integer,Integer> freqCnt=new HashMap<Integer,Integer>();

        for( int i = 0; i < s.length(); i++){
            int key=s.charAt(i)-'a';
            if(freqCnt.containsKey(key) == false){
                freqCnt.put(key,1);
            }else{
                freqCnt.put(key,freqCnt.get(key)+1);
            }
        }

        int ret=Integer.MIN_VALUE;

        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                if(freqCnt.containsKey(i) && freqCnt.containsKey(j)){
                    int x=freqCnt.get(i);
                    int y=freqCnt.get(j);
                    int diff=Math.abs(-freqCnt.get(j));
                    if( x%2==0 && (y%2)>0){
                        ret=Math.max(ret,y-x);
                    }
                } 
            }
        }

        return ret;

    }
}