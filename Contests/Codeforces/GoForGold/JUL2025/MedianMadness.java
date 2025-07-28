import java.util.Scanner;

public class MedianMadness{

    private static void solve_testcase(Scanner sc){
        int n,k;
        n=sc.nextInt();
        k=sc.nextInt();

        int values[]=new int[n];
        for(int i=0;i<n;i++){
            values[i]=sc.nextInt();
        }

        int answer=0;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=i;j<n;j++){
                if(values[j]>=k){
                    cnt++;
                }else{
                    cnt--;
                }

                if(cnt >= 0 && (j-i+1)%2==1){
                    answer++;
                }
            }
        }

        System.out.println(answer);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t;
        t=sc.nextInt();

        while(t>0){
            solve_testcase(sc);
            t--;
        }
    }
}