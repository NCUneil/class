#include<stdio.h>

//3*3整形矩阵对角线元素之和
int main()
{
	int a[3][3];
	int sum = 0;
	for(int i = 0;i < 3;i ++)
		for(int j = 0;j < 3;j ++)
		{
			scanf("%d",&a[i][j]);
			if(i==j)//对角线
			{sum += a[i][j];}		
		}
		printf("%d\n",sum);
		
}
//_______________________________________________________________
//杨辉三角
int main()
{
	int i=0;//列
	int n=0;//行
	int m=10;//总行数
	int a[10][10];

	for(n=0;n<m;n++)
	{
	for(i=0;i<=n;i++)
	{
		if(n==i||i==0)//每行的两边为1
		{
			a[n][i]=1;
		}
		else//除了两边外其他数的值
		{
			a[n][i]=a[n-1][i-1]+a[n-1][i];
		}
	}
	}
	for(n=0;n<m;n++)
	{
		for(i=0;i<=n;i++)
		{
		printf("%-5d",a[n][i]);
		}
		printf("\n");
	}

	return 0;
}
//_______________________________________________________________
//计算礼炮声响次数
int main()
{
	int a[22];
	int x=1;
	int y=1;
	int z=1;
	int m=0;
	int n=0;
	int i=0;
	
	for(i=0;i<=21;i++)
	{
		
	if(x<=4)
		{
			if(i%5==0)
			{
			a[i]=1;
			x++;
			}
		}
	
	if(y<=4)
		{
			if(i%6==0)
			{
			a[i]=1;
			y++;
			}
		}
		
	if(z<=4)
		{
			if(i%7==0)
			{
			a[i]=1;
			z++;
			}
		}
	}
	for(n=0;n<=22;n++)
	{
		if(a[n]==1)
		{
		m++;
		}
	}
	printf("%d\n",m);
	return 0;
}
//_______________________________________________________________
//抓交通肇事犯
int main()
{
	int m[69];
	int chepai[10][10];
	int i=31;
	int x,y,z;


	for(z=0,i=31;i<100;z++,i++)
	{
		m[z]=i*i;
	}
	
	for(x=0;x<=9;x++)
	{
		for(y=0;y<=9;y++)
		{
			chepai[x][y]=x*1000+x*100+y*10+y;
			if(x==y)
			{
				chepai[x][y]=0;
			}
			for(z=0;z<69;z++)
			{
				if(chepai[x][y]==m[z])
					printf("%d\n",chepai[x][y]);
			}
		}
	}
	

	return 0;
}
//_______________________________________________________________
//三天打渔两天晒网
int time(int year,int month,int day)
{
	int sum=0;
	int s=1990;
	int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	
	sum=(year-s)*365;
	for(int i=0;i<month-1;i++)
		{
			sum=sum+a[i];
		}
	sum+=day;
	
	//判断是否为闰年
	
	while(s<=year)
	{
		if((year%4==0&&year%100!=0)||(year%400==0))
		{
			sum++;
		}
	s++;
	}
	return sum;
}

int main()
{
	int year=1990;
	int month=1;
	int day=2;
	int x=0;

	x=time(year,month,day)%5;
	switch(x)
	{
	case 1:printf("打渔\n");break;
	case 2:printf("打渔\n");break;
	case 3:printf("打渔\n");break;
	case 4:printf("晒网\n");break;
	case 0:printf("晒网\n");break;
	}
	return 0;
}
//_______________________________________________________________
//文章中的大小写，数字，空格，以及其他字符的个数
int daxie(char a[][5])
{
	int n=0;
	int i;
	int j;

	for(i=0;i<3;i++)
	{
		for(j=0;j<5;j++)
		{
			if(65<=a[i][j]&&a[i][j]<=90)
			{
				n++;
			}
		}
	}
	return n;
}

int xiaoxie(char a[][5])
{
	int n=0;
	int i;
	int j;

	for(i=0;i<3;i++)
	{
		for(j=0;j<5;j++)
		{
			if(97<=a[i][j]&&a[i][j]<=122)
			{
				n++;
			}
		}
	}
	return n;
}

int shuzi(char a[][5])
{
	int n=0;
	int i;
	int j;

	for(i=0;i<3;i++)
	{
		for(j=0;j<5;j++)
		{
			if(48<=a[i][j]&&a[i][j]<=57)
			{
				n++;
			}
		}
	}
	return n;
}
int kongge(char a[][5])
{
	int n=0;
	int i;
	int j;

	for(i=0;i<3;i++)
	{
		for(j=0;j<5;j++)
		{
			if(a[i][j]==32)
			{
				n++;
			}
		}
	}
	return n;
}
int other(char a[][5])
{
	int n=0;
	int j;
	for(j=0;a[0][j]!=0;j++)
	{	if(65<=a[0][j]&&a[0][j]<=90);
			else if(97<=a[0][j]&&a[0][j]<=122);
			else if(48<=a[0][j]&&a[0][j]<=57);
			else if(a[0][j]==32);
			else n++;
	}
	return n;
	

}
int main()
{
	char a[][5]={'w','E','s',' ','3','g','5','e','B','9','t','j','!',0};
	printf("%d\n",daxie(a));
	printf("%d\n",xiaoxie(a));
	printf("%d\n",kongge(a));
	printf("%d\n",other(a));
	return 0;
}
//_______________________________________________________________
//电文翻译
	int main()
{
	char mima[]={"ZYXzyx"};
	char yuanwen[50];
	int j=0;

		while(mima[j]!=0)
	{
		if('A'<=mima[j]&&mima[j]<='Z')
		{
			yuanwen[j] =(26-(mima[j]-1)+64)+64;
		}
		else if('a'<=mima[j]&&mima[j]<='z')
		{
			yuanwen[j] = (26-(mima[j]-1)+96)+96;
		}
		j++;
	}
	yuanwen[j]=0;
	printf("%s\n",mima);
	printf("%s\n",yuanwen);
	return 0;
}