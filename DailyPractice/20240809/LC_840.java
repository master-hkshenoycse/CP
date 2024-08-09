class Solution {
    public int numMagicSquaresInside(int[][] grid) {
        int row=grid.length;
        int col=grid[0].length;
        int ans=0;
        for(int i=0;i+2<row;i++){
            for(int j=0;j+2<col;j++){

                int valid=1;
                int cnt[]=new int[10];

                for(int p=0;p<3;p++){
                    for(int q=0;q<3;q++){
                        if(grid[i+p][j+q]<1 || grid[i+p][j+q]>9){
                            valid=0;
                        }else{
                            cnt[grid[i+p][j+q]]++;
                        }
                    }
                }

                for(int k=1;k<=9;k++){
                    if(cnt[k] != 1){
                        valid=0;
                    }
                }

                //System.out.println(i+ " "+j);

                if(grid[i][j]+grid[i][j+1]+grid[i][j+2] != 15){
                    valid=0;
                }

                if(grid[i+1][j]+grid[i+1][j+1]+grid[i+1][j+2] != 15){
                    valid=0;
                }

                if(grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2] != 15){
                    valid=0;
                }

                if(grid[i][j]+grid[i+1][j]+grid[i+2][j] != 15){
                    valid=0;
                }

                if(grid[i][j+1]+grid[i+1][j+1]+grid[i+2][j+1] != 15){
                    valid=0;
                }

                if(grid[i][j+2]+grid[i+1][j+2]+grid[i+2][j+2] != 15){
                    valid=0;
                }

                if(grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2] != 15){
                    valid=0;
                }

                if(grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j] != 15){
                    valid=0;
                }

                //System.out.println(valid);


                ans=ans+valid;
            }
        }

        return ans;
    }
}