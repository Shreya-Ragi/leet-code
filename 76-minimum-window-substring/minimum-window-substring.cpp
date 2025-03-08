class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";
        int left = 0;
        int right = 0;
        map<char, int> count_map;
        for(char c:t){
            count_map[c]++;
        }
        int tno = t.size();
        int min_k = INT_MAX;
        int win;

        while(right <= s.size()){
            if(tno == 0){
                if(count_map[s[left]] == 0){
                    int k = right - left;
                    if(k < min_k)
                    {
                        min_k = k;
                        win = left;
                    }
                    count_map[s[left]]++;
                    left++;
                    tno++;
                }
                else{
                    count_map[s[left]]++;
                    left++;
                    continue;
                }
            }
            if(count_map[s[right]]>0) tno--;
            count_map[s[right]]--;
            right++;
        }
        if(min_k == INT_MAX) return "";
        return s.substr(win, min_k);
    }
};