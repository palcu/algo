class Solution {
private:
    stack<char> parans;
    bool is_closing(char c) {
        return c == ')' || c == ']' || c == '}';
    }
    bool is_matching(char a, char b) {
        return (
            (a == '(' && b == ')') ||
            (a == '[' && b == ']') ||
            (a == '{' && b == '}')
        );
    }
public:
    bool isValid(string s) {
        for (auto c : s) {
            if (is_closing(c)) {
                if (!parans.empty() && is_matching(parans.top(), c)) {
                    parans.pop();
                }
                else {
                    return false;
                }
            } else {
                parans.push(c);
            }
        }
        return parans.empty();
    }
};
