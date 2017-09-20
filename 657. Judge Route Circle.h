class Solution {
public:
    bool judgeCircle(string moves) {
        int cnt[128];
        cnt['L'] = cnt['R'] = cnt['U'] = cnt['D'] = 0;
        for(auto c : moves){
            cnt[c]++;
        }
        return (cnt['L'] == cnt['R']) && (cnt['U'] == cnt['D']);
    }
};