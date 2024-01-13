class Solution {
    public int maxArea(int[] height) {
        int max = 0;
        int left = 0;
        int right = height.length-1;
        while(left<right){
            int curr = Math.min(height[left],height[right])*(right-left);
            max = Math.max(max,curr);
            if(height[left]<=height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return max;
        
    }
}