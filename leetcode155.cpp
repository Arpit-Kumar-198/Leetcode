class MinStack {
    public:
    stack<long long> st;
    long long min;
    // stack<int> helper;
        MinStack() {
            min = LLONG_MAX;
        }
        
        void push(int val) {
            // st.push(val);
            // if(helper.size()==0 || val<helper.top()) helper.push(val);
            // else helper.push(helper.top());
    
            long long x = (long long)val;
            if(st.size()==0){
                st.push(x);
                min = x;
            }
            else if(x>=min){
                st.push(x);
                
            }
            else {
                st.push(2*x-min);
                min = x;
            }
        }
        
        void pop() {
            // st.pop();
            // helper.pop();
            if(st.top()>=min) st.pop();
            else{
                long long oldMin = 2*min - st.top();
            
                min = oldMin;
                st.pop();
            }
        }
        
        int top() {
            // return st.top();
    
            if(st.top()>=min) return (int)st.top();
             
             return (int)min;
    
        }
        
        int getMin() {
            // return helper.top();
            return (int)min;
        }
    };
    
    /**
     * Your MinStack object will be instantiated and called as such:
     * MinStack* obj = new MinStack();
     * obj->push(val);
     * obj->pop();
     * int param_3 = obj->top();
     * int param_4 = obj->getMin();
     */