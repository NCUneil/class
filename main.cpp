#include <stdio.h>
#include <string.h>


/*
struct PERSON
{
	int num;
	char name[20];
	char sex;

	union
	{
		int clas;
		char title[20];
	}pos;//�����¼
	
};

int main()
{
	struct PERSON p[2] = {10086,"CMCC",'F',{501}};

	p[0].num = 118;
	strcpy(p[0].name,"yule");
	p[0].sex = 'M';
	p[0].pos.clas = 501;

	p[1].num = 1;
	strcpy(p[1].name,"yangheping");
	p[1].sex = 'F';
	strcpy(p[1].pos.title,"BOSS");

	
	return 0;
}



//IP - ֪ʶ��Ȩ


0.0.0.0   --- 255.255.255.255   IPV4  IPV6

IP   255.255.255.0
     192.168.1.1
	 127.0.0.1


//���磬     IP + ��������  --->��ǰ�������������
union IP
{
	struct CIP
	{
		unsigned char a;
		unsigned char b;
		unsigned char c;
		unsigned char d;
	}cip;//4

	int nip;//4
};



int main()
{
	//union IP ip ={{192,168,1,1}};
	//printf("%d\n",ip.nip);

	union IP ip;
	ip.nip = 16885952;
	printf("%d.%d.%d.%d\n",ip.cip.a,ip.cip.b,ip.cip.c,ip.cip.d);

	
	return 0;
}


#include <time.h>


int main()
{
	long t = time(NULL);
	printf("%ld\n",t);
	return 0;
}

  
	
struct    union
*/

//�곣��
/*
#define sun 0
#define mon 10
#define tue 2
#define wed 3
#define thu 4
#define fri 5
#define sat 6

: error C2058: constant expression is not integral
Error executing cl.exe.


//ö�ٳ���
enum WEEK
{
	SUN=10, MON, TUE, WED, THU, FRI, SAT
};            

int main()
{
	printf("%f\n",SUN);



	return 0;
}


#define QQ_VIP1               0x00
#define QQ_VIP2               0x01
#define QQ_VIP3               0x02
#define QQ_VIP4               0x03
#define QQ_VIP5               0x04
#define QQ_VIP6               0x05
#define QQ_VIP7               0x11
#define QQ_VIP8               0x32

enum EnmQQNetBarFlag
{
	ENM_QQNETBARLEVEL_NONE = 0,    // ��QQ����
	ENM_QQNETBARLEVEL_GOLD,          //  ��������
	ENM_QQNETBARLEVEL_SILVER,        //   ��������
	ENM_QQNETBARLEVEL_COPPER,      //   ͭ������
	ENM_QQNetBarLevel_TGA,               //   TGA����
};


if(QPlayer == ENM_QQNETBARLEVEL_GOLD)
{
	
}


#define SINGLE  0
#define MARRIED 1 
#define DIVORCE 2

struct person
{
	char name[20];//����
	char sex;     //�Ա�
	int  age;      //����
	int  marryFlag;//����״̬��δ�飬�ѻ飬���     //�ػ�
};    


enum MF
{
	SINGLE, MARRIED, DIVORCE
}; 

struct person
{
	char name[20];
	char sex;
	int  age;
	enum MF marryFlag;
};

int main()
{
	struct person p1 = {"yule",'M',28, MARRIED};

	return 0;
}
*/



/*
enum MF
{
	SINGLE, MARRIED, DIVORCE
}; 

struct person
{
	char name[20];
	char sex;
	int  age;
	enum MF marryFlag;
};
struct person p1;


Ӣ��¶���






typedef     unsigned int    size_t;


typedef     ��������        ����


typedef unsigned char uchar;
    
	  

//typedef unsigned char u_char;
//          è          ����

int main()
{
	int i = 10;
	char ch = 20;
	u_char c = 255;

	printf("%d\n",sizeof(u_char));
	c= c+1;
	
	

	return 0;
}


#define D_INT_PTR int *

typedef int *  INT_PTR;

���Ͷ���

int main()
{
	INT_PTR p,s,q;

	int *i,j,k;




	return 0;
}


struct MY_DATE
{
	int month;
	int day;
	int year;
};
typedef struct MY_DATE    DT;



typedef struct  SA_ch_Msg_Info
{
    int  time;
    char btype;
    int  data;
}SAchMsgInfo;

struct  SA_ch_Msg_Info
{
    int  time;
    char btype;
    int  data;
}SAchMsgInfo;



struct  SA_ch_Msg_Info
{
    int  time;
    char btype;
    int  data;
};
typedef struct  SA_ch_Msg_Info SAchMsgInfo;


int main()
{
	DT date = {2015,8,20};

	return 0;
}



typedef struct MY_DATE
{
	int month;
	int day;
	int year;
}DT,*PDT;




typedef struct MY_DATE*   PDT;

int main()
{
	PDT p;
}



typedef int ARR[10];  //�����ͣ��������ͣ�������ΪARR   ARR a;


int func(int x,float y)
{
	return x;
}


typedef int (*PFUNC)(int ,float);//����ָ��    ����   ��������ΪPFUNC

int main()
{
	PFUNC p = func;
	return 0;
}
*/

#include <stdlib.h>




int main()
{
	

	FILE *p = fopen("F:\\CProject\\XG06_0819\\XG06_0819.cpp","r");
	if (p == NULL)
	{
		printf("�ļ���ʧ��\n");
		exit(-1);
	}
	char ch;

	ch = fgetc(p);
	while(ch != EOF)
	{
		printf("%c",ch);
		ch = fgetc(p);
	}


	fclose(p);

	return 0;
}



