class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<string> t1;
        vector<string> t2;

        for(int i = 0; i < version1.size(); i++){
            string temp = "";
            while(version1[i] >= '0' && version1[i] <= '9'){
                temp += version1[i];
                i++;
            }
            t1.push_back(temp);
        }

    for(int i = 0; i < version2.size(); i++){
        string temp = "";
        while(version2[i] >= '0' && version2[i] <= '9'){
            temp += version2[i];
            i++;
        }
        t2.push_back(temp);
    }

    int lo = 0, hi = 0;
    while(lo < t1.size() && hi < t2.size()){
        if(stoi(t1[lo]) < stoi(t2[hi])) return -1;
        else if(stoi(t1[lo]) > stoi(t2[hi])) return 1;
        else lo++,hi++;
    }
    while(lo < t1.size() && stoi(t1[lo]) == 0) lo++;
    while(hi < t2.size() && stoi(t2[hi]) == 0) hi++;
    if(lo < t1.size()) return 1;
    if(hi < t2.size()) return -1;
    return 0;
   }
};