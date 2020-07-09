#include <stdio.h>           /*预处理指令（），包含一个头文件，拷贝-粘贴操作*/

void myPrint(void);          /*函数申明/原型，告知编译器存在改函数，C标准建议，要为程序中用到的所有函数提供函数原型*/

int main(void)               /*一个函数定义，main函数*/
{                            /*函数体开始*/
    int x, y;                /*变量申明*/
    x = 5;                   /*赋值表达式*/
    y = 6;                   /*赋值表达式*/
    printf("Hello World! - %d - %d \n", x, y);  /*函数调用*/
    myPrint();               /*自定义函数调用*/
    getchar();               /*函数调用*/
    return 0;                /*return语句*/
}                            /*函数体结束*/

void myPrint(void)           /*函数定义*/
{
    printf("My Hello World!");
}
