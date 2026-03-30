class Solution {
private:
    long long hoursNeeded(vector<int>& piles, int k){
        long long hours = 0;
        for(int pile: piles){
            hours += (pile + k - 1) / k;
        }

        return hours;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // Binary search en el espacio de velocidades
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // ¿Podemos terminar con velocidad mid?
            if (hoursNeeded(piles, mid) <= h) {
                // Sí funciona, buscar velocidad menor
                right = mid;
            } else {
                // No funciona, necesitamos velocidad mayor
                left = mid + 1;
            }
        }
        
        return left;
    }
};
