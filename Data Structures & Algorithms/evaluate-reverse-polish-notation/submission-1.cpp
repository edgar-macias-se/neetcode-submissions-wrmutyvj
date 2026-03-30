class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numStack;
        
        // Map de operadores a funciones lambda
        unordered_map<string, function<int(int, int)>> opMap = {
            {"+", [](int a, int b) { return a + b; }},
            {"-", [](int a, int b) { return a - b; }},
            {"*", [](int a, int b) { return a * b; }},
            {"/", [](int a, int b) { return a / b; }}
        };
        
        for (const string& token : tokens) {
            // Verificar si es operador
            if (opMap.count(token)) {
                // Pop dos operandos (ORDEN IMPORTANTE)
                int b = numStack.top(); numStack.pop();
                int a = numStack.top(); numStack.pop();
                
                // Aplicar operación
                int result = opMap[token](a, b);
                numStack.push(result);
            } else {
                // Es un número (puede ser negativo o multi-dígito)
                numStack.push(stoi(token));
            }
        }
        
        return numStack.top();
    }
};