package Contests.Leetcode.Weekly_410;
import java.util.ArrayList;

public class LC_3249 {
    class Solution {
    int ans=0;

    int dfs(int v,int p,ArrayList<ArrayList<Integer> > tree){
        int cnt=0;
        int max_sz=-1,min_sz=100000;
        for(Integer to:tree.get(v)){
            if(to==p){
                continue;
            }
            int sz_subtree=dfs(to,v,tree);
            cnt=cnt+sz_subtree;
            max_sz=Math.max(max_sz,sz_subtree);
            min_sz=Math.min(min_sz,sz_subtree);
        }

        if(cnt==0){
            ans++;
        }else{
            if(max_sz==min_sz){
                ans++;
            }
        }

        cnt++;

        return cnt;

    }
    public int countGoodNodes(int[][] edges) {
        ArrayList<ArrayList<Integer> >  tree= new ArrayList< ArrayList <Integer> >();
        int n=edges.length+1;

        for(int i=0;i<n;i++){
            tree.add(new ArrayList<Integer> ());
        }   

        for(int i=0;i<n-1;i++){
            int x=edges[i][0];
            int y=edges[i][1];
            tree.get(x).add(y);
            tree.get(y).add(x);
        }

        dfs(0,-1,tree);

        return ans;
    }
}
};
    

