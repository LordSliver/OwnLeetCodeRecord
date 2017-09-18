class Solution {
public:
    int search(vector<int>& num, int target) {
        /*
        int i;
        for(i = 0; i < num.size(); ++i){
            if(num[i] == target)
                return i;
            else if(num[i] > target)
                break;
        }
        for(int j = num.size() - 1; j > i; --j){
            if(num[j] == target)
                return j;
            else if(num[j] < target)
                return -1;
        }
        return -1;*/
        
        int l =0 , r = num.size() - 1;
        while(l < r){
            int m = (l + r) / 2;
            if(num[m] == target)
                return m;
            if((target < num[0]) ^ (num[m] < num[0]) ^ (num[m] < target))
                l = m + 1;
            else
                r = m; 
        }
        return l == r && num[l] == target ? l : -1;
    }
};