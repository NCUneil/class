#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/*
#define PI 3.14


int main()
{
	int xy = 100;

	printf("%f\n", PI);
	printf("PI\n");//PI 3.14 中文
	return 0;
}


extern void func();

int main()
{
	//assert(0);
	printf("%s\n", __FILE__);
	printf("%d\n", __LINE__);
	printf("%s\n", __DATE__);//预处理完成日期
	printf("%s\n", __TIME__);//预处理完成时间
	

	K&R C    ANSI C     ISO C  C89   C99   C14
	//func();
	
	return 0;
}

int main()
{
int *p = (int*)malloc(100);
if (p == NULL)
printf("File %s line :%d\n",__FILE__,__LINE__);;

DEBUG_PRINT;


free(p);

p = (int*)malloc(1024*1024*1024*2);
if (p == NULL)
{
//printf("s - error\n");
DEBUG_PRINT;
exit(-1);
}

free(p);


return 0;
}



#define do_forever for(;;)
#define PI 3.14
*/

//1.不要通过宏，发明新语言
//2.宏替换C语言，宏不要加分号
//3.宏连接符 反斜杠  \    ，在宏的最后一行，不要加连接符

//4.尽可能用const  而不用#define，常变量更安全
//5.能用函数，不用宏函数，   C语言函数，参数类型检查，宏函数直接替换

//6.宏函数，给参数加上括号，防止优先级错乱，宏整体也建议加上括号

/*
STDARG.H

va_list
va_start

va_arg

va_end

#define va_end(ap)     ap = (char*)0

#define DEBUG_PRINT printf("File %s \
line :%d\n",\
__FILE__,__LINE__) 

int main()
{
	DEBUG_PRINT;
	return 0;
}


#define PI 3.14159


const float pi = 3.14159f;

void func(int f)
{
	printf("%d\n",f);
}

int main()
{
	func(pi);
	
	return 0;
}


int add(int x,int y)
{
	return x+y;
}

#define ADD(x,y)   ((x)+(y))

#define SQUAR(x)   ((x)*(x))

int squar(int x)
{
	return x*x;
}

int main()
{
	printf("%d\n",SQUAR(10+5)); //(10+5)*(10+5)  //10+5 * 10+5
	printf("%d\n",squar(10+5));



	printf("%d\n", add(10*2,20*2)*5);//300
	printf("%d\n", ADD(10*2,20*2)*5);//300

	//(x)+(y)     (10*2) + (20*2) *  5

	               
	return 0;
}


全大写 
#define  MAX()

getMax

GetMax

get_max


MAX(10,20)


#define offsetof(s,m) (size_t)&(((s *)0)->m)

struct STU
{
	int num;
	char name[12];
	float score;
};

int main()
{
	printf("%d\n",offsetof(struct STU,name));

	return 0;
}


int main()
{
	short i;
	scanf("%hd", &i);

	return 0;
}


#define MAX(a,b) ( (a)>(b)?(a):(b) )

#define MAX2(a,b)  ( (((a)-(b))>>31)  ? (b) :  (a))


int main()
{
	int max = MAX2(-100,-20);   
	printf("%d\n", max);
	return 0;
}


#define  ADD(a,b)   a+b


10+30
20+40
int add(int x, int y)
{
	return x+y;
}

add(10,20);
add(20,30);

#define PI 3


const int x = 4;

int main()
{
	const int pi = 3;

	

	printf("%d\n", x);
	printf("%d\n", pi);
	printf("%d\n", x);
	printf("%d\n", x);
	printf("%d\n", pi);//编译  时替换  

	
	return 0;
}


int add()
{
	const int pi = 3;//程序员自我修养     

	return pi;
}

int main()
{
	add();
	printf("helloxxxxxxxxxxxxxxxxxxxxxx\n");

	return 0;
}


#define 整型 int
#define 赋值 =
#define 输出整型(x) printf("%d",x)
#define 主函数 int main()
#define 开始 {
#define 结束 }


int main()
{
int i = 10;
printf("%d",i)
 }


#define int ____
#define char _
#define short __
#define float .____
#define double .________


int main()
{

}



#define  PI 3.14

#define AREA(R)  ( (PI)*(R)*(R) )

int main()
{
	printf("%f\n", AREA(10));
	//          (3.14)*(10)*(10)
	return 0;

}
 */
/*
#define PRINT(FORMAT, VALUE) \
	printf("The value is" FORMAT "hahah\n", VALUE)


int main()
{
	int x = 10;

	PRINT("%d", x+3);
	//PRINT(FORMAT, VALUE);

	//printf("The value is%dhahah\n", x+3);


	return 0;
}


int main()
{
	char *ch = ("world             \"   "     "hahaha");

	
	return 0;
}
*/
/*

#define PRINT(FORMAT, VALUE) \
	printf("The value of " #VALUE " is " FORMAT "hahah\n", VALUE)
                         

x+3
"The value of " #x+3 " is " "%d" "hahah\n", x+3)

  "The value of x+3 is 13hahah\n", x+3   
 



int main()
{
	int x = 10;

	PRINT("%d", x+3);

	return 0;
}





printf("p != NULL"  " File:%s Line:%d\n",__FILE__,__LINE__);
 

#include <Windows.h>

#define  MY_ASSERT(EXPRESS) \
if (!EXPRESS)\
{\
	printf("Assertion failed: "#EXPRESS", file:%s,line:%d\n",__FILE__,__LINE__);\
	MessageBoxW(NULL, L"xxxxxxxxx",L"ASSERT ERROR", MB_ABORTRETRYIGNORE);\
	exit(-1);\
}


int main()
{
	int *p = NULL;
	//assert(p != NULL);
	MY_ASSERT(p != NULL);
	return 0;
}


#define MY_STRCAT(S1,S2)    S1##S2

int main()
{
	printf("%s\n", MY_STRCAT("hello","world"));
	               MY_STRCAT("hello","world")
					   "helloworld"
	return 0;
}
*/

#define MY_STRCAT(S1,S2)    S1##S2

int main()
{
	int x = MY_STRCAT(0x,20);

#undef MY_STRCAT
	//int x = 1020;

	printf("%d\n",x);//   0A20

	return 0;
}