class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        vector<int> output(arr.size());
        int n=arr.size();
       int prefix = 1;
    for (int i = 0; i < n; i++) {
        output[i] = prefix; 
        prefix *= arr[i];  
    }

    
    int suffix = 1;
    for (int i = n - 1; i >= 0; i--) {
        output[i] *= suffix; 
        suffix *= arr[i];   
    }
    return output;
    }
};
