class Solution {
    public:
        int countStudents(vector<int>& students, vector<int>& sandwiches) {
            int n0st = 0;
            int n1st = 0;
            int n0sw = 0;
            int n1sw = 0;
            for(int i = 0; i < students.size(); i++){
                 if(students[i]==0) n0st++;
                 else n1st++;
            }
            for(int i = 0; i < sandwiches.size(); i--){
                 if(sandwiches[i]==0) n0sw++;
                 else n1sw++;
            }
    
            while(n0st > 0 && n1st > 0){
                if(students.front()==sandwiches.front()){
                    if(students.front()==1){
                        n1sw--;
                        n1st--;
                    }
                    else{
                        n0st--;
                        n0sw--;
                    }
                    students.erase(students.begin(), students.begin() + 1);
                    sandwiches.erase(sandwiches.begin(),sandwiches.begin()+1);
                }
                else {
                    int t = students.front();
                    students.erase(students.begin(), students.begin() + 1);
                    students.push_back(t);
                }
            }
            if(n0st==0 && n1st==0) return 0;
               int c = 0;
                    if(students.front()==0){
                         while(sandwiches.size()!=0 && sandwiches.front()!=1) {
                            c++;
                            sandwiches.erase(sandwiches.begin(),sandwiches.begin()+1);
                        }
                    }
                    else{
                        while(sandwiches.size()!=0 && sandwiches.at(0)!=0) {
                            c++;
                            sandwiches.erase(sandwiches.begin(),sandwiches.begin()+1);
                        }
                    }
                return students.size()-c;
           
        }
    };