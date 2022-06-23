class Solution {
public:
    vector<int>original;
    vector<int>random;
    Solution(vector<int>& nums) {
        original.assign(nums.begin(),nums.end());
        random.assign(nums.begin(),nums.end());
    }
    
    vector<int> reset() {
        return original;
    }
    
    vector<int> shuffle() {
        random_shuffle(random.begin(),random.end());
        return random;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */