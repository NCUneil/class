#include <stdio.h>
/*
void func()
{

}


int add(int x, int y)
{
	int sum = 0;
	sum = x + y;
	return sum;
}


int main()
{
	int s = 0;
	int a = 10;
	int b = 20;

	s = add(a,b);
	return 0;
}


int
xxx

#define PI 3.14




int add(int x, int y， int z)
{
	return x+y+z;
	if ()
	{
		if ()
		{
			double
			register
			continue
		}
	}
}

int main()
{
	int s = 0;
	
	int a = 10;
	int b = 20;
	// s = add(a,b);
	_asm
	{
		push eax//1.现场保护
		push ebx//1.现场保护

		mov eax,b
		push eax //2.从右向左传参，push压栈传参
		mov ebx,a
		push ebx

		call add
		add esp,8  //4.清理参数
		mov s,eax //3.函数返回值，一般在eax中
		
		pop ebx//1.现场还原
		pop eax//1.现场还原

	}
	printf("%d\n",s);
	return 0;
}


//       1    8    23


struct MY_FLOAT
{
	unsigned int sign:1;
	unsigned int exp:8;
	unsigned int man:23;
};

int get_sys_litt()
{
	int i= 0x12345678;

	if (*(char*)&i == 0x12)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
*/


struct MY_FLOAT
{
	unsigned int man:23;
	unsigned int exp:8;
	unsigned int sign:1;
};
int float_to_int(float f)//0x00 0x00 0x41 0x42
{
	struct MY_FLOAT *p = (struct MY_FLOAT*)&f;

	//printf("0x%x\n",(*p).sign);  
	//printf("0x%x\n",(*p).exp);
	//printf("0x%x\n",(*p).man);
	p->exp -= 127;
	p->man = (p->man) >> (23 - p->exp);

	if (p->sign == 0)
	{
		return p->man | (1 << p->exp);
	}
	else
	{
		return (-1)*(p->man | (1 << p->exp));
	}
}


int main()
{
	float x = -123456.002;//0x41420000

	printf("%d\n", float_to_int(x));
	return 0;
}