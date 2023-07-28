class Solution {
public:
    vector<int> nearest_R(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;
        st.push(arr[n-1]);
        for (int i = n-2; i >= 0; i--) {
            while (!st.empty() && arr[i] > st.top()) {
                st.pop();
            }
            if (!st.empty()) {
                ans[i] = st.top();
                if (arr[i] > st.top()) {
                    st.push(arr[i]);
                }
            } else {
                st.push(arr[i]);
            }
        }
        return ans;
    }

    vector<int> nearest_L(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;
        st.push(arr[0]);
        for (int i = 1; i < n; i++) {
            while (!st.empty() && arr[i] >= st.top()) {
                st.pop();
            }
            if (!st.empty()) {
                ans[i] = st.top();
                if (arr[i] > st.top()) {
                    st.push(arr[i]);
                }
            } else {
                st.push(arr[i]);
            }
        }
        return ans;
    }

    int trap(vector<int>& arr) {
        int n = arr.size(); 
        vector<int> greatest_to_l = nearest_L(arr);
        vector<int> greatest_to_r = nearest_R(arr);
        int water = 0;
        for (int i = 0; i < n; i++) {
            if (greatest_to_l[i] != -1 && greatest_to_r[i] != -1) {
                water += min(greatest_to_l[i], greatest_to_r[i]) - arr[i];
            }
        }
        return water;
    }
};
