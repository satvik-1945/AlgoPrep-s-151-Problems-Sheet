class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) 
    {
        int n = arr.size();
        vector<int> rmin(n+1);
        vector<int> lmax(n);
        int max_ = INT_MIN;
        int min_ = INT_MAX;

        for(int i = 0 ; i< n;i++)
        {
            max_ = max(max_,arr[i]);
            lmax[i] = max_;
        }
        rmin[n]= INT_MAX;
        for(int i = n-1 ;i>= 0; i--)
        {
            min_ = min(min_ , arr[i]);
            rmin[i] = min_;
        }
        int count = 0 ;
        for(int i = 0 ;i < n ; i++)
        {
            if(lmax[i] <= rmin[i+1])
            {
                count++;
            }
        }
        return count ;
    }
};