#include <cstdlib>
#include <iostream>
#include <stack>
using namespace std;

stack<float> result;

float calculator(float previousResult) {
    char op;
    float operand;

    cout << "Enter an operation (+, -, *, /, q, c, u): ";
    cin >> op;

    if (op == 'q') {
        return previousResult;
    }

    switch (op) {
    case '+':
        cout << "Enter a number: ";
        cin >> operand;
        cout << "Current result: " << previousResult << " + " << operand << " = "
            << previousResult + operand << endl;
        result.push(previousResult);
        return calculator(previousResult + operand);
    case '-':
        cout << "Enter a number: ";
        cin >> operand;
        cout << "Current result: " << previousResult << " - " << operand << " = "
            << previousResult - operand << endl;
        result.push(previousResult);
        return calculator(previousResult - operand);
    case '*':
        cout << "Enter a number: ";
        cin >> operand;
        cout << "Current result: " << previousResult << " * " << operand << " = "
            << previousResult * operand << endl;
        result.push(previousResult);
        return calculator(previousResult * operand);
    case 'c':
        cout << "Enter the new starting number: ";
        cin >> previousResult;
        cout << "New number: " << previousResult << endl;
        result.push(previousResult);
        return calculator(previousResult);
    case 'u':
        if (!result.empty()) {
            previousResult = result.top();
            result.pop();
            cout << "Undoing the last operation..... Current result: "
                << previousResult << endl;
        }
        else {
            cout << "No previous result to undo. Sorry!" << endl;
        }
        return calculator(previousResult);

    case '/':
        cout << "Enter a number: ";
        cin >> operand;
        cout << "Current result: " << previousResult << " / " << operand << " = "
            << previousResult / operand << endl;
        if (operand == 0) {
            cerr << "Error: Division by zero is not allowed." << endl;
            return calculator(previousResult);
        }
        return calculator(previousResult / operand);
    }
}

int main() {
    float init_value;
    float final_result;

    cout << "enter a number: " << endl;
    cin >> init_value;
    final_result = calculator(init_value);
    cout << "Final result: " << final_result << endl;
}
