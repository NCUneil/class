#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>



/*
int main()
{
	const char *p1 = "hello";
	char * const p2 = "world";


	p1++;
	//p1[2] = 'X';
	//*(p1+2) = 'X';
	//printf("%c\n",p1[0]);
	//printf("%c\n",*p1);

	//p2++;   

	printf("%c\n",p2[2]);
	p2[2] = 'X';

	return 0;
}



const char *p1 = "hello";

int main()
{
	//char str[2] =  {"a","b"};
	//char *strp[2] = {"a","b"};
	//char str[2][3]={"a","b"};
	//printf("")
	//char str[2][3]={'a','b','e','d','e','f'};
	return 0;
}


#include <string.h>

void Func(char str_arg[100])
{
	printf("%d\n",sizeof(str_arg));
}

int main(void)
{
	char str[] = "Hello";
	printf("%d\n",sizeof(str));//6     sizeof(str)    &str+1   str+1

	printf("%d\n",strlen(str));//5

	char *p = str;

	printf("%d\n",sizeof(p));

	Func(str);

	return 0;
}



6.�������"ָ��"����������ȷ����()        -360��2016

A.��ʹ��free�ͷŵ�һ��ָ�����ݺ�,ָ�������ֵ����ΪNULL
B.32λϵͳ���κ�����ָ��ĳ��ȶ���4���ֽ�
C.ָ�����������int��������ָ��ʵ��ָ�����ݵ�int��������
D.Ұָ����ָ��δ��������Ѿ��ͷŵ��ڴ��ַ

int *p;

int *p = (int *)malloc(sizeof(int) * 10);
//10000

free(p);//p   NULL  

#include <stdlib.h>

int main()
{
	

	int *p = (int *)malloc(sizeof(int) * 10);


	free(p);
	p = NULL;//

	*p = 1000;


	return 0;
}


int func(int a)
{
	int b;
	switch (a)
	{
	case 1: 
		b = 30;
	case 2: 
		b = 20;
		break;
	case 3: 
		b = 16;
	default: 
		b = 0;
	}
	return b;
}
int main()
{
	printf("%d\n",func(1));
	return 0;
}


int main()
{
	char str[] = "10086";
	char *p = str;

	printf("%d\n",strlen(str+1));//4
	printf("%d\n",sizeof(p++));//4
	printf("%d\n",strlen(p++));//5
	printf("%d\n",strlen(p) );

	return 0;
}



int main()
{
	char *x = "hello";
	char *y = "hellowolrd";

	if (strlen(x)-strlen(y) > 0)
	{
		printf("%s\n",x);
	}
	else
	{
		printf("%s\n",y);
	}
	return 0;
}



int main()
{
	char str[] = "hello";

	char *p = str;

	printf("%c\n", ++*p++);   //���� 10���ʽ
    


	return 0;
}

size_t strlen1(const char *str)
{
	int length = 0 ;
	while(*str++ != '\0')
	{
		length++;
	}
	return length;
}

size_t strlen2(const char *str)
{
	const char *tmp = str;
	while(*tmp++ != '\0');
	return tmp-str;
}



int main()
{
	char *x = "hello";

	strlen(x);
	
	return 0;
}


int arr[10];

c++

stl
vector


int main()
{
	int i = 10;
	int j = 20;

	int k;
	//k = i + j;

	__asm
	{
		push eax
		mov eax, i
		add eax, j
		mov k,eax
		pop eax
	}
	

	printf("%d\n",k);

	return 0;
}


warning C4996: 

'strcpy': This function or variable may be unsafe. 
Consider using strcpy_s instead. 


To disable deprecation, use _CRT_SECURE_NO_WARNINGS. 
See online help for details.

int main()
{
	char str[] = "helloworldaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	int money = 1234;
	char buff[2];

	


	strcpy(buff,str);//��дC++ ��ȫ���� 

	printf("%d\n",money);
	return 0;
}

// ��ȫ  ��  Ч��   �ɷ���


int main()
{
	char s1[20] = "hello";//hellowolrdworld
	char s2[20] = "world";

	printf("%d\n",strlen(strcat(strcat(s1,s2),s2)));
	//printf("hello\n");
	return 0;
}*/
/*
"helloworld"  ,, l
0        8

10
"dlrowolleh"   strchr
  2


char *strrchr(char *string, char ch)
{
	size_t len = strlen(string)
	string = string + len-1;

	for (int i=0; i<len; i++)
	{
		if (*string == ch)
		{
			return string;
		}
		string--;
	}

	return NULL;
}
char *strchr(char *string, char ch)
{
	while(*string != 0)
	{
		if (*string == ch)
		{
			return string;
		}
		string++;
	}
	return NULL;
}
*//*
int count = 0;

char *my_strstr(char *s1, char *s2)
{
	int len = strlen(s2);
	while(*s1 != 0)
	{
		if( strncmp(s1,s2,len) == 0 )
		{
			return s1;
		}
		s1++;
		count++;
	}
	return NULL;
}

//��С��˾��д������汾�ͳ�
//���ݽṹ BF  KMP     BM�Ƚ�
//         7   10      12


char *you_strstr(char *s1, char *s2)
{
	int len = strlen(s2);
	char *tmp;

	while((tmp=strchr(s1, *s2)) != NULL)
	{
		if(strncmp(tmp,s2,len) == 0)
		{
			return tmp;
		}
		s1 = tmp+1;
		count++;
	}
	return NULL;
}

int main()
{
	char s1[30] = "AAAAAAAAAaabaaabxcd";
	char s2[20] = "abx";

	printf("%s\n",my_strstr(s1,s2));
	
	printf("%d\n",count);
	return 0;
}
*/

#include <ctype.h>
int main()
{

	char ch = getchar();

	/*if(ch>='A' && ch <='Z')
	{
		printf("��д\n");
	}*/
	if (isupper(ch))
	{
		printf("��д\n");
	}



	return 0;
}
