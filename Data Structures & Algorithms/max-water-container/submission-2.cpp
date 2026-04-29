class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxArea = 0;
        int left = 0 , right = heights.size()-1;
        while (left < right) {
            int area = heights[left] < heights[right] ?  heights[left] * (right -left) : heights[right] * (right -left);
            if(area > maxArea) maxArea = area;
            if(heights[left] < heights[right]) left++;
            else if(heights[right] < heights[left]) right--;
            else if(heights[right] == heights[left]) {
                left++;
            }
        }
        return maxArea;
    }
};
