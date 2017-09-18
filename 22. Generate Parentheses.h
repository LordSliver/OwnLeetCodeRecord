class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        addingpar(result, "", n, n);
        return result;
    }
    
    void addingpar(vector<string> &res, string str, int l, int r){
        if(l==0 && r==0){
            res.push_back(str);
            return;
        }
        if(l > 0)
            addingpar(res, str + "(", l - 1, r);
        if(r > l) 
            addingpar(res, str + ")", l, r - 1);
    }
};