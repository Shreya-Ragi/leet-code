class Solution {
public:
    int count = 0;
    void check_stretchy(vector<pair<char, int>>& groups, vector<pair<char, int>>& wordgroups){
        for(int i = 0; i<groups.size(); i++){
            // cout << groups[i] << " " << wordgroups[i] << ",";
            if(groups[i].second < 3){
                if(groups[i].second != wordgroups[i].second){
                    count--;
                    return;
                }
            }
            else{
                if(groups[i].first != wordgroups[i].first || wordgroups[i].second > groups[i].second){
                    count--;
                    return;
                }
            }
        }
    }

    int expressiveWords(string s, vector<string>& words) {
        count = words.size();
        char currc = s[0];
        int sub = 0;
        vector<pair<char, int>> groups;
        for(int i=0; i< s.size(); i++){
            if(s[i] != currc){
                groups.push_back({currc, sub});
                sub = 1;
                currc = s[i];
            } 
            else sub += 1;
            if(i == s.size()-1) groups.push_back({s[i], sub});
        }
        for(string word : words){
            char currc = word[0];
            int sub = 0;
            vector<pair<char, int>> wordgroups;
            for(int i=0; i<word.size(); i++){
                if(word[i] != currc){
                    wordgroups.push_back({currc, sub});
                    sub = 1;
                    currc = word[i];
                } 
                else sub += 1;
                if(i == word.size()-1) wordgroups.push_back({word[i], sub});
            }
            if(groups.size() != wordgroups.size()){
                count--;
                continue;
            }
            check_stretchy(groups, wordgroups);
        }
        return count;
    }
};