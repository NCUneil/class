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


常指针，解引用时，只读不写
const int * p;
int const * p;

常变量，变量必须初始化（指向某个内存地址），运行时不能指向其他地址
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


栈：动态
堆：？？？
全局变量，静态变量，数据段：静态
常量区                    ：静态         
代码段                    ：静态

int main()
{
	int i = 10;//运行时，开辟空间，动态内存
	
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
         猫           咪


#include <stdlib.h> 




int main()
{

	void *p = malloc(1024);//在heap申请40字节的连续空间，值为随机
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

英文a-z





#include <stdlib.h>


int main()
{

	int *p = (int*)malloc(10*sizeof(int));
		
	for (int i=0;i<10;i++)
	{
		*(p+i) = i;
	}

	
	p = (int*)realloc(p, 2000*sizeof(int));

	//五星酒店
	int *s = (int*)calloc(10,sizeof(int));
	return 0;

}



堆空间是否需要释放？？
如何释放？
free


free()
*/

#include <stdlib.h>

int main()
{
	int *p = (int*)malloc(10);
	return 0;
}