// Check if character is an operator
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || 
    ch == '*' || ch == '/' || ch == '^');
}

// Get precedence of operators
int operatorPrecedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
}

// Convert infix to postfix
string convertInfixToPostfix(string s) {
    stack<char> st;
    string res;
    int sz = s.size();

    for (int i = 0; i < sz; i++) {
        if (isalnum(s[i])) {
            res += s[i];
        } else if (s[i] == '(') {
            st.push(s[i]);
        } else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                res += st.top();
                st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() && operatorPrecedence(s[i]) <= 
            operatorPrecedence(st.top())) {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while (!st.empty()) {
        res += st.top();
        st.pop();
    }

    return res;
}


// Convert infix  to prefix 
string convertToPrefix(string infix) {
    reverse(infix.begin(), infix.end());

    for (int i = 0; i < infix.size(); i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }

    string postfix = convertInfixToPostfix(infix);
    reverse(postfix.begin(), postfix.end());

    return postfix;
}
