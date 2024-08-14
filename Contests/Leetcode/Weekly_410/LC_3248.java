package Contests.Leetcode.Weekly_410;
import java.util.*;



public class LC_3248 {
    class Solution {
        public int finalPositionOfSnake(int n, List<String> commands) {
            int x=0,y=0;
    
            for(String str:commands){
                if(str.equals("UP")){
                    x--;
                }else if(str.equals("RIGHT")){
                    y++;
                }else if(str.equals("DOWN")){
                    x++;
                }else{
                    y--;
                }
            }
    
            return x*n+y;
        }
    }
        
}

