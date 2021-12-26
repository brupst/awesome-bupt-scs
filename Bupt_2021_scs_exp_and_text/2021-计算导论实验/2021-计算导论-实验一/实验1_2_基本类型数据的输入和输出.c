/*编写一程序，按照顺序分别输入某学生的性别、年龄和身高(以米为单位)，你的任务是将三者按照规定的格式输出。性别要用一个字符型(char型)变量存储，
年龄要用一个整型(int 型)变量存储，身高要用一个单精度浮点型(float 型)变量存储。
输入格式:
为三行，第一行为一个字符‘M’或‘F’代表性别；第二行为一个整数，代表年龄；最后一行为一个浮点数，代表身高。测试用例保证输入合法。
输出格式:
只有一行，形如：“The sex is M, the age is 18, and the height is 1.660000.”。*/

#include<stdio.h>
int main()
{
   int age;
   float height;
   char sex;
   scanf("%c",&sex);
   scanf("%d",&age);
   scanf("%f",&height);
   printf("The sex is %c, the age is %d, and the height is %f.",sex,age,height);
   return 0;
}