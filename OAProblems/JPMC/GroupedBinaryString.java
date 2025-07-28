//https://codeforces.com/blog/entry/145008
/*
Problem Statement: Count Grouped Binary Substrings
You are given a binary string s consisting of only '0' and '1'.

A binary substring is called grouped if: - All '0's come together followed by all '1's, or - All '1's come together followed by all '0's.

For example, "0011" or "1100" are grouped, but "0101" is not.

You need to count the number of such non-empty substrings where: - The number of consecutive '0's and '1's are equal, and - All '0's and '1's are grouped together (e.g. "01", "0011", "1100", "000111", etc.)

Input
A binary string s of length up to 10^5.

Output
An integer denoting the total number of valid grouped substrings.

Example
Input:
00110011
Output:
6
Explanation
The valid grouped substrings are: - "0011" - "01" (twice) - "1100" - "10" (twice)

Total = 6.
*/

import java.util.Scanner;

public class GroupedBinaryString{
    public static void main(String[] args) {
        int t;
        Scanner sc=new Scanner(System.in);
        
        t=sc.nextInt();
        sc.nextLine();
        while(t>0){
            String s;
            s=sc.nextLine();

            int n=s.length();
            int prev=0,ans=0,i=0;

            while(i<n){
                int j=i+1,cnt=1;
                while(j<n && s.charAt(j)==s.charAt(j-1)){
                    j++;
                    cnt++;
                }
                ans=ans+Math.min(cnt,prev);
                prev=cnt;
                i=j;
            }

            System.out.println(ans);
            t--;
        }
        
    }
}
