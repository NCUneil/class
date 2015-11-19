#include <stdlib.h>
#include <memory.h>

char *strcpy(char *dst_str, char *src_str)
{
	char *tmp = dst_str;
	while(*dst_str++ = *src_str++);
	return tmp;
}
size_t strlen(char *str)
{
	char *p = str;
	while(*p && p++);
	return p-str;
}
char *strcat(char *dst_str, char *src_str)
{
	char *tmp = dst_str;
	while(*dst_str && dst_str++);
	while(*dst_str++ = *src_str++);
	return tmp;
}
char *strrev(char *str)
{
	char tmp;
	char *p = str;

	size_t length = strlen(str);
	char *s = str+length-1;
	length /= 2;

	while(length--)
	{
		tmp = *p;
		*p = *s;
		*s = tmp;
		s--;
		p++;
	}
	return str;
}
char *big_add(char *s1, char *s2)
{
	size_t s1_length = strlen(s1);
	size_t s2_length = strlen(s2);

	char *s = (char *)malloc(sizeof(char)*(s1_length+s2_length));
	memset(s,0,sizeof(char)*(s1_length+s2_length));

	char *tmp = s;
	strrev(s1);
	strrev(s2);
	
	while (*s1 != 0 && *s2 != 0)
	{
		*s = (*s1-'0') + (*s2-'0')+ *s;
		if (*s > 9)
		{
			*s = *s-10;
			*(s+1) += 1;
		}
		*s+= '0';
		s++;
		s1++;
		s2++;
	}
	if (*s1 != 0)
	{
		strcpy(s,s1);
	}
	if (*s2 != 0)
	{
		strcpy(s,s2);
	}
	strrev(tmp);
	return tmp;

}

int main(int argc, char *argv[])
{
	char *p = argv[1];
	char *s = argv[2];
	//char p[200] = "1234567890896854523433";
	//char s[200] = "1234567890896854523433";
	char *tmp = big_add(p, s);
	printf("%s\n",tmp);
	free(tmp);
	return 0;
}