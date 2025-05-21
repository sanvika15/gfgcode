class Solution {
  public:
    int findUnique(vector<int> &arr) {
        // Initialize result variable to 0
        int num = 0;

        // Iterate through all elements in the array
        for(int ele : arr) {
            // XOR each element with the result
            // The property of XOR:
            // a ^ a = 0 and a ^ 0 = a
            // So all duplicate elements cancel each other out
            // Only the unique element remains
            num = num ^ ele;
        }

        // Return the element which is not cancelled (i.e., unique one)
        return num;        
    }
};