#include<iostream>
#include<stack>
#include<string>

using namespace std;

//定义操作符优先级
int priority(char op)
{
    if (op == '*' || op == '/') return 2;
    else if (op == '+' || op == '-') return 1;
    else return 0;
}

//实现对表达式字符串的分析计算
double calculate(string str)
{
    stack<double> num_stack; //存储操作数的栈
    stack<char> op_stack; //存储操作符的栈

    //在字符串末尾添加一个'#'符号，作为结束标志
    str += '#';

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9') //如果是数字
        {
            double num = 0; //存储操作数
            while (str[i] >= '0' && str[i] <= '9') //读取该数字的所有位
            {
                num = num * 10 + (str[i] - '0');
                i++;
            }
            num_stack.push(num); //将该数字压入操作数栈
            i--; //回退一个字符
        }
        else //如果是操作符
        {
            char op = str[i];
            while (!op_stack.empty() && priority(op_stack.top()) >= priority(op)) //如果栈顶操作符优先级高于等于当前操作符
            {
                double num2 = num_stack.top(); //弹出栈顶的两个操作数
                num_stack.pop();
                double num1 = num_stack.top();
                num_stack.pop();
                char op_top = op_stack.top(); //弹出栈顶操作符
                op_stack.pop();
                double res; //计算结果
                if (op_top == '+') res = num1 + num2;
                else if (op_top == '-') res = num1 - num2;
                else if (op_top == '*') res = num1 * num2;
                else if (op_top == '/') res = num1 / num2;
                num_stack.push(res); //将计算结果压入操作数栈
            }
            if (op != '#') op_stack.push(op); //将当前操作符压入操作符栈，'#'不用压入
            else break; //遇到结束符号，退出循环
        }
    }
    return num_stack.top(); //返回最终计算结果
}

int main()
{
    string expr;
    cout << "请输入一个中缀表达式（不含空格）：" << endl;
    cin >> expr;
    double res = calculate(expr); //计算表达式
    cout << "计算结果为：" << res << endl;
    return 0;
}
