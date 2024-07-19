
class Solution {
    public List<Integer> luckyNumbers (int[][] matrix) {
        int n=matrix.length;
        int m=matrix[0].length;
        int row_min[]=new int[n];
        int col_max[]=new int[m];
        for(int i=0;i<n;i++){
            row_min[i]=Integer.MAX_VALUE;
        }

        for(int j=0;j<m;j++){
            col_max[j]=0;
        }

        List<Integer> sol=new ArrayList<>();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                row_min[i]=Math.min(row_min[i],matrix[i][j]);
                col_max[j]=Math.max(col_max[j],matrix[i][j]);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==row_min[i] && matrix[i][j]==col_max[j]){
                    sol.add(matrix[i][j]);
                }
            }
        }

        return sol;
    }
}