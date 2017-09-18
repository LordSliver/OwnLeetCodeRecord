class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        
        std::sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ++i){
            int front = i + 1, back = nums.size() - 1, target = -nums[i];
            while(front < back){
                if (nums[front] + nums[back] < target)
                    front++;
                else if(nums[front] + nums[back] > target)
                    back--;
                else {
                    vector<int> three(3, 0);
                    three[0] = nums[i];
                    three[1] = nums[front];
                    three[2] = nums[back];
                    result.push_back(three);
                    
                    while(front < back && nums[front] == three[1]) front++;
                    while(front < back && nums[back] == three[2]) back--;
                }
            }
            while(i+1 < nums.size() && nums[i+1] == nums[i]) i++;
        }
        return result;
    }
};