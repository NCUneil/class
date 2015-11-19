#include <stdio.h>
#include <string.h>






/*
int main()
{
	char *p1 = (char *)1000;
	char *p2 = (char *)2000;

	printf("%d\n", p2-p1);

	return 0;
}

int main()
{
	int *p = NULL;
	*p = 100;

	int *s;
	*s = 200;

	return 0;
}
printf("%o\n",);


#define offsetof(s,m)   (size_t)&(((s *)0)->m)
*/


/*
int main()
{
	char str[] = "world";
	char *cp = str;

	printf("%p\n",cp); 
	printf("%c\n",++*cp++);//  x  orld
	printf("%s\n",str);//xorld
	
	getchar();

	//printf("%c\n", ++*++cp);//p
	//printf("%s\n",str);//wprld
 


	//printf("%c\n",++*cp);//  xorld
	//printf("%c\n",(*cp)++);//???

	//printf("%s\n",str);
//	printf("%c\n", *++cp);//
//	printf("%c\n",*cp++);//?
//	printf("%c\n",*cp);
//	printf("%p\n",&str[0]);
//	printf("%p\n",str);

//	printf("%p\n",*&cp);

//	printf("%c\n",**&cp);
//	printf("%c\n",*cp);

//	printf("%c\n",*cp+1);
//	printf("%c\n",*(cp+1));

//	printf("%p\n",cp++);//0
//	printf("%p\n",++cp);//2


	


	return 0;
}


int main()
{
	int i = 12;
	int j =24;
	int *p = &i;
	int **s = &p;

	*p = 25;
	**s = 50;
	*s = &j;
	p = &i;
	**s = 60;
	**s = *p;
	
	printf("%d %d\n",i,j);
	return 0;
}


int *find_max(int *arr, int length)
{
	int max = *arr;
	int *max_ptr = arr;

	while(length--)
	{
		if (max < *arr)
		{
			max = *arr;
			max_ptr = arr;
		}
		arr++;
	}
	return max_ptr;
}


void find_max1(int *arr, int length, int **s)
{
	int max = *arr;
	while(length--)
	{
		if (max < *arr)
		{
			max = *arr;
			*s = arr;
		}
		arr++;
	}
}
int main()
{
	int *p = NULL;
	
	int arr[10] = {1,2,3,4,5,6,7,80,9,10};

	find_max1(arr, 10, &p); 

	printf("%d\n",*p);

	//p = find_max(arr, sizeof(arr)/sizeof(arr[0]));

	//写一个函数，
	//调用该函数后，
	//让p指向arr数组中最大元素的地址

	

	return 0;
}


size_t strlen(char *str)
{	
	char *p = str;

	while(*p++!=0);

	return p-str-1;
}
int main()
{
	char str[] = "";
	printf("%d\n",strlen(str));
	return 0;
}


int main()
{
	char s1[] = "Astring";
	char s2[] = "Another";
	char s3[] = "Thrid";
	char s4[] = "Last";

	char *arr[5] = {s1,s2,s3,s4};
	               

   char *tmp;

   

	//字符串排序
	for (int i=0; i<3; i++)
	{
		for (int j=0;j<3-i;j++)
		{
			if (strcmp(arr[j], arr[j+1]) > 0)
			{
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
	


	int i = 0;
	while(arr[i] != 0)
	{
		printf("%s\n", arr[i++]);
	}

	return 0;
}

#define N 5
int main()
{
	int arr[N] = {55,40,50,10,50};
	int brr[N] = {15,25,65,55,40};
	int crr[N] = {90,70,20,65,95};
	int drr[N] = {50,40,75,85,90};



	int *prr[] = {arr,brr,crr,drr};
	int **s = prr;

	int max = **s;   

	for (int j=0;j<4;j++)
	{
		for (int i=0;i<N;i++)
		{
			printf("%d ",*(*s+i));
		}
		s++;
	}
	
	


	int max = prr[0][0];

	for (int i=0;i<sizeof(prr)/sizeof(prr[0]);i++)
	{
		for (int j=0;j<N;j++)
		{
			if(max < prr[i][j])
			{
				max = prr[i][j];
			}
		}
	}

	printf("%d\n",max);

	return 0;
}
*/

//ASLR
int main()
{
	char *arr[] = {"Astring","Another","Thrid","Last",NULL};
	char **strings = arr;


	return 0;
}

#include <stdio.h>



bool find1(char **strings, char value)
{
	char *string;

	while(*strings != NULL)
	{
		string = *strings;

		while(*string != 0)
		{
			if (*string == value)
			{
				return true;
			}
			string++;
		}

		strings++;
	}
	return false;
}

bool find2(char **strings, char value)
{	
	while(*strings != NULL)
	{
		while(**strings != 0)
		{
			if (**strings == value)
			{
				return true;
			}
			(*strings) = (*strings)+1;
		}

		strings++;
	}
	return false;
}


int main()
{
	char *arr[] = {"Astring","AnotYher","Thrid","LasXt",NULL};
	char **strings = arr;
	printf("%d\n",find2(strings, 'X'));


	return 0;
}