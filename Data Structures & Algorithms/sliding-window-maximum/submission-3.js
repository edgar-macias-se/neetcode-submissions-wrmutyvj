class Solution{

maxSlidingWindow(nums, k) {
    const result = [];
    const deque = []; // Índices en orden decreciente de valores
    
    for (let i = 0; i < nums.length; i++) {
        // Remover índices fuera de la ventana
        while (deque.length && deque[0] <= i - k) {
            deque.shift();
        }
        
        // Mantener deque en orden decreciente
        while (deque.length && nums[deque[deque.length - 1]] < nums[i]) {
            deque.pop();
        }
        
        deque.push(i);
        
        // Agregar resultado si la ventana está completa
        if (i >= k - 1) {
            result.push(nums[deque[0]]);
        }
    }
    
    return result;
}
}