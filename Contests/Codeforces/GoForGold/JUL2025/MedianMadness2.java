import java.util.Scanner;

class FenwickTree{
    int n;
    Long[] bit;

    FenwickTree(int n){
        this.n = n;
        bit = new Long[n+1];
        for(int i=1;i<=n;i++){
            bit[i]=0L;
        }
    }

    public void update(int n,int index,Long value){
        while(index<=n){
            bit[index]+=value;
            index+=(index & (-index));
        }
    }

    public Long query(int index){
        Long ret=0L;
        
        while(index>0){
            ret=ret+bit[index];
            index-=(index & (-index));
        }

        return ret;
    }
}
public class MedianMadness2 {
    
    private static void solve_testcase(Scanner sc,Long mod){
        
        int n=sc.nextInt();
        int k=sc.nextInt();
        
        int[] values = new int[n+1];
        
        for(int i=1;i<=n;i++){
            values[i]=sc.nextInt();
        }

        FenwickTree evenTree = new FenwickTree(3*n+5);
        FenwickTree oddTree = new FenwickTree(3*n+5);

        Long answer=0L;
        int balance = n+1;
        
        evenTree.update(3*n, balance, 1L);

        for(int i=1;i<=n;i++){

            if(values[i]>=k){
                balance++;
            }else{
                balance--;
            }

            if(i%2==0){
                answer=answer+oddTree.query(balance);
                answer%=mod;
                evenTree.update(3*n, balance, 1L);
            }else{
                answer=answer+evenTree.query(balance);
                answer%=mod;
                oddTree.update(3*n, balance, 1L);
            }   
        }

        System.out.println(answer);
        
    }
    public static void main(String[] args) {
        Long mod = 1000000007L;
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();
        while(t>0){
            solve_testcase(sc,mod);
            t--;
        }

    }   
}
