#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include<iostream>
using namespace std;
//
//void func(char** str);
//
//int main(void)
//{
//    int i;
//    char s[6][1024], * pStr[6];
//
//    for (i = 0; i < 6; i++)
//    {
//        scanf("%s", s[i]);
//        pStr[i] = s[i];
//    }
//    func(pStr);
//    //输出排序后的结果
//    for (i = 0; i < 6; i++)
//    {
//        puts(pStr[i]);
//        printf("%s", pStr[i]);
//        printf("%s", s[i]);
//    }
//
//    return 0;
//}
//
//void func(char** str)
//{
//    int i, j;
//    char* temp;
//
//    for (i = 0; i < 5; i++)
//    {
//        for (j = i+1; j < 6; j++)
//        {
//            if (
//                strcmp(str[i], str[j]) > 0
//
//                )
//            {
//                temp = *(str + j);
//                *(str + j) = *(str + i);
//                *(str +i) = temp;
//            }
//        }
//    }
//    for (i = 0; i < 6; i++)
//    {
//        printf("%s", str[i]);
//
//    }
//}

//
//#include <stdio.h>
//int counter( ){
//static int c = 0;//局部c=0，且使用一次，
//return  ++c;//第一次返回1
//}
//int main() {
//	for (int i = 0; i < 2; i++)
//	{
//		int c;//第一次默认c=0
//		c = counter();//第一次使用后主函数的c是1。//第二次到这c承接函数内的++c就是++2，主函数的c就成了3，函数里的也是3
//		for (int j = 0; j < c; j++)printf("%d\n", counter());//第一次时counter已经使用2次，输出函数返回函数内的c=2；
//		//第二次调用再次将局部的c（3）加上1 变成4输出...而且此时主函数c=3循环3次，还剩两次每次+1，输出5和6结束循环
//	}
//	return 0;
//}
//
//
//#include <stdio.h>
//
//int  word_divide(char str[])
//{
//    int count = 0;
//    int i = 0;
//
//    while (str[i] != '\0')
//    {
//        if (str[i] == ' ')
//        {
//            count++;
//            while (str[i] == ' ')
//                i++;
//        }
//        else
//        {
//            i++;
//        }
//    }
//    if (str[i - 1] != ' ')
//        count++;
//
//    return count;
//}
//int main()
//{
//    char str[] = "This is a Longer Road!";
//    int l = word_divide(str);
//
//    printf("%d\n", l);
//    return 0;
//}

//
//int main() {
//	char str[10], c;
//	scanf("%s", str);
//	//getchar();
//	scanf("%c", &c);
//	cout << str << endl;
//	cout << c << endl;
//
//}


//
//int main() {
//	int a = 1; int b = 2; int c = 3; int d = a != c == a < b < c; cout << d << endl;
//}