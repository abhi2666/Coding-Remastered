class Solution {
private:
    vector<char> countDigits(int num) {
        vector<char>digits;
        while(num > 0) {
            int digit = num%10;
            char c = digit+'0';
            digits.push_back(c);
            num/=10;
        }
        return digits;
    }
public:
    int compress(vector<char>& chars) {
        int ans = 0;
        int i = 0; 
        vector<int>res;
        int n = chars.size();
        while(i < n) {
            char curr = chars[i];
            int cnt = 0;
            while(i < n && chars[i]==curr) {
                i++;
                cnt++;
            }
            ans++;
            res.push_back(curr);
            if(cnt>1) {
                vector<char> digits = countDigits(cnt);
                reverse(digits.begin() ,digits.end());
                ans+= digits.size();
                for(auto digit : digits) res.push_back(digit);
            }
            //now update the chars array
            chars.clear();
            for(auto ele : res) {
                chars.push_back(ele);
            }
        }
        return ans;
    }
};