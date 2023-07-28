class Solution {
public:
    void helper(vector<int>& temp, vector<vector<int>>& ans, int index, int sum, int target, vector<int>& candidates) {
        if (sum == target) {
            ans.push_back(temp);
            return;
        }
        if (index == candidates.size() || sum > target) {
            return;
        }
        // Pick the current candidate.
        sum += candidates[index];
        temp.push_back(candidates[index]);
        helper(temp, ans, index + 1, sum, target, candidates);
        temp.pop_back();
        sum -= candidates[index];
        
        // Skip duplicates.
        while (index + 1 < candidates.size() && candidates[index] == candidates[index + 1]) {
            index++;
        }
        
        // Move to the next candidate.
        helper(temp, ans, index + 1, sum, target, candidates);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // Sort the candidates for easier duplicate handling.
        vector<vector<int>> ans;
        vector<int> temp;
        int sum = 0;
        int index = 0;
        helper(temp, ans, index, sum, target, candidates);
        return ans;
    }
};
