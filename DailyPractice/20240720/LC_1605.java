class Solution {
    public int[][] restoreMatrix(int[] rowSum, int[] colSum) {
        int n=rowSum.length;
        int m=colSum.length;
        int sol[][]=new int[n][m];

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sol[i][j]=Math.min(rowSum[i],colSum[j]);
                rowSum[i]-=sol[i][j];
                colSum[j]-=sol[i][j];
            }
        }

        return sol;
    }
}