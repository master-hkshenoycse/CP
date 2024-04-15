import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;



class Result {

    /*
     * Complete the 'validateRequests' function below.
     *
     * The function is expected to return an INTEGER_ARRAY.
     * The function accepts following parameters:
     *  1. STRING_ARRAY blacklisted_ips
     *  2. STRING_ARRAY requests
     */
     
    public static boolean checkMatch(String a,String b,int i,int j,int n,int m,int [][]memo){
        if(i==n && j==m){
            return true;
        }
        
        if(i==n){
            return false;
        }   
        
        
        
        if(memo[i][j] != -1){
            if(memo[i][j]==1){
                return true;
            }else{
                return false;
            }
        }
        
        if(a.charAt(i)=='*'){
            boolean res=checkMatch(a, b, i, j+1, n, m,memo) || checkMatch(a, b, i+1, j, n, m,memo); 
            if(res){
                memo[i][j]=1;
            }else{
                memo[i][j]=0;
            }
            return res;
        }
        
        if(a.charAt(i) != b.charAt(j)){
            memo[i][j]=0;
            return false;
        }
        
        boolean res=checkMatch(a, b, i+1, j+1, n, m,memo);
        
        if(res){
            memo[i][j]=1;
        }else{
            memo[i][j]=0;
        }
        
        return res;
        
    
    }
    public static List<Integer> validateRequests(List<String> blacklisted_ips, List<String> requests) {
    // Write your code here
      List<Integer> sol=new ArrayList<>();
       
        for(String request:requests){
            boolean isMatch=false;
            
            for(String p:blacklisted_ips){
                int n=p.length();
                int m=request.length();
                int memo[][]=new int[n+1][m+1];
                
                for(int i=0;i<n;i++){
                    for(int j=0;j<m;j++){
                        memo[i][j]=-1;
                    }
                }
                if(checkMatch(p, request, 0, 0, n, m,memo)){
                    isMatch=true;
                    break;
                }
            }
            
            if(isMatch){
                sol.add(1);
            }else{
                sol.add(0);
            }
        }
        
        
        return sol;

    }

}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int blacklisted_ipsCount = Integer.parseInt(bufferedReader.readLine().trim());

        List<String> blacklisted_ips = IntStream.range(0, blacklisted_ipsCount).mapToObj(i -> {
            try {
                return bufferedReader.readLine();
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        })
            .collect(toList());

        int requestsCount = Integer.parseInt(bufferedReader.readLine().trim());

        List<String> requests = IntStream.range(0, requestsCount).mapToObj(i -> {
            try {
                return bufferedReader.readLine();
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        })
            .collect(toList());

        List<Integer> result = Result.validateRequests(blacklisted_ips, requests);

        bufferedWriter.write(
            result.stream()
                .map(Object::toString)
                .collect(joining("\n"))
            + "\n"
        );

        bufferedReader.close();
        bufferedWriter.close();
    }
}
