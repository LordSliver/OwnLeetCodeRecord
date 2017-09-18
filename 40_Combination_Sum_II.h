class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> comb;
        process(candidates, result, comb, target, 0);
        return result;
    }
    void process(vector<int> candidates, vector<vector<int>> & result, vector<int> comb, int target, int begin){
        if(!target){
            result.push_back(comb);
        }
        for(int i = begin; i < candidates.size() && target >= candidates[i]; ++i){
            if(i == begin || candidates[i] != candidates[i - 1]){
                comb.push_back(candidates[i]);
                process(candidates, result, comb, target - candidates[i], i + 1);
                comb.pop_back();
            }
        }
    }
};