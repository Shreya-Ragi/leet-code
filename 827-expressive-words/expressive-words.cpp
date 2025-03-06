class Solution {
public:
    int count = 0;
    void check_stretchy(vector<string>& groups, vector<string>& wordgroups){
        for(int i = 0; i<groups.size(); i++){
            // cout << groups[i] << " " << wordgroups[i] << ",";
            if(groups[i].size() < 3){
                if(groups[i] != wordgroups[i]){
                    count--;
                    return;
                }
            }
            else{
                if(groups[i][0] != wordgroups[i][0] || wordgroups[i].size() > groups[i].size()){
                    count--;
                    return;
                }
            }
        }
    }

    int expressiveWords(string s, vector<string>& words) {
        count = words.size();
        char currc = s[0];
        string sub = "";
        vector<string> groups;
        for(int i=0; i< s.size(); i++){
            if(s[i] != currc){
                groups.push_back(sub);
                sub = s[i];
                currc = s[i];
            } 
            else sub += s[i];
            if(i == s.size()-1) groups.push_back(sub);
        }
        for(string word : words){
            char currc = word[0];
            string sub = "";
            vector<string> wordgroups;
            for(int i=0; i<word.size(); i++){
                if(word[i] != currc){
                    wordgroups.push_back(sub);
                    sub = word[i];
                    currc = word[i];
                } 
                else sub += word[i];
                if(i == word.size()-1) wordgroups.push_back(sub);
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