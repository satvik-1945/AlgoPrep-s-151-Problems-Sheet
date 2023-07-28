class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& arr, int left, int right) {
        int i = 0;
        int j = 0;
        int n = arr.size();
        int count = 0;
        int m = 0;
        while (j <n) {
            if (arr[j] >= left && arr[j] <= right) {
                m = j-i+1;
                count +=m ;
                j++;
            } else if (arr[j] < left) {
                
                count += m;
                j++;
            } else if (arr[j] > right) {
                m = 0;
                i = j + 1;
                j = i;
            }
        }
        return count;
    }
};
