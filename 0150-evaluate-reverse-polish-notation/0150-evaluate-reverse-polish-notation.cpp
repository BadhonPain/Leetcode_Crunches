class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (int i = 0; i < tokens.size(); i++) {
            string ch = tokens[i];

            if (ch == "+" || ch == "-" || ch == "*" || ch == "/") {
                int operand2 = st.top();
                st.pop();
                int operand1 = st.top();
                st.pop();
                int result;

                if (ch == "+")
                    result = operand1 + operand2;
                else if (ch == "-")
                    result = operand1 - operand2;
                else if (ch == "*")
                    result = operand1 * operand2;
                else if (ch == "/")
                    result = operand1 / operand2;

                st.push(result);
            } else
                st.push(stoi(ch));
        }
        int final_result = st.top();
        st.pop();
        return final_result;
    }
};