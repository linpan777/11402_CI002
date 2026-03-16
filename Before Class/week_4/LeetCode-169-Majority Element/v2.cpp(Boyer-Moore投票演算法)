class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = nums[0], count{1};
        for(int i{1}; i < nums.size(); i++)
        {
            count = (majority == nums[i])? count+=1: count-=1;
            if(count == 0)
            {
                majority = nums[i];
                count++;
            }
        }
        return majority;
    }    
};