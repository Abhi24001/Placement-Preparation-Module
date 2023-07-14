class Solution {
public:
    void solve(vector<int>& nums, vector<int>& output, vector<vector<int>>& ans, int index, vector<int> used) {
        if (output.size() == nums.size()) {
            ans.push_back(output);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if(!used[i]){
            used[i]=1;     // used for current recursive call
            output.push_back(nums[i]);
            solve(nums, output, ans, (index + 1) % nums.size(),used);
            output.pop_back();
            used[i]=0;  // set to unused for next recursion
        }
        
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        vector<int> used(nums.size(), 0);  // to keep track of repetition
        solve(nums, output, ans, 0, used);
        return ans;
    }
};
