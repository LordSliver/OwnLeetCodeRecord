class Solution {
public:
    vector<int> searchRange(vector<int>& num, int target) {
        vector<int> result(2, -1);
        if(num.size() < 1)
            return result;
        
        int l = 0, r = num.size() - 1;
        while(l < r){
            int m = (l + r) / 2;
            if(num[m] < target) l = m + 1;
            else r = m;
        }
        
        if(num[l] != target) return result;
        else result[0] = l;
        
        r = num.size() - 1;
        while(l < r){
            int m = (l + r) / 2 + 1;
            if(num[m] > target) r = m - 1;
            else l = m;
        }
        
        result[1] = r;
        
        return result;
    }
};