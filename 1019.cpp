#include <stdio.h>


void func(int *brr)
{
	printf("%d\n",sizeof(brr));
}
/*
int main()
{
	

	int brr[10] = {10,20,30,40,50,60,70,80,90,100};


	printf("%p\n", brr);
	*(brr+3) = 200;

	printf("%d\n", *(brr+3));

	*(brr+i)    brr[i]


	//func(brr);
	//printf("%d\n",sizeof(brr));//other

	

	//printf("%p\n",brr);
	//printf("%p\n",&brr[0] + 1);

	//printf("%p\n",&brr + 1);


	
	return 0;
}


int main()
{
	int arr[10] = {10,20,30,40,50,60,70,80,90,100};
	//int *ap = arr;
	

	printf("%d\n",2[arr]);   // arr[2]   *(arr+2)
		                 //      *(2+arr)

	return 0;
}


int main()
{

	int arr[10];
	int *p;
	for (p=arr; p<arr+10; p++)
	{
		*p = 0;
	}



	return 0;
}*/
/*
int main()
{
	int arr[10];
	int i;
	for (i=0;i<10;i++)//00953630  cmp         dword ptr [i],0Ah 
	{
		arr[i] = 0;//    ���ҵ�iֵ��  Ȼ��arr+i λ�ã���0�����λ��
	}


	int *p;
	for(p=arr; p-arr<10; p++)
	{
		*p = 0;//ָ��Ч���Ը����±�
	}
	
	
	register int *p;
	register int i;

	for(i=0,p=arr; i<10; i++,p++)
	{
		*p = 0;
	}

	return 0;
}


int main()
{
	int matrix[3][5] =
	{
		1,2,3,4,5,
		6,7,8,9,10,
		11,12,13,14,15
	};

	
	return 0;
}



int main()
{
	int arr[5] = {1,2,3,4,5};

	printf("%p\n", *(&arr+1));

	printf("%p\n", &arr[0]+1);
	printf("%p\n", arr+1);

	return 0;
}

int main()
{
	int arr[3][5] =
	{
		{1,2,3,4,5},
		{6,7,8,9,10},
		{11,12,13,14,15},
	};


	arr[i] = *(arr+i);
	printf("%d\n", *(*(arr+2)+3));
	arr[2][3]


	//printf("%p\n",&arr[0][0]);
	//printf("%p\n",&arr[0][0] + 1);//4
	//printf("%p\n",arr[0] + 1);    //4

	//printf("%p\n",&arr[0] + 1);//20
	//printf("%p\n",arr + 1);//   20


	return 0;
}


���鶨��Ϊ"int arr[4][5];"

����"*(*(arr+1)+2);"��ʾ( )
{x,x,x,x,x},
{y,y,y,y,y},
{z,z,z,z,z},
{a,a,a,a,a}

A.a[1][0]+2    
B.�����1�е�2��Ԫ�صĵ�ַ    
C.�����1�е�2��Ԫ�ص�ֵ    
D.�����0�е�2��Ԫ�ص�ֵ


//�ٶ���ʼλ���ڴ��ַΪ100
int ints[20] = 
{
	10,  20,  30,  40,  50,  60,  70,  80,  90,  100, 
	110, 120, 130, 140, 150, 160, 170, 180, 190, 200 
};


int main()
{
	printf("%p\n", ints);//0
	printf("%p\n",&ints + 2);//160
	printf("%p\n", &ints[-2] + 1);//
	return 0;
}
        //160 
//    //

int main()
{
	int arr[3][5] =
	{
		{1,2,3,4,5},
		{6,7,8,9,10},
		{11,12,13,14,15},
	};

	int (*p)[5] = arr;//����  ָ��
	
	
	
	return 0;
}
*/



web



