class Solution {
public:
bool prime(int num)
{
     bool flag = true;
    for(int i = 2; i <= sqrt(num); i++)
    {
        if(num%i == 0){
            flag = false;
            break;
        }
    }
    if(num == 1) return false;
    return flag;
}
    int smallestValue(int n) {
        if(prime(n)) return n;
        int f = 0;
        for(int i = 1; i < sqrt(n); i++)    // sqrt(15) will be 3.87298     3 < 3.87298 will be true
        {
            if(n%i==0 && prime(i))
            {
                int m = n;
                while(m%i == 0)
                {
                    f += i;
                    m /= i;
                }
            }
        }
        for(int i = sqrt(n); i >= 1; i--)
        {
            if(n%i==0 && prime(n/i))
            {
                int m = n;
                while(m%(n/i) == 0)
                {
                    f += n/i;
                    m /= (n/i);
                }
            }
        }
        if(n==4) return n;
        return smallestValue(f);

    }
};