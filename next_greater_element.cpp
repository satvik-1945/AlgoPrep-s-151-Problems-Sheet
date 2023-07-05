class Solution {
public:
    bool next_perm(string & nums)
    {
        int i= nums.size() -1 ;
        while(i > 0  and nums[i-1] >= nums[i])i--;
        if(i == 0 ) return false;

        int j = nums.size() -1 ;
        while(j > i-1 and nums[i-1] >= nums[j]) j--;
        swap(nums[j],nums[i-1]);
        reverse(nums.begin()+i,nums.end());
        return true;
    }
    int nextGreaterElement(int n) 
    {
        /*
        so we have a number
        1483629
        1223469*/
        string num = to_string(n);
        bool res = next_perm(num);
        auto ans = stoll(num);
        return( ! res || ans > INT_MAX)?-1 : ans;

    }
};