#include<bits/stdc++.h>
using namespace std;

/*Given the total number of persons N and a number k which indicates that k-1 persons are skipped and the kth person is killed in a circle. 
The task is to choose the person in the initial circle that survives*/

int Josephus(int n,int k){
    int i=1,ans=0;

    while(i<=n){
        ans=(ans+k)%i;
        i++;
    }

    return ans+1;

}

int main()
{
 
    int N = 14, k = 2;
    cout << Josephus(N, k) << endl;
    return 0;
}
