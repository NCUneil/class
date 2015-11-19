#include <stdio.h>


/*
int main()
{
	int a = 2;
	int b = 3;

	float x = 11.5f;
	float y = -5.5f;

	printf("%f\n", (float)(a+b)/1 + (int)x%(int)y); //6.0f
                     
	x *= -1;
	y *= -1;

	printf("%d\n", a+b/1 + (int)x%(int)y);      //4
                   5     +    (-1)
	return 0;
}
*/


/*
int main()
{
	unsigned char x = 254;
	unsigned char y = 0;
	unsigned int  a = 0;

	a = y = x+3;  
	return 0;
}


int main()
{
	int a = 10;
	int b = 20;

	//a *= b+2;  //202    or   220   

	a *= b += 2*3;//260 26

	//a = a*(b += 2*3);

	//a = a*26;


	printf("%d - %d\n",a,b);//    26
	return 0;
}


int f(int n)
{
	return 10;
}

int main()
{                 //   0  1   2  3  4 5  6  7  8  9  10  
	int arr[200] = {100,95,90,85,80,75,70,65,60,55,50,45,40};
	int x = 0;

//	arr[f(x)] = arr[f(x)] + 1000;//   f(x)   f(x)   

	arr[f(x)] += 1000;            //f(x)

	return 0;
}
*/

/*
int main()
{
	int a = 10;
	//a = a + 5;


	a += 5;
	return 0;
}

int main()
{
	int a = 10;
	int b = 20;

	printf("%d\n", a+++b);//      a + ++b
	                      //      a++ + b
	                      //      C缺陷和陷阱--1、2
	return 0;
}

左值：拥有内存空间，并且可读可写的变量可以作为左值



int main()
{
	int a = 10;
	int b = 200;
	int arr[10] = {0};
	const int c = 30;
	
	arr = a+b;

	return 0;
}


a++;     a=a+1;

++a;     a=a+1;



void func(int x,int y)
{
	printf("%d- %d\n",x,y);
}

int main()
{
	int a = 10;
	func(a++,++a);

	//int b = a++ + ++a + ++a + a++ + a++;
	//printf("%d\n",b);
	return 0;
}


int g_i = 100;

int g1()
{
	g_i = g_i+1;

	return 0;
}

int g2()
{
	g_i = g_i*2;

	return 0;
}

int g3()
{
	g_i = g_i+3;

	return 0;
}

int main()
{
	g1()+g2()+g3();

	printf("%d\n",g_i);
	return 0;
}



int main()
{
	int a = 10;
	
	printf("%d\n",sizeof a++);//编译时sizeof已经将大小算好
	                          //函数，运行时计算
	printf("%d\n",a);




	//getchar();
	return 0;
}


int main()
{
	
	int a = 10;
	//左操作数必须为左值
	//a++ = 100;
	//a = 100           ;    a=a+1;
	
	
	++a = 100;//         前置++ 的结果可以做左值
	          //         后置++ 的结果不能做左值
	

	printf("%d\n",a);

	return 0;
}
*/

/*
int main()
{
	int week = 7;
	
	if (week>=1 &&week<=5)
	{
		printf("周中\n")
	}
	else
	{
		if (week == 6)
		{
			printf("周六\n");
		}
		else
		{
			printf("周日\n");
		}
		
	}
	

	week>=1 && week<=5 ? printf("周中\n") : week==6?printf("周六\n"):printf("周日\n") ;
	return 0;
}



int main()
{
	//1+2+3++100;
	int i;
	int j;
	int sum = 0;
	for (i=1,j=100; i<j; i++,j--)
	{
		sum += (i+j);
	}
	printf("%d\n",sum);
	return 0;
}




int main()
{
	int x = 1;

	int sum = 0;

	while(x<=100)
	{
		sum+=x;
		x++;
	}

	printf("%d\n",sum);
	return 0;
}



int main()
{
	int a = 10;
	int b = 20;

	a = b;//   赋值，从右向左
	**s;


	sizeof(a)
	return 0;
}
*/


