#include <iostream>
#include <stack>

int main () {
    std::stack<int> st;
    for (int num = -1; num != 0; std::cin >> num) {
        if (num > 0) {
            st.push(num);
        }
        else if (st.size() > 0) {
            st.top() += num;
            if (st.top() <= 0) {
                st.pop();
            }
        }
    }
    std::cout << st.size() << ' ' << (st.size() == 0 ? -1 : st.top()) << std::endl;
    return 0;
}