class Solution {
public:
    int threeSumClosest(vector<int>& num, int target) {
        
        int closest = num[0] + num[1] + num[2];
        std::sort(num.begin(), num.end());
        for(int i = 0; i < num.size() - 2; ++i){
            int front = i + 1;
            int back = num.size() - 1;
            
            while(front < back){
                int temp = num[i] + num[front] + num[back];
                if(temp == target)
                    return temp;
                if(abs(temp - target) < abs(closest - target))
                    closest = temp;
                temp > target? back-- : front++;
            }
        }
        return closest;
    }
};