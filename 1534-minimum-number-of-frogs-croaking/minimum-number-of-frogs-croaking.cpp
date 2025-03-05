class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        std::map<char, int> idx_map = {{'c',0},{'r',1},{'o',2},{'a',3},{'k',4}};
        std::vector<int> counts = {0, 0, 0, 0, 0};
        std::string s = "croak";
        int idx, active = 0, minFrogs = 0;
        for(char c:croakOfFrogs){
            idx = idx_map[c];
            if(idx == 0){
                active++;
                minFrogs = std::max(minFrogs, active);
            }
            else{
                if(counts[idx-1] == 0) return -1;
                else counts[idx-1] -= 1;
            }
            if(idx == 4) active--;
            else counts[idx] +=1;
        }
        if(counts[0] || counts[1] || counts[2] || counts[3] || counts[4]){
            return -1;
        }
        return minFrogs;
    }
};