// class Solution { not working !!
// public:
//     bool isSubsequence(string s, string t) {
//         int i = 0, j = 0;
//         while(j < t.size()) {
//             while(j < t.size() && t[j] != s[i]) j++;
//             j++;
//             i++; 
//         }
//         if(i == s.size()-1) return true;
//         else return false;
//     }
// };

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while (j < t.size() && i < s.size()) {
            if (t[j] == s[i]) {
                i++;
            }
            j++;
        }
        return i == s.size();
    }
};
