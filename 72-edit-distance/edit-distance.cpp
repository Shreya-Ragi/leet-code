class Solution {
public:
    int minDistance(string word1, string word2) {
        word1 = ' ' + word1;
        word2 = ' ' + word2;
        int i, j;
        int DP[word1.size()][word2.size()];
        for(i=0; i<word1.size(); i++){
            DP[i][0] = i;
        }
        for(i=0; i<word2.size(); i++){
            DP[0][i] = i;
        }

        for(i=1; i<word1.size(); i++){
            for(j=1; j<word2.size(); j++){
                DP[i][j] = std::min(std::min(DP[i-1][j]+1, DP[i][j-1]+1), DP[i-1][j-1]+ (word1[i] != word2[j])); 
            }
        }
        return DP[word1.size()-1][word2.size()-1];
    }
};