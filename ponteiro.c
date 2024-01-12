void operacao_int(int a, int b, char op, int* res) {

    if (op == '+') {
        *res = a + b;
        
    } else if (op == '-') {
        *res = a - b;
    } else if (op == '*') {
        *res = a * b;
    } else if (op == '/') {
        if (b != 0) {
            *res = a / b;
        } else {
            *res = 0; 
        }
        
    } else if (op == '%') {
        if (b != 0) {
            *res = a % b;
        } else {
            *res = 0;
        }
        
    } else if (op == '^') {
        *res = a ^ b;
    } else if (op == '|') {
        *res = a | b;
    } else if (op == '&') {
        *res = a & b;
        
    } else {
        *res = 0;
    }
}
