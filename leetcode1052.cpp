class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();

        int preLoss = 0;

        if(n == 1)
        {
            if(grumpy[0]==0) return customers[0];
            else
            {
                if(minutes > 0) return customers[0];
                else return 0;
            }
        }
        for(int i = 0; i < minutes; i++)
        {
            if(grumpy[i]==1) preLoss += customers[i];
            
        }
        int maxLoss = preLoss;
        int idx = 0;    //very important
        int i = 1, j = minutes;
        while(j < n)
        {
            int currLoss = preLoss;
            if(grumpy[j]==1) currLoss += customers[j];
            if(grumpy[i-1]==1) currLoss -= customers[i-1];
            if(maxLoss < currLoss)
            {
                maxLoss = currLoss;
                idx = i;
            }
            preLoss=currLoss;
            i++,j++;
        }
        int satisfy = 0;
        for(int j = idx; j < idx+minutes; j++) grumpy[j]=0;
        for(int j = 0; j < n; j++)
        {
            if(grumpy[j]==0) satisfy += customers[j];
        }

        return satisfy;
    }
};