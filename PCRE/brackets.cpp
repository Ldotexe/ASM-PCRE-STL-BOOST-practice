#include <iostream>
#include <string>
#include <stack>

int main () {
    std::string str;
    std::stack<char> st;
    std::cin >> str;
    for (size_t i = 0; i < str.size(); ++i) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{' || str[i] == '<') {
            st.push(str[i]);
        }
        if (str[i] == ')') {
            if (!st.empty()) {
                if (st.top() == '(') {
                    st.pop();
                }
            }
            else {
                std::cout << "NO" << std::endl;
                return 0;
            }
        }
        if (str[i] == ']') {
            if (!st.empty()) {
                if (st.top() == '[') {
                    st.pop();
                }
            }
            else {
                std::cout << "NO" << std::endl;
                return 0;
            }
        }
        if (str[i] == '}') {
            if (!st.empty()) {
                if (st.top() == '{') {
                    st.pop();
                }
            }
            else {
                std::cout << "NO" << std::endl;
                return 0;
            }
        }
        if (str[i] == '>') {
            if (!st.empty()) {
                if (st.top() == '<') {
                    st.pop();
                }
            }
            else {
                std::cout << "NO" << std::endl;
                return 0;
            }
        }
    }
    if (!st.empty()) {
        std::cout << "NO" << std::endl;
        return 0;
    }
    std::cout << "YES" << std::endl;
    return 0;
}