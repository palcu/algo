#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <string>
#include <list>
#include <cstring>

using namespace std;


class MinStack {
    list<int> data, dataMin;

public:
    void push(int x) {
        data.push_back(x);
        if (dataMin.empty() || dataMin.back() >= x) {
            dataMin.push_back(x);
        }
    }

    void pop() {
        if (data.back() == dataMin.back())
            dataMin.pop_back();
        data.pop_back();
    }

    int top() {
        if (data.empty())
            return -1;
        return data.back();
    }

    int getMin() {
        return dataMin.back();
    }
};

int main(){
    MinStack stack;
    stack.push(-2);
    stack.push(0);
    stack.push(-1);
    std::cout << stack.getMin() << std::endl;
    std::cout << stack.top() << std::endl;
    stack.pop();
    std::cout << stack.getMin() << std::endl;
    return 0;
}
