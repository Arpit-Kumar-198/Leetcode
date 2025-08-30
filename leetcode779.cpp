class Solution {
public:
    int kthGrammar(int n, int k) {
       if(n==1) return 0;
       if(k%2==0)   // k is even
       {
            int prevAns = kthGrammar(n-1,k/2);
            if(prevAns==0) return 1;
            else return 0;
       }
       else     //k is odd
       {
            int prevAns = kthGrammar(n-1,k/2+1);
            return prevAns;
       }
    }
};
/*  n = 3, k = 3 then ans = 1

                0
        0               1
    0       1       1       0
*/