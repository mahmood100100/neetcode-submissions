class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0 , left = 0 , right = height.size()-1 , leftBorder , rightBorder;
        while(height[left+1] > height[left] && left+1 < right) left++;
        while(height[right-1] > height[right] && right-1 > left) right--;
        leftBorder = height[left];
        rightBorder = height[right];
        while (left < right) {
            int minHeight = min(leftBorder , rightBorder);
            int h =0;
            if(leftBorder == minHeight) {
                left++;
                while(left < right && height[left] < leftBorder) {
                    h = leftBorder - height[left];
                    water+= h;
                    left++;
                }
                leftBorder = height[left];

            } else {
                  right--;
                  while(left < right && height[right] < rightBorder) {
                    h = rightBorder - height[right];
                    water+= h;
                    right--;
                }
                rightBorder = height[right];
            }
        }

        return water;

    }
};
