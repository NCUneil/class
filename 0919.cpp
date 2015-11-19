#include <stdio.h>

/*
warning C4293: “<<”: 

Shift 计数为负或过大，其行为未定义


int main()
{
	unsigned int i = 0x11223344;// 00000000000000  0001 0001

	//i=i<<-1; //??

	i=  2<<1;   //    0010    0100 

	printf("%d\n",i);
	return 0;

}



int main()
{
	int i = 0x8FFFFFFF;//??10 00 1111 1111111

	       
	i=i<<33;
	printf("0x%p\n",i);
	return 0;
}


int main()
{
	unsigned int i = 0xE7;
	unsigned int j = 0x89;


	//i = i ^ j;

	printf("%p\n",~i);
	return 0;
}


//1            8          23
//符号位     指数位       尾数位

int float_to_int(float f)//       f=12.125
{
	//int *p = (int*)&f;
	//int tmp = *p;

	int tmp = *(int*)&f;

	unsigned int sign = 1;

	if (tmp & 0x80000000)
	{                       
		sign = -1;
	}
	
	return sign * ( ((tmp & 0x00FFFFFF) | 0x00800000) >> (23-(((tmp & 0x7FFFFFFF) >> 23) - 127)) );

}

int main()
{
	float f = 123456789.1;///error
	printf("%d\n",(int)f);


	printf("%d\n",float_to_int(f));
	return 0;
}


int func(int x)
{
	int countx = 0;
	while(x)
	{
		countx++;
		x = x & (x-1);
	}
	return countx;
}

int main()
{
	printf("%d\n",func(0xFEFFFFFF));
	return 0;
}

             10    20       -10
			 20    10       10
			 -10   -5       -5
			 -5    -20      15
void func(int a, int b)
{
	
}
*/



