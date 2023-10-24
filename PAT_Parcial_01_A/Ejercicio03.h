#pragma once
#include <vector>

class MinStack {
private:
    std::vector<int> mainStack; 
    std::vector<int> minStack;  

public:
    MinStack();
    void push(int value);
    void pop();
    int top();
    int getMin();
};

