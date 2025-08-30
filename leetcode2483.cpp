class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int pre[n+1]; // no of N before kth hour
        int suff[n+1]; // no of Y after and icluding kth hour
        pre[0] = 0;
        for(int i = 0; i < n; i++)
        {
            int count = 0;
            if(customers[i]=='N') count++;
            pre[i+1] = pre[i]+count;
        }
        suff[n] = 0;
        for(int i = n-1; i >= 0; i--)
        {
            int count = 0;
            if(customers[i]=='Y') count++;
            suff[i] = suff[i+1]+count;
        }
        int min = INT_MAX;
        int idx = -1;
         for(int i = 0; i <= n; i++)
        {
            pre[i] += suff[i];
            if(pre[i]<min){
                min = pre[i];
                idx = i;
            }
        }
        return idx;
    }
};