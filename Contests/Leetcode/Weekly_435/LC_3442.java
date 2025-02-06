package Contests.Leetcode.Weekly_435;

class Solution {
    int delta_x(char ch){
        if(ch=='N'){
            return 1;
        }
        return -1;
    }

    int delta_y(char ch){
        if(ch=='E'){
            return 1;
        }
        return -1;
    }
    int getGreedy(String s,int k,char p,char q){
        int ret=0,x=0,y=0;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='N' || s.charAt(i)=='S'){

                if(s.charAt(i)!=p && k>0){
                    k--;
                    x+=delta_x(p);
                }else{
                    x+=delta_x(s.charAt(i));
                }

            }else{

                if(s.charAt(i)!=q && k>0){
                    k--;
                    y+=delta_y(q);
                }else{
                    y+=delta_y(s.charAt(i));
                }

            }

            ret=Math.max(ret,Math.abs(x)+Math.abs(y));
        }

        return ret;

    }
    public int maxDistance(String s, int k) {
        
        int ret=0;
        ret=Math.max(ret,getGreedy(s,k,'N','W'));
        ret=Math.max(ret,getGreedy(s,k,'N','E'));
        ret=Math.max(ret,getGreedy(s,k,'S','W'));
        ret=Math.max(ret,getGreedy(s,k,'S','E'));
        return ret;

    }
}