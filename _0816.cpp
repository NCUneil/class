#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/*
int main()
{

	int i = 100;
	int *p = &i;
	int **s = &p;
	


	printf("%d\n",*&i);
	printf("%d\n",*&p);
	printf("%d\n",**&p);
	printf("%d\n",**s);
	
	//int **  =   int *
	
	return 0;
}


int main()
{
	int i = 10;
	int j = 20;

	int *p = &i;
	int **s = &p;

	*s = &j;
	*p = 3000;
	*s = &i;
	**s = 200;
	*p = 500;

	int ***q = &s;
	***q = 300;
	**q = &i;
	*p = 600;///?????

	printf("%d - %d\n",i,j);//500 3000 
	return 0;
}
*/




/*
int[100] (*s);
有100个整型元素的数组类型

数组   指针

int main()
{
	int arr[100] = {10,20,30,40,50,60,70,80,90,100};

	//printf("%d\n", &arr[0]);
//	printf("%d\n", arr+1);
	//printf("%d\n", &arr+1);//整个数组的地址



	int (*s)[100] = &arr;

	for (int i=0;i<10;i++)
	{
		printf("%d\n",*(*s+i));
	}


	return 0;
}


我是一个指针
*p


数组类型
元素个数，元素类型


()   []    

*
double (*p)[10];



int main()
{
	int arr[3][5] = {
		{1,3,5,7,9},
		{2,4,6,8,0},
		{10,20,30,40,50}
	};

	int (*p)[5] = arr;    


	for (int i=0;i<3;i++)
	{
		for (int j=0;j<5;j++)
		{
			printf("%-2d ",*(*p+j));
		}
		printf("\n");
		p++;
	}
	return 0;
}

 

int main()
{
	//假设a地址为1000
	int a[3][4]=
	{
		{ 1, 3, 5, 7}, 
		{ 9,11,13,15},
		{17,19,21,23}
	};

	int (*p)[4] = a;

	printf("%x, %x\n",a, *p);


	printf("%x, %x\n",a[0], *(p+0));
	printf("%x, %x\n",&a[0], &a[0][0]);

	printf("%d, %d\n",a[1], p+1);
	printf("%d, %d\n",&a[1][1], *(p+1)+1);
	printf("%d, %d\n",a[2], *(p+2));
	printf("%d, %d\n",&a[2],p+2);
	printf("%d, %d\n",a[1][0],*(*(p+1)+0));
	printf("%d, %d\n",*a[2],*(*(p+2)+0));
	return 0;
}



int main()
{
	char *s1 = "zero";         //0x1000
	char *s2 = "hello";        //0x2000
	char *s3 = "world";        //0x3000
	char *s4 = "china";        //0x4000

	char * arr[4] = {s1,s2,s3,s4};
	char *tmp;
	int i;
	int j;
	int len = sizeof(arr)/sizeof(arr[0]);
	for (i=0,j=len-1   ;i<len/2;  i++,j--)
	{
		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}

	
	
	for (int k=0;k<sizeof(arr)/sizeof(arr[0]); k++)
	{
		printf("%s\n",arr[k]);
	}
	



	return 0;
}



int func1()
{
	return 1;
}

double funcx(int n,int m)
{
	return 1.0;
}

int func2()
{
	return 2;
}

int func3()
{
	return 3;
}

int func4()
{
	return 4;
}





int main()
{
	func1();//1;
	func2();//2;
	func3();//3;
	func4();//4;


	double (*p)(int, int) = funcx;

	printf("%p\n",funcx);
	printf("%p\n",p);
	printf("%p\n",*p);

	//函数指针，c语言最高技巧

	//bubble_sort(int *arr,int n);

	return 0;
}




int main()
{
	int **(*p)(int *s, char (*q)(void*, void*)) = NULL;


	return 0;
}


(char*)malloc(10);

人
void *

男人
int  *

女人
char *

其他人
int (*p)(int *,int **);


int main()
{
	int i = 10;
	void *p = &i;//  任意类型的地址都能放入void*，不需强制类型转换
	

	int arr[10];
	p = main;
	

	return 0;
}



int main(int argc, char *argv[])   
{
	int i =0;
	while(i<argc)
	{
		printf("%s\n",argv[i]);
		i++;
	}
	return 0;
}


int main(int argc, char *argv[])//   
{
	if (argc != 3)
	{
		printf("参数不正确\n");
		exit(-1);
	}
	char *buff = (char*)malloc(sizeof(char) * strlen(argv[1]) + 1);
	if (buff == NULL)
	{
		printf("error\n");
		exit(-1);
	}
	strcpy(buff,argv[1]);

	
	switch(*(argv[2]+1))
	{
	case 'P':
		printf("%s\n",buff);
		break;
	case 'L':
		buff = strlwr(buff);
		printf("%s\n",buff);
		break;
	case 'U':
		buff = strupr(buff);
		printf("%s\n",buff);
		break;
	default:
		printf("输入错误，请重新输入\n");
		break;

	}

	free(buff);
	return 0;
}
*/