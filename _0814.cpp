#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vld.h>


/*
int main()
{
	int n = 0;
	scanf("%d",&n);


	//int arr[n] = {0};

	int *brr = (int*)calloc(n,sizeof(int));


	int *arr = (int*)malloc(n*sizeof(int));
	if (arr == NULL)
	{
		printf("error\n");
		exit(-1);
	}
	int *start = arr;

	for (int i=0;i<n;i++)
	{
		*arr = 0;
		arr++;
	}
	arr = start;


	arr[0]  *arr;

	return 0;
}




int main()
{
	char *p = (char *)malloc(sizeof(char) * 20);
	if (p==NULL)
	{
		exit(-1);
	}

	for (int i=0;i<20;i++)
	{
		*(p+i) = 'A'+i;
	}

	int *s = (int *)malloc(0);

	p = (char*)realloc(p,0);

	return 0;
}


void func1()
{
	int *p = (int *)malloc(1024*1024*1024*1);
	if (p ==NULL)
	{
		printf("error\n");
		exit(-1);
	}
	
}

void func()
{
	int *p = (int *)malloc(1024*1024*1024*1);
	if (p ==NULL)
	{
		printf("error\n");
		exit(-1);
	}
	free(p);
}
int main()
{
	func();
	func1();

	getchar();
	return 0;
}




int main()
{
	char *p1 = (char *)malloc(8*sizeof(char));
	for (int i=0;i<8;i++)
	{
		*(p1+i) = 'A'+i;
	}

	char *p2 = (char *)malloc(4*sizeof(char));
	for (i=0;i<4;i++)
	{
		*(p2+i) = 'a'+i;
	}

	int *p3 = (int *)malloc(5*sizeof(int));
	for (i=0;i<5;i++)
	{
		*(p3+i) = i;
	}


	return 0;
}

#include <string.h>
#include <vld.h>

int main()
{

	char str[200] = "";
	scanf("%s",str);//"hello"

	char *p = (char *)malloc(sizeof(char) * strlen(str)+1);
	strcpy(p,str);

	free(p);
	
	return 0;
}*/
/*
Visual Leak Detector Version 1.0 installed 
(single-threaded static).


WARNING: Visual Leak Detector detected memory leaks!
		 ---------- Block 58 at 0x003B0F28: 6 bytes ----------
		 Call Stack:
Data:
68 65 6C 6C    6F 00              hello... ........

Visual Leak Detector detected 1 memory leak.
Visual Leak Detector is now exiting.
The thread 0x768 has exited with code 0 (0x0).
The program 'F:\CProject\XG06_0814\Debug\XG06_0814.exe' has exited with code 0 (0x0).

Visual Leak Detector Version 1.0 installed (single-threaded static).
No memory leaks detected.
Visual Leak Detector is now exiting.
The thread 0xAF4 has exited with code 0 (0x0).
The program 'F:\CProject\XG06_0814\Debug\XG06_0814.exe' has exited with code 0 (0x0).




int main()
{
	int *p1 =(int*)malloc(10*sizeof(int));//32+ 40 +4 = 76 
	int *p2 =(int*)malloc(10*sizeof(int));
	int *p3 =(int*)malloc(10*sizeof(int));
	int *p4 =(int*)malloc(10*sizeof(int));

	return 0;
}


cannot open Debug/XG06_0814.exe for writing
Error executing link.exe.
Creating browse info file...

#include <assert.h>

char *input()
{
	//char str[200] = "";
	char *str = (char*)malloc(sizeof(char)*1024*1024*1024*3);
	assert(str != NULL);╤оят
	gets(str);        //hello
	
	
	return str;

}

int main()
{
	char *tmp = input();

	printf("%s\n",tmp);

	free(tmp);
	return 0;
}*/
#include <windows.h>


int main()
{
	while(1)
	{
		char *p = (char *)malloc(sizeof(char)*1024*1024*10);//10MB
		Sleep(1500);
	}


	return 0;
}