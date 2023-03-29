#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<double> num;
stack<char> ope;

// 定义运算符优先级
int priority(char op) {
    if (op == '(') return 0;
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return -1;
}

// 处理运算符
void process_op() {
    char op = ope.top();
    ope.pop();
    double n2 = num.top();
    num.pop();
    double n1 = num.top();
    num.pop();
    double res;
    switch (op) {
    case '+':
        res = n1 + n2;
        break;
    case '-':
        res = n1 - n2;
        break;
    case '*':
        res = n1 * n2;
        break;
    case '/':
        res = n1 / n2;
        break;
    default:
        break;
    }
    num.push(res);
}

int main() {
    string input;
    cout << "请输入一个表达式：";
    getline(cin, input);

    for (int i = 0; i < input.length(); i++) {
        char ch = input[i];
        if (ch == ' ') {
            continue;
        }
        else if (ch >= '0' && ch <= '9') {
            double num_val = ch - '0';
            while (i + 1 < input.length() && input[i + 1] >= '0' && input[i + 1] <= '9') {
                i++;
                num_val = num_val * 10 + (input[i] - '0');
            }
            num.push(num_val);
        }
        else if (ch == '(') {
            ope.push(ch);
        }
        else if (ch == ')') {
            while (!ope.empty() && ope.top() != '(') {
                process_op();
            }
            ope.pop(); // 弹出左括号
        }
        else {
            while (!ope.empty() && priority(ch) <= priority(ope.top())) {
                process_op();
            }
            ope.push(ch);
        }
    }

    // 处理剩余的运算符
    while (!ope.empty()) {
        process_op();
    }

    cout << "表达式的计算结果为：" << num.top() << endl;

    return 0;
}