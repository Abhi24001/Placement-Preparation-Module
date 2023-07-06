class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mp;
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            mp.insert(nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i]-1)!=mp.end()){
                continue;
            }else{
              int count=0;int cp=nums[i];
              while(mp.find(cp)!=mp.end()) {
                  cp++;
                  count++;
                  maxi=max(count,maxi);
              }
            }
        }
        return maxi;
    }
};
