//reverse word in string
class Solution {
public:
    string reverseWords(string s) {
        //using new feature 
        istringstream ss(s);
        string word;
        string ans = "";
        while(ss >> word) {
            word = " " + word;
            ans = word+ans;
        }
        return ans.substr(1, ans.size());
    }
};