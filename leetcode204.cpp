// very famous
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

    int countPrimes(int n) {
        if(n==0 || n==1 || n==2) return 0;
        if(n==3) return 1;
        if(n==4) return 2;
        vector<bool> sieve(n+1,true);
        sieve[0] = false;
        sieve[1] = false;
        for(int i = 2; i <= sqrt(n); i++)
        {
            int j = i+i;
            while(j<=n)
            {
                sieve[j] = false;
                j += i;
            }
        }
        int count = 0;
        if(sieve[n]==true) sieve[n]=false;
        for(int i = 2; i <= n; i++)
        {
           if(sieve[i]==true) count++;
        }
        return count;
    }
int main()
{
    int n;
    cin >> n;
    cout << countPrimes(n);
}
