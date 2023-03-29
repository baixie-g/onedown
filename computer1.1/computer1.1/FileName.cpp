#include<iostream>
#include<stack>
#include<string>

using namespace std;

//������������ȼ�
int priority(char op)
{
    if (op == '*' || op == '/') return 2;
    else if (op == '+' || op == '-') return 1;
    else return 0;
}

//ʵ�ֶԱ��ʽ�ַ����ķ�������
double calculate(string str)
{
    stack<double> num_stack; //�洢��������ջ
    stack<char> op_stack; //�洢��������ջ

    //���ַ���ĩβ���һ��'#'���ţ���Ϊ������־
    str += '#';

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9') //���������
        {
            double num = 0; //�洢������
            while (str[i] >= '0' && str[i] <= '9') //��ȡ�����ֵ�����λ
            {
                num = num * 10 + (str[i] - '0');
                i++;
            }
            num_stack.push(num); //��������ѹ�������ջ
            i--; //����һ���ַ�
        }
        else //����ǲ�����
        {
            char op = str[i];
            while (!op_stack.empty() && priority(op_stack.top()) >= priority(op)) //���ջ�����������ȼ����ڵ��ڵ�ǰ������
            {
                double num2 = num_stack.top(); //����ջ��������������
                num_stack.pop();
                double num1 = num_stack.top();
                num_stack.pop();
                char op_top = op_stack.top(); //����ջ��������
                op_stack.pop();
                double res; //������
                if (op_top == '+') res = num1 + num2;
                else if (op_top == '-') res = num1 - num2;
                else if (op_top == '*') res = num1 * num2;
                else if (op_top == '/') res = num1 / num2;
                num_stack.push(res); //��������ѹ�������ջ
            }
            if (op != '#') op_stack.push(op); //����ǰ������ѹ�������ջ��'#'����ѹ��
            else break; //�����������ţ��˳�ѭ��
        }
    }
    return num_stack.top(); //�������ռ�����
}

int main()
{
    string expr;
    cout << "������һ����׺���ʽ�������ո񣩣�" << endl;
    cin >> expr;
    double res = calculate(expr); //������ʽ
    cout << "������Ϊ��" << res << endl;
    return 0;
}
