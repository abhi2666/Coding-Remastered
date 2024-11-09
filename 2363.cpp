class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        unordered_map<int, int>mp;
        vector<vector<int>>ans;
        for(auto items : items1) {
            int id = items[0];
            int value = items[1];
            mp[id] += value;
        }
        for(auto items : items2) {
            int id = items[0];
            int value = items[1];
            mp[id] += value;
        }

        for(auto it : mp) {
            vector<int> temp = {it.first, it.second};
            ans.push_back(temp);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};