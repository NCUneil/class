#include <stdio.h>
#include <string.h>

/*
i i+1

[0] [1]
[8] [9]
//[9] [10]


void swap(int *a,int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void bubble_sort(int *array,int len)
{
	for (int i=0;i<len-1;i++)
	{
		for (int j=0;j<len-1-i;j++)
		{
			if (array[j] > array[j+1])
			{
				swap(&array[j], &array[j+1]);   
			}
		}
	}
}

int main()
{
	int arr[] = {30,20,10,40,60,50,70,90,80,0};
	bubble_sort(arr,sizeof(arr)/sizeof(arr[0]));

	return 0;
}

'p' : const object must be initialized if not extern
Error executing cl.exe.


��ָ�룬������ʱ��ֻ����д
const int * p;
int const * p;

�����������������ʼ����ָ��ĳ���ڴ��ַ��������ʱ����ָ��������ַ
int * const p;


int main()
{
	int i = 10;
	int j = 20;

	int * const p = &i;
	*p = 1000;

	//p = &j;

	return 0;
}



int main()
{
	int money = 12345;

	char str[8];
	strcpy(str,"AAAAAAAABBB");


	printf("%d\n",money);
	return 0;
}


ջ����̬
�ѣ�������
ȫ�ֱ�������̬���������ݶΣ���̬
������                    ����̬         
�����                    ����̬

int main()
{
	int i = 10;//����ʱ�����ٿռ䣬��̬�ڴ�
	
	printf("%d\n",i);
	return 0;
}


int main()
{
	char buff[1024*1000] = {1,2,3};
	for (int i=0;i<3;i++)
	{
		printf("%d ",buff[i]);
	}
	return 0;
}


typedef unsigned int size_t;
         è           ��


#include <stdlib.h> 




int main()
{

	void *p = malloc(1024);//��heap����40�ֽڵ������ռ䣬ֵΪ���
	if (p == NULL)
	{
		printf("alloc error\n");
		exit(1);
	}


	*p = 'A';
	p++;
	*p = 'B';




	return 0;
}



int main()
{
	int i = 0x12345678;
	void *p = (void*)&i;

	printf("%x\n",*(char*)p);

	
	return 0;
}

#include <stdlib.h>

int main()
{
	char *p = (char *)malloc();
	if (p == NULL)
	{
		printf("alloc error\n");
		exit(1);
	}
		
	return 0;
}


int len = strlen(str);

char buff[len] = {0};

 
#include <stdlib.h>


void re_word(char *str)
{
	int len = 0;
	while(*str)
	{
		if (*str == ' ')
		{
			char *tmp = (char*)malloc(len+1);
			if (tmp == NULL)
			{
				exit(1);
			}
			for (int i=0;i<len;i++)
			{
				*(tmp+i) = *(str-len+i);
			}
			*(tmp+len) = 0;

		}
		len++;
		str++;
	}
}

int main()
{
	char str[] = "hello world china";
	re_word(str);
	return 0;

} 

Ӣ��a-z





#include <stdlib.h>


int main()
{

	int *p = (int*)malloc(10*sizeof(int));
		
	for (int i=0;i<10;i++)
	{
		*(p+i) = i;
	}

	
	p = (int*)realloc(p, 2000*sizeof(int));

	//���ǾƵ�
	int *s = (int*)calloc(10,sizeof(int));
	return 0;

}



�ѿռ��Ƿ���Ҫ�ͷţ���
����ͷţ�
free


free()
*/

#include <stdlib.h>

int main()
{
	int *p = (int*)malloc(10);
	return 0;
}