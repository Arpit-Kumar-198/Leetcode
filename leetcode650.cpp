class Solution {
public:

class Solution {
public:
int highestFactor(int n)
{
    int hf = n;
    for(int i = n-1; i >= 1; i--)
    {
        if(n%i == 0)
        {
            hf = i;
            break;
        }
    }
    return hf;
}
    int minSteps(int n) {
        if(n==1) return 0;
        int ans = 0;
        while(n != 1)
        {
           int hf = highestFactor(n);
           ans += (n/hf);
           n = hf;
        }
        
        return ans;
    }
};



// 2nd method
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
    else return flag;
}
    int minSteps(int n) {
        if(n==1) return 0;
        int ans = 0;
        vector<int> fact;
        while(n != 1)
        {
            for(int i = 2; i <= n; i++)
            {
                if(n%i == 0 && prime(i))
                {
                    fact.push_back(i);
                    n /= i;
                }
            }
        }
        for(int i = 0; i < fact.size(); i++) ans += fact[i];
        return ans;
    }
};