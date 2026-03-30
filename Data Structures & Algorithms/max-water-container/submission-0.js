class Solution {
    /**
     * @param {[]} heights
     * @return {}
     */
    maxArea(height) {
    
    let init = 0; let last = height.length - 1;
    let mostWater  = 0;

    while(init < last){
        const currWater = Math.min(height[init], height[last]) *  (last - init);
        mostWater = currWater > mostWater ? currWater  : mostWater;
        if(height[init] < height[last]){
            init++;
        }else{
            last--;
        }
    }

    return mostWater;


};
}
