#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*
char *my_strpbrk(char *str, char *group)
{

	char *tmp = str;
	while(*group != '\0')
	{
		for (tmp = str; *tmp != '\0'; tmp++)
		{
			if (*tmp == *group)
			{
				return tmp;
			}
		}
		group++;
	}
	return NULL;
}



char *my_strpbrk(char *str, char *group)
{
	char *tmp;
	while(*group != 0)
	{
		if ((tmp = strchr(str, *group)) == NULL)
		{
			;//没找到
		}
		else
		{
			return tmp;
		}
		group++;
	}
	return NULL;
}


int main()
{
	char *s1 = "helloworld";
	char *s2 = "abc";


	printf("%s\n", my_strpbrk(s1,s2));


	return 0;
}



int main()
{
	size_t count = strcspn("xxdxxaaaaabbbcccdddd","ad");
	printf("%d\n",count);
	return 0;
}



int main()
{
	char str[] = "t he thE-x @dsad the    @USA#$  ththe  thee thethe the th e";
	char *p = strtok(str, " -@#$");
	
	int n = 100;
	while(p != NULL)
	{
		printf("%s\n",  p);
		p = strtok(NULL, " -@#$");
	}
	



	
	return 0;
}


size_t get_the(char *string)
{

	char *buff = (char *)malloc(strlen(string) + 1);
	if (buff == NULL)
	{
		return -1;
	}
	
	strcpy(buff, string);

	int count = 0;

	char *tmp = strtok(buff, " ");

	while(tmp != NULL)
	{
		if (strcmp(tmp, "the") == 0)
		{
			count++;
		}
		tmp = strtok(NULL, " ");
	}

	free(buff);
	return count;
}

int main()
{
	char *str = "  t    he  the  the   te  the  ";
	printf("%u\n",get_the(str));
	return 0;
}





int main()
{
	int i = 100;
	double dou = 3.14;
	void *p = &i;
	p = &dou;

	p = main;
	
	return 0;
}

int main()
{
	int *p = (int *)malloc(10 * sizeof(int));
	return 0;
}


char *my_memcpy(char *dst, char *src, size_t length)
{
	char *tmp = dst;

	while(length--)
	{
		*dst = *src;
		src++;
		dst++;
	}

	return tmp;
}
int main()
{
int arr[10] = {1,2,3,4,5,6,7,8,9,-10};
int brr[10];

void *p = my_memcpy(brr, arr, 10*sizeof(int));

return 0;
}




void *my_memcpy(void *dst, void *src, size_t length)
{
	void *tmp = dst;

	while (length--)
	{
		*(char *)dst = *(char *)src;
		dst = (char *)dst + 1;
		src = (char *)src + 1;
	}

	return tmp;
}

void *my_memmove(void*dst, void *src, size_t length)
{
	char *buff = (char*)malloc(length);

	memcpy(buff,src,4);
	memcpy(dst,buff,4);

	free(buff);

	return dst;
}
int main()
{
	char str[] = "helloworld";
	//            hehellorld
	memmove(str+2, str, 4);

	printf("%s\n",str);
	return 0;
}




int main()
{

	int i = 0x02345678;
	int j = 0x12345678;


	printf("%d\n",memcmp(&i,&j,3));
	return 0;
}


void swap(int *p1, int *p2)
{
	int tmp;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void swap(double *p1, double *p2)
{
	double tmp;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}


//泛型编程   C   void*   pfunc
void swap(void *p1, void *p2, size_t n)
{
	void *tmp = malloc(n);
    memcpy(tmp,p1,n);   
	memcpy(p1,p2,n);
	memcpy(p2,tmp,n);
	free(tmp);
}

int main()
{
	int i[20] = {10,20,30,40,50};
	int j[20] = {-10,-20,-30,-40,-50};

	swap(&i,&j, sizeof(i) );
	

	return 0;

}

//泛型的顺序查找
//泛型的冒泡排序
int find(int *arr, int length, int key)
{
	for (int i=0;i<length;i++)
	{
		if (arr[i] == key)
		{
			return i;
		}
	}
	return -1;
}


int main()
{
	double arr[] = {20,50,60,80,70,90,10};
	printf("%d\n", find(arr,sizeof(arr)/sizeof(arr[0]),220));
	return 0;
}
*/