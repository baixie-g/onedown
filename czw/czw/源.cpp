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
//    //��������Ľ��
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
//static int c = 0;//�ֲ�c=0����ʹ��һ�Σ�
//return  ++c;//��һ�η���1
//}
//int main() {
//	for (int i = 0; i < 2; i++)
//	{
//		int c;//��һ��Ĭ��c=0
//		c = counter();//��һ��ʹ�ú���������c��1��//�ڶ��ε���c�нӺ����ڵ�++c����++2����������c�ͳ���3���������Ҳ��3
//		for (int j = 0; j < c; j++)printf("%d\n", counter());//��һ��ʱcounter�Ѿ�ʹ��2�Σ�����������غ����ڵ�c=2��
//		//�ڶ��ε����ٴν��ֲ���c��3������1 ���4���...���Ҵ�ʱ������c=3ѭ��3�Σ���ʣ����ÿ��+1�����5��6����ѭ��
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