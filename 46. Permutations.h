class Solution {
public:
    vector<vector<int>> permute(vector<int>& num) {
        vector<vector<int>> result;
        result.push_back(num);
        
        if(num.size() < 2){
            return result;
        }
        int time = 1;
        for(int i = num.size(); i > 1; --i){
            time *= i;
        }
        
        for(time--; time > 0; --time){
            int i;
            for(i = num.size() - 2; i >= 0 ;--i)
                if(num[i] < num[i + 1])
                    break;
            reverse(begin(num) + i + 1, end(num));
            if(i > -1){
                auto itr = upper_bound(begin(num) + i + 1, end(num), num[i]);
                swap(num[i], *itr);
            }
            result.push_back(num);
        }
        return result;
    }
};