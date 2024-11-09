// class Solution {
// private:
//     bool isValid(string word) {
//         int n = word.size();
//         if(word[0]=='-' && word[n-1]=='-') return false;
//         if(word[n-1]!='!' && word[n-1]!='.' && word[n-1]!=',') return false;
//         int hyphenCount = 0, puncCount = 0;
//         for(char c : word) {
//             if(c >= '0' && c <= '9') return false;
//             if(c=='-') hyphenCount++;
//             if(c=='!' || c=='.' || c==',') puncCount++;
//             if(hyphenCount > 1 || puncCount > 1) return false; 
//         }
//         return true;
//     }
// public:
//     int countValidWords(string sentence) {
//         string temp = "";
//         int validWords = 0;
//         int i = 0;
//         while(i < sentence.size()){
//             if(sentence[i]==' ') {
//                 if(isValid(temp)) validWords++;
//                 temp = "";
//                 while(i < sentence.size() && sentence[i]==' ') i++;
//             }
//             else {
//                 temp+=sentence[i];
//                 i++;
//             }
//         }
//         if(isValid(temp)) validWords++;
//         return validWords;
        
//     }
// };

#include <string>
#include <sstream>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isValidWord(const string& word) {
        int n = word.size();
        bool hasHyphen = false;
        bool hasPunctuation = false;
        
        for (int i = 0; i < n; ++i) {
            if (isdigit(word[i])) {
                return false; // contains digit
            }
            if (word[i] == '-') {
                if (hasHyphen || i == 0 || i == n - 1 || !islower(word[i-1]) || !islower(word[i+1])) {
                    return false; // invalid hyphen usage
                }
                hasHyphen = true;
            }
            if (word[i] == '!' || word[i] == '.' || word[i] == ',') {
                if (hasPunctuation || i != n - 1) {
                    return false; // invalid punctuation usage
                }
                hasPunctuation = true;
            }
        }
        
        return true;
    }
    
    int countValidWords(string sentence) {
        istringstream ss(sentence);
        string token;
        int validWordCount = 0;
        
        while (ss >> token) {
            if (isValidWord(token)) {
                ++validWordCount;
            }
        }
        
        return validWordCount;
    }
};