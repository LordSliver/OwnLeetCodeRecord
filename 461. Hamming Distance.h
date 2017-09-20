class Solution {
public:
    int hammingDistance(int x, int y) {
        int tmp = x ^ y;
        int n = 0;
        while(tmp){
            tmp &= (tmp - 1);
            ++n;
        }
        return n;
    }
};