#include <stdio.h>
#include <windows.h>
#include <assert.h>
#include <stdlib.h>


#include <time.h>

typedef long clock_t;


//ʱ�临�Ӷȣ��ռ临�Ӷȷ���  ��ǰ����
//���ܷ�����
/*
clock_t t1 = clock();//100

clock_t t2 = clock();//2100


typedef long long          __time32_t; 
typedef __time32_t     time_t; 
    tm
int main()
{
	
	time_t t1;
	time(&t1);

	//printf("%lld\n", t1);
	char *t2 = ctime(&t1);
	*t2 = 'X';
	printf("%s\n",t2);

	//printf("%s\n", ctime(&t1));


	return 0;
}

int main()
{
	time_t t1;
	time(&t1);


	struct tm *p = gmtime(&t1);
	printf("%s\n",asctime(p));


	time();//UNIXʱ���
	ctime();
	localtime();  tm



	return 0;
}


int main()
{
	time_t t1;
	time_t t2;


	time(&t1);

	t2 = time(NULL);
	
	return 0;
}

int main()
{
	int count0 = 0;
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	int count4 = 0;
	int count5 = 0;

	srand(time(NULL));// 0 ~ 32767    1-6
	
	int r = 0;
	for (int i=0;i<100000;i++)
	{

		r = rand()%6;
		if(r == 0)
		{
			count0++;
		}
		else if(r == 1)
		{
			count1++;
		}
		else if(r == 2)
		{
			count2++;
		}
		else if(r == 3)
		{
			count3++;
		}
		else if(r == 4)
		{
			count4++;
		}
		else if(r == 5)
		{
			count5++;
		}		
	}

	printf("%d\n",count0);
	printf("%d\n",count1);
	printf("%d\n",count2);
	printf("%d\n",count3);
	printf("%d\n",count4);
	printf("%d\n",count5);
	
	return 0;
}

//          argument count      // xg.exe -x -l -y
int main(int argc, char *argv[])
{
	for (int i=0;i<argc; i++)
	{
		printf("%s\n",argv[i]);   
	}
	
	return 0;
}



ͨ�������д����ַ�����    -L �ַ���ȫ��ת��ΪСд
					      -U �ַ���ȫ��ת��Ϊ��д
						  -* ���ַ�������ȫ��ת��Ϊ'*'

						  xg.exe Hello -L  
						               -U
									   -*
									   -X
					     *(argv[2]+1)	   
               //xg.exe  hello -L
//xg.exe  hello XXXL
int main(int argc, char **argv)
int main(int argc, char *argv[])
{
	int tmp;
	char *p = "hello";

	if (argc < 3)
	{
		printf("������������ȷ������������\n");
		exit(-1);
	}
	void *x = malloc(100);

	//����argv[1]�ַ�����  ��̬�ռ���
	char *buff = (char*)malloc(strlen(argv[1]) + 1);
	assert(buff != NULL);

	strcpy(buff, argv[1]);
	//����������


	if (*argv[2] != '-')
	{
		free(buff);
		printf("��������ȷ\n");
		exit(-1);
	}
	switch(*(argv[2]+1))
	{
	case 'L':
		strlwr(buff);
		break;
	case 'U':
		strupr(buff);
		break;
	case '*':
		strset(buff,'*');
		break;
	default:
		printf("��������ȷ\n");
		exit(-2);

		
	}

	printf("%s\n", buff);
	free(buff);

	
	return 0;
}

EOF 
FILE




fopen(PATH,MODEL)
            r   w    a
			rb  wb   ab
	
	fgetc   fputc   char /�ַ�
char fgetc( FILE *stream );       EOF�жϽ���
int fputc( char ch, FILE *stream );   

	fgets   fputs       �ַ���
char *fgets( char *string, int n, FILE *stream ); NULL������־
buff[50]      buff          20      fr         
	"helloworld"
	"helloworld"
	"helloworld"
	"helloworld"

	int fputs( const char *string, FILE *stream );
	 string= "helloworld"


size_t fread( void *buffer, 
			 size_t size, 
			 size_t count, 
			 FILE *stream );  


size_t fwrite( const void *buffer, 
			  size_t size, 
			  size_t count, 
			  FILE *stream );


fseek   rewind   ftell
int fseek(FILE *stream, 
		  long offset,     -10
		  int origin );
			SEEK_CUR
			SEEK_END
			SEEK_SET


rewind

fseek(FILE*,0,SEEK_SET);

long ftell(FILE *stream );

fclose(f);

long GetFileSize(char *PATH)
{
	FILE *f = fopen(PATH,"r");
	assert(f != NULL);

	long size = ftell(f,0,SEEK_END);
	fclose(f);
	return size;
}









fclose

getchar   putchar    fgetc   fputc
gets      puts       fgets   fputs
printf    scanf     

fread  fwrite

fseek   rewind   ftell

fflush



fprintf fscanf  sprintf  VIPPPPPPPPPPPPPPPPPPPPPPPPPP



[]
[sscanf  ]

tmpfile
tmpnam
remove
rename


int main()
{
	FILE* fr = fopen("c:\\1.txt", "r");
	assert(fr != NULL);

	int i1,i2,i3,i4;

	//fprintf(fw,"%d %d %d %d is %s year",2,0,0,0,"leap");
	//fscanf(fr,"%d,%d,%d,%d",&i1,&i2,&i3,&i4);
	fclose(fr);

	return 0;
}



strcat(char *,char *)

int main()
{
	char buff[2];

	sprintf(buff,"%d %f %c",1234,3.14f,'X');
	return 0;
}

tmpfile
tmpnam
remove
rename




//   filemon
int main()
{
	FILE *f = tmpfile();
	fputc('X',f);

	fflush(f);

	getchar();

	fclose(f);

	return 0;
}


int main()
{
	char buff[128];

	sprintf(buff,"%d%d%d%d%dtmp.txt", rand(),rand(),rand()rand())


	printf("%s\n",tmpnam(buff));
	return 0;
}


int main()
{
	int i = remove("c:\\1.doc");

	printf("%d\n",i);//-1  �ļ�������  ɾ��ʧ��
	                 //0   ɾ���ɹ�

	return 0;
}


int main()
{
	rename("c:\\2.doc" ,"f:\\2.doc");
	return 0;

}*/