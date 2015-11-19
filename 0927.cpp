#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

/* 
#define my_va_start(p,v)          p = (char*)(&v) + sizeof(v)  
#define my_va_arg(p,type)         *(type *)p
#define my_va_forword(p,type)     p = p + sizeof(type)
#define my_va_end(p)              p = NULL

//             n代表有几个可变参，参与求解最大值
int max_list(int n, ...)//3,  10,20,30
{
	va_list ptr;
	va_start(ptr,n);//迎来,让ptr指向 第一个可变参地址
	
	int tmp = va_arg(ptr,int);//根据类型，使用ptr间接访问  可变参
	int max = tmp;



	for (int i=0;i<n-1;i++)
	{
		tmp = va_arg(ptr,int);
		if (max < tmp)
		{
			max = tmp;
		}
	}
	va_end(ptr);  //送往，让ptr指向NULL（因为ptr已经越界）

	return max;
}


                      
double max_list(double val,...)
{
	char *ptr;
	double tmp = val;
	double max = tmp;
	my_va_start(ptr,val);

	while(tmp >= 0)
	{
		if (max < tmp)
		{
			max = tmp;
		}
		tmp = my_va_arg(ptr,double);
		my_va_forword(ptr,double);
	}
	my_va_end(ptr);

	return max;
}


double max_list(double val, ...)
{
	//printf("%d\n",val);

	double tmp = val;
	double *ptr = &val;

	while(tmp >= 0)
	{
		printf("%lf\n",tmp);
		ptr++;//   int   +4  double   +8     char +1
		tmp = *ptr;
	}

	return -1.0;
}



int main()
{
	
	printf("%d\n",max_list(4, -10,20,30,4000));

	return 0;
}




int my_atoi(char *str)
{

	int sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	//'1'-'0' = 1*10000 = 10000
	//'2'-'0' = 2*1000 = 2000
	char *buff = (char*)malloc(strlen(str)+1);
	if (buff == NULL)
	{
		return -1;
	}
	char *tmp = buff;
	strcpy(buff,str);
	_strrev(buff);
	//buff  --"54321"

	int sum = 0;
	int i = 0;
	while(*buff != 0)
	{
		sum += (*buff-'0') * (int)pow(10.0f,i);
		i++;
		buff++;
	}
	free(tmp);

	return sum*sign;
}

int  atoi(char *str);
void itoa(char *str,int n,int radix);
int  hextoi(char *str);//"0xFFF11";

int my_atoi(char *str)//   "12345"
{
	int sum = 0;
	int sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	int tmp;

	while(*str)
	{
		tmp = (*str - '0');
		if (tmp <0 || tmp >9)
		{
			return -1;
		}
		sum = sum*10 + tmp;
		str++;
	}
	return sum*sign;

}

int main()
{
	printf("%d\n", my_atoi("12345.02"));
	printf("%d\n", my_atoi("-123456789"));
	printf("%d\n", my_atoi("-12x345"));
	return 0;
}



int x()
{
	printf("x\n");
	return 0;
}


int main()
{
	printf("wolrd\n");
	return 0;
}
#include <ctype.h>
int main()
{
	char ch;
	while((ch = getchar()) != '@')
	{
		if (isupper(ch))
		{
			ch = tolower(ch);
		}
		putchar(ch);
	}
	return 0;
}


int main()
{
	int a = 10;
	int b = -25;
	int c = 0;
	int d = 3;
	int e = 20;

	printf("%d\n",a <<= d > 20 ? b && c++ : d--);

	a <<= d > 20 ? b && c++ : d--

	//a = a << ( 3 );
	//       1010 << 3   0101 0000
	return 0;
}
( 1110 0001 ^ 0001 1110 ) >> 1
1110 0001
0001 1110
---------
1111 1111 >> 1  
1111 1111

//0x8F   0x80   
int main()
{
	char a = 0x1E;//0000 0000 0000 0000 0000 0000 0001 1110
	               
	char b = 0x8F;//1111 1111 1111 1111 1111 1111 1000 1111
					1111 1111 1111 1111 1111 1111 0001 1110 b<<1
				    1111 1111 1111 1111 1111 1111 1110 0001 ~a
				----------------------------------------------
				^   0000 0000 0000 0000 0000 0000 1111 1111 >> 1

				0000 0000 0000 0000 0000 0000 0111 1111     1 >> 1
	              
				0111 1111

	

	a = (~a ^ b << 1) >> 1;
		
	return 0;
}



int main()
{
	//int i = 0x12345678;
	//char ch = i;

	unsigned char ch = 0x8F;
	//         1000 1111
	int i = ch;

	return 0;
}

*/

/*
#define BOOL unsigned char

#define TRUE  1
#define FALSE 0


int main()
{
	float i = 10.0;
	if (i >= -0.000001f && i <= 0.000001f)
	{
		printf("zero\n");
	}
//#define NULL    0


	int *p = NULL;
	if (p == NULL)
	{
	}

	return 0;

}


#define BOOL unsigned char

#define TRUE  1
#define FALSE 0




int main()
{
	char *str = "hello";
	
	
	while (*str)
	{
		printf("%c",*str);
		str++;
	}
	return 0;

}


int main()
{
	int i;
	for (i=0;i<10;i++)
	{
		printf("%d\n",i);
	}

	for (i=0;i<10;i++)
	{
		printf("%d\n",i);
	}


	
	return 0;
}
*/


extern int g_i;


int main()
{
	printf("%d\n",g_i);
	return 0;
}