class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            if (ch == '(' || ch == '{' || ch == '[')
                st.push(ch);

            else if (ch == ')' || ch == '}' || ch == ']') {
                if (st.empty())
                    return false;

                char peek = st.top();
                st.pop();

                if ((ch == ')' && peek != '(') || (ch == '}' && peek != '{') ||
                    (ch == ']' && peek != '['))
                    return false;
            }
        }
        return st.empty();
    }
};