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
		printf("��\n");
	}
	else if(input == 10)
	{
		printf("ʮ\n");
	}
	else if (input == 20)
	{
		printf("��ʮ\n");
	}
	else
	{
		printf("����ֵ\n");
	}
	return 0;
}

*/
//4��֧���ϣ�switchЧ�ʸߣ�Ϊʲô��
//           switch�ڲ�ά����һ����ת�����飩

/*
int main()
{
	int input;
	scanf("%d",&input);

	switch(input)
	{
	case 0:
		printf("��\n");
		break;
	case 10:
		printf("ʮ\n");
		break;
	case 20:
		printf("��ʮ\n");
		break;
	case 30:
		printf("��ʮ\n");
		break;
	default:
		printf("����ֵ\n");
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
#define �ȱ�     3
#define ����     2
#define ����     1
#define �������� 0


enum 
{
	��������,����,����,�ȱ�
};

int is_trangle(double a,double b,double c)
{
	//�ж�a,b,c�Ƿ���ż���������
	if (a+b < c)
	{
		return ��������;
	}
//   4  3  4
	if (a==b && a==c)
	{
		return �ȱ�;
	}
	if (a==b || a==c || b==c)
	{
		return ����;
	}
	else
	{
		return ����;
	}
}

int main()
{
	double a = 0.0;
	double b = 0.0;
	double c = 0.0;
	printf("����������\n");
	scanf("%lf %lf %lf"��&a,&b,&c);

	



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

//���Ϊ�з�����������λΪ0����ô��λ��0
//���Ϊ�з�����������λΪ1����ô��λ��1
//���Ϊ�޷�����������0
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