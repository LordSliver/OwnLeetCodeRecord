class Solution {
public:
    vector<string> n2c = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.size() <= 0)
            return result;
        process(digits, result, "", 0, digits.size());
        return result;
    }
    
    void process(string digits, vector<string> &result,string answer,int index,int end){
        if (index == end) {
            if (answer.size() > 0) {
                result.push_back(answer);
            }
        }
        else {
            int n = (int)(digits[index] - 48);
            if (n == 0 || n == 1)
                process(digits, result, answer + "", index + 1, end);
            else {
                for (auto c : n2c[n - 2]) {
                    process(digits, result, answer + c, index + 1, end);
                }
            }
        }
    }
};