#include <stdio.h>

/*
//197x   K&R C

int add(int x, int y);

int main()
{
	printf("%f\n",add(10.5f,20.2f));
	return 0;
}


//C  C++   php  python  美国  大陆
int func(int x)
{
	if ()
	{
	}
}


//java     oc  swift   日本
int 
add(int x,int y)
{
	if (x == 0){
		printf("zero\n");
	}
	return x+y;
}




bool print_start(int n)
{
	if (n <= 0)
	{
		return false;
	}

	for (int i=0;i<n;i++)
	{
		printf("*");
	}
	printf("\n");

	return true;
}

int main()
{
	printf("%d\n", print_start(100));
	return 0;
}


warning C4244: 
“return”: 从“float”转换到“int”，可能丢失数据

int add(float x, float y)   
{
	return x+y;   10.0f + 20.5f   (int)30
}

int main()
{
	printf("%d\n", add(10,  20.5f));
	return 0;
}


bool IsEmpty(SEQ_LIST *p)
{
	//if (p->length == 0)
	//{
	//	return true;
	//}
	//else
	//{
	//	return false;
	//}



	return p->length == 0;
}

调用方式   调用约定




int i;

void funcC(int n);
void funcA();
void funcB();

int __cdecl printf(void);



int main()
{
	funcA();
	funcB();
	funcC();
	return 0;
}





void funcA()
{
	funcB();
	printf("A\n");
}

void funcB()
{
	funcA();
	funcC();
	printf("B\n");
}

void funcC(int c)
{
	funcB();
	printf("C\n");
}




__cdecl       C语言调用约定
__stdcall     STD调用约定
__fastcall    快速调用约定



int __fastcall add(int x,int y)
{
	return x+y;
}

int main()
{
	printf("%d\n",add(10,20));
	return 0;
}


//

void func(int num)
{
	if(num ==0)
	{
		return ;
	}

	int i = 10;
	printf("0x%p\n",&i);
	printf("%d\n",num);
	func(--num);	
}

int main()
{
	func(100);
	return 0;
}




void func(int num)
{
	if (num == 0)
	{
		return ;
	}

	printf("%d ",num%10);
	func(num/10);
}
int main()
{
	int i = 123456;
	func(i);
	return 0;
}

float aver()


int printf(char *str, ...);
*/


#include <stdarg.h>


/*
float aver(int n, ...)
{
	char *s;
	float sum = 0.0f;

	//   绕开n，指向n身后， 让s指向   可变参的地址
	va_start(s, n);   //准备访问可变参
	for (int count=0; count<n; count++)
	{
		//               指明可变参的类型
		sum += va_arg(s, int);
	}

	va_end(s);
	return sum/n;
}


int main()
{
	float f = aver(3,   10,30,20);
	printf("%f\n",f);
	return 0;
}

*/

//第一个参数，是有多少个值
int max_list(int n,...);


int max_list(int val, ...)
{
	va_list s;
	va_start(s,val);

	int max = val;
	int num;

	do 
	{
		num = va_arg(s, int);
		if (max < num)
		{
			max = num;
		}
	} while (num > 0);

	va_end(s);

	return max;
}

int main()
{
	printf("%d\n",max_list(1000,2,3,4600,7,8,9,-1));
	return 0;
}

#define _crt_va_start(ap,v)  ( ap = (va_list)_ADDRESSOF(v) + sizeof(v) )
#define _crt_va_arg(ap,t)    ( *(t *)((ap += sizeof(t)) - sizeof(t)) )
#define _crt_va_end(ap)      ( ap = (va_list)0 )