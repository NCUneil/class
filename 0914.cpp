#include <stdio.h>
#include <string.h>
#include <stdlib.h>





/*
int main()
{
	int i = 0;

	if(i>1)
	{
		if(i>2)
		{
			printf("i>1 && i>2\n");
		}
		else
		{
			printf("haha\n");
		}
	}

	
	return 0;
}

void bubble_sort(int *arr,int length)
{
	int tmp;
	for (int i=0; i<length-1; i++)
	{
		for (int j=0;j<length-1-i; j++)
		{
			if (arr[j] > arr[j+1])
			{
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
			break;
		}//1

		break;
	}//2
}//3

int main()
{
	return 0;

}



int main2()
{
	int input;
	scanf("%d",&input);

	if (input == 0)
	{
		printf("零\n");
	}
	else if(input == 10)
	{
		printf("十\n");
	}
	else if (input == 20)
	{
		printf("二十\n");
	}
	else
	{
		printf("其他值\n");
	}
	return 0;
}

*/
//4分支以上，switch效率高，为什么，
//           switch内部维护了一个跳转表（数组）

/*
int main()
{
	int input;
	scanf("%d",&input);

	switch(input)
	{
	case 0:
		printf("零\n");
		break;
	case 10:
		printf("十\n");
		break;
	case 20:
		printf("二十\n");
		break;
	case 30:
		printf("三十\n");
		break;
	default:
		printf("其他值\n");
		break;
	}

	return 0;
}



int func()
{
L2:
	printf("func\n");
	return 0;
}

int main()
{

	goto L1;


L1:	printf("hello wolrd\n");
	goto L2;
	return 0;
}
*/

//3
//2
//1
//0
/*
#define 等边     3
#define 等腰     2
#define 常规     1
#define 非三角形 0


enum 
{
	非三角形,常规,等腰,等边
};

int is_trangle(double a,double b,double c)
{
	//判断a,b,c是否能偶组成三角形
	if (a+b < c)
	{
		return 非三角形;
	}
//   4  3  4
	if (a==b && a==c)
	{
		return 等边;
	}
	if (a==b || a==c || b==c)
	{
		return 等腰;
	}
	else
	{
		return 常规;
	}
}

int main()
{
	double a = 0.0;
	double b = 0.0;
	double c = 0.0;
	printf("请输入三边\n");
	scanf("%lf %lf %lf"，&a,&b,&c);

	



	return 0;
}

int substr(char *dst,char *src,int start,int len)
{
	if (dst == NULL || src == 0)
	{
		return -1;
	}
	if (start >= strlen(src))
	{
		*dst = 0;
		return 0;
	}
	if (len<=0)
	{
		*dst = 0;
		return 0;
	}

	char *tmp = dst;
	src = src+start;

	for (int i=0;i<len;i++)
	{
		if (*src == 0)
		{
			break;
		}
		*dst++ = *src++;
	}
	*dst = 0;

	return strlen(tmp);
}




int main()
{
	char s1[20] = "helloworld";
	char s2[20];

	printf("%d\n",substr(s2,s1,3,4));
	printf("%s\n",s2);

	printf("%d\n",substr(s2,s1,100,20));
	printf("%s\n",s2);

	printf("%d\n",substr(s2,s1,3,20));
	printf("%s\n",s2);
	return 0;
}


void del_blank(char *str)
{
	
	char *buff = (char *)malloc(sizeof(char) * (strlen(str)+1));
	if (buff == NULL)
	{
		printf("error\n");
		return ;
	}
	char *s1 = str;
	char *s2 = buff;
	bool flag = true;

	while(*str != 0)
	{
		if (*str != ' ')
		{
			*buff = *str;
			buff++;
			str++;
			flag = true;
		}
		else
		{
			if (flag == true)
			{
				*buff = *str;
				buff++;
				str++;
				flag = false;
			}
			else
			{
				str++;
			}
		}
		
	}
	*buff = 0;
	strcpy(s1,s2);
	free(s2);
}

int main()
{
	char str[] = "         abc def    xyz      ";

	del_blank(str);
	printf("%s\n",str);
	return 0;
}
*/
/*
#include <limits.h>

//如果为有符号数，符号位为0，那么高位补0
//如果为有符号数，符号位为1，那么高位补1
//如果为无符号数，都补0
int main()
{
	unsigned short s = 0xFFFF;
	unsigned long  i;

	i = s;

	return 0;
}

1,11,52
 
int main()
{
	double d = 3.1415926231234;
	float f;

	f = d;
	return 0;
}
*/


//IEEE R32.
int main()
{
	double d = 1.23e200;
	float f = 3.9234567890f;

	f = d;
	printf("%f\n",f);
	return 0;
}