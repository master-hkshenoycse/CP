
import java.util.Scanner;

public class BobAndCanon {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t=sc.nextInt();

        while(t>0){
            int n = sc.nextInt();
            int m = sc.nextInt();
            int x = sc.nextInt();
            int y = sc.nextInt();
            int cx=0,cy=0;
            sc.nextLine();
            x--;
            y--;

            char[][] battleField = new char[n][m];

            for(int i=0;i<n;i++){
                String line = sc.nextLine();
                for(int j=0;j<m;j++){
                    battleField[i][j]=line.charAt(j);
                    if(battleField[i][j] == 'c'){
                        cx=i;
                        cy=j;
                    }
                }
                System.out.println(line);
            }

            int poss=0;

            if(cx==x && cy-1>=0 && battleField[cx][cy-1]=='.'){
                poss=1;
            }

            if(cx==x && cy+1<m && battleField[cx][cy+1]=='.'){
                poss=1;
            }

            if(cy==y && cx-1>=0 && battleField[cx-1][cy]=='.'){
                poss=1;
            }

            if(cy==y && cx+1<n && battleField[cx+1][cy]=='.'){
                poss=1;
            }

            if(poss==1){
                System.out.println("Yes");
            }else{
                System.out.println("No");
            }


            t--;

        }

        
    }   
}
