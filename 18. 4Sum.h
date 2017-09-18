class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& num, int target) {
        vector<vector<int>> result;
        int n = num.size();
        if(n < 4)
            return result;
        std::sort(num.begin(), num.end());
        for(int i = 0; i < n - 3; ++i){
            if(i > 0 && num[i] == num[i-1]) continue;
            if(num[i] + num[i+1] + num[i+2] + num[i+3] > target) break;
            if(num[i] + num[n-3] + num[n-2] + num[n-1] < target) continue;
            
            for(int j = i + 1; j < n - 2; ++j){
                if(j > i + 1 && num[j] == num[j-1]) continue;
                if(num[i] + num[j] + num[j+1] + num[j+2] > target) break;
                if(num[i] + num[j] + num[n-2] + num[n-1] < target) continue;
                
                int third = j + 1, fourth = n - 1;
                while(third < fourth){
                    int sum = num[i] + num[j] + num[third] + num[fourth];
                    if(sum < target)
                        third++;
                    else if(sum > target)
                        fourth--;
                    else{
                        result.push_back(vector<int>{num[i], num[j], num[third], num[fourth]});
                        
                        do{third++;} while(third < fourth && num[third] == num[third-1]);
                        do{fourth--;}while(third < fourth && num[fourth] == num[fourth+1]);
                    }
                }
            }
        }
        return result;
    }
};