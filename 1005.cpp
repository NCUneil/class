#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
//c语言，memcpy，出现内存重叠，未定义
void *my_memcpy(void *dst, void *src, size_t n)
{
	if (dst == NULL || src == NULL)
	{
		return NULL;
	}

	void *ret = dst;

	while(n--)
	{
		*(char*)dst = *(char*)src;

		dst = (char*)dst+1;
		src = (char*)src+1;
	}
	return ret;
}

void *my_memmove(void *dst, void *src, size_t n)
{
	void *ret = dst;
	if (dst <= src || dst >= ((char*)src + n))
	{
		while(n--)
		{
			*(char*)dst = *(char*)src;

			dst = (char*)dst+1;
			src = (char*)src+1;
		}
	}
	else
	{
		dst = (char*)dst + n - 1;
		src = (char*)src + n - 1;
		while(n--)
		{
			*(char*)dst = *(char*)src;
			dst = (char*)dst-1;
			src = (char*)src-1;
		}
	}
	return ret;
}



int main()
{
	char str[20] = "AABBCCDD";
	my_memmove(str+2, str, 4);

	


	return 0;
}





memset(void *dst, char ch, size_t n)

int main()
{
	char buff[20];
	//int *tmp = (int*)malloc(100*sizeof(int));
	int *tmp = (int*)calloc(100,sizeof(int));

	memset(buff, 0xFF, 20);
	return 0;
}


泛型swap
int顺序查找



int *find(int arr[], int length, int key)
{
	for(int i=0;i<10;i++)
	{
		if(arr[i] == key)
		{		
			return &arr[i];
		}
	}
	return NULL;
}

int *find(int *arr, int length, int key)
{
	for(int i=0;i<10;i++)
	{
		if(*arr == key)
		{		
			return arr;
		}
		arr++;
	}
	return NULL;
}
*/
/*

void *find(void *arr, int length, void *key, int width)
{                                              //sizeof(double)
	for(int i=0;i<length;i++)
	{
		if(memcmp(arr,key,width) == 0) 
		{		
			return arr;
		}
		arr = (char*)arr+width; 
	}
	return NULL;
}

void bubble_sort(int *arr,int length,int width)
{
	for (10)
	{
		for (10)
		{
			if (arr[j] > arr[j+1])     //函数指针，回调函数  
			{
				swap();
			}
		}
	}
}



int main()
{
	double arr[10] = {10.0,20,30,40,50,60.0,70.0,80,90,100};
	double key = 100.0;
	
	void *p = find(arr, sizeof(arr)/sizeof(arr[0]), &key, sizeof(arr[0]));
	
	printf("%lf\n",*(double*)p);



	int i1 = 255;
	int i2 = 3000;

	return 0;
}




struct NODE 
{
	int a;
	struct NODE *b;
	struct NODE *c;
};

int main()
{
	//          200
	struct NODE nodes[5] = 
	{
		{5,  nodes+3, NULL},//     200
		{15, nodes+4, nodes+3},//  212
		{22, NULL,    nodes+4},//  224
		{12, nodes+1, nodes},  //  236
		{18, nodes+2, nodes+1}  // 248
	};
	struct NODE *np = nodes+2;
	struct NODE **npp = &nodes[1].b;

	printf("%p\n",nodes);


	printf("%p\n",(*npp)->a);
	//printf("%p\n",nodes); //200
	//printf("%d\n",(*nodes[3].b->b).a);
	//printf("%p\n",nodes[3].b->b);//248
	//printf("%d\n",nodes[3].b->b->b->a);



	//printf("%d\n",nodes->a);
	//printf("%d\n",(*nodes).a);   //nodes[0]
	//printf("%p\n",nodes[3].c->a);

	//printf("%d\n",nodes.a);//           //&nodes[0].a
	//printf("%d\n",nodes->a);
	//printf("%d\n",nodes[3].a);
	//printf("%p\n",nodes[3].c);
	
	return 0;
}




struct NODE 
{
	int a;
	struct NODE *b;
	struct NODE *c;
};

struct NODE n[3] = {1,NULL,2,n,n+1,3};


int main()
{
	return 0;
}

#pragma pack(4) 
#pragma pack(4) 


64bit 平台下


//32 - win    4+1+3   8
//64 - win    4+1+3   8
//64 - linux  8 + 1 + 7 = 

1.如果什么都没说，默认4字节对齐
	如果最宽<4字节  short  ，按照最宽对齐
	如果最宽>4自己，long long ，按照4字节对齐

2.如果VS编译器，默认8字节字节
3.如果说32位，4字节

4.如果说64位，默认8字节
	如果最宽<8字节  short int ，按照最宽对齐
	如果最宽>8字节，double, long long ，按照8字节对齐


struct POS
{
	long a;// 64     8BYTE
	char b;
};




int main()
{
	printf("%d\n",sizeof(struct POS)); //64bit  long-win 4    long-unix linux  8BYTE
	//printf("%d\n",sizeof(long*));
	return 0;
}

#pragma pack(4) 

struct X
{
	int x;
	short y;
	char z;
	int d;
};
#include <stddef.h>

int main()
{
	printf("%d\n",offsetof(struct X, x));
	printf("%d\n",offsetof(struct X, y));
	printf("%d\n",offsetof(struct X, z));
	printf("%d\n",offsetof(struct X, d));
	return 0;
}


#define A(s,m)   (size_t)&(((s *)0)->m)


A(struct X, x)
*/


union X
{
	short a;
	char b[10];
};

int main()
{
	printf("%d\n",sizeof(union X));
	return 0;
}