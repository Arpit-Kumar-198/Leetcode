class Solution {
    public:
        int largestRectangleArea(vector<int>& heights) {
            int n = heights.size();
            vector<int> arr1(n,0);
            vector<int> arr2(n,n-1);
            arr1[0] = 0;
            int i = 1; 
            stack<int> st1;
            st1.push(0);
            while(i < n){
                while(st1.size()!= 0 && heights[st1.top()]>=heights[i]){
                    st1.pop();
                }
                if(st1.size()==0) arr1[i] = 0;
                else arr1[i] = st1.top() + 1;
                st1.push(i);
                i++;
            }
            arr2[n-1] = n-1;
            i = n-2; 
            stack<int> st2;
            st2.push(n-1);
            while(i >= 0){
                while(st2.size()!= 0 && heights[st2.top()]>=heights[i]){
                    st2.pop();
                }
                if(st2.size()==0) arr2[i] = n-1;
                else arr2[i] = st2.top() - 1;
                st2.push(i);
                i--;
            }
            int ans = 0;
            for(int i = 0; i < n; i++){
                int x = (arr2[i]-arr1[i]+1)*heights[i];
                ans = max(ans,x);
            }
            return ans;
        }
    };