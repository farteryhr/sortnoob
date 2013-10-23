#include <stdio.h>
#include <string.h>

typedef char* cstring;
const cstring varname[]=
{
	"a","b","c","d","e","f","g","h","i","j","k","l","m","n",
	"o","p","q","r","s","t","u","v","w","x","y","z"
};
const char* getvar(int num)
{
	return varname[num];
}
const cstring varguard="OK";
#define MERGEFMT "merge_%s_%s_%s_%s"
#define MERGEARG(ptrl,ptrr) getvar(ll),getvar(rr-1),\
	(ptrl)==lr?varguard:getvar(ptrl),\
	(ptrr)==rr?varguard:getvar(ptrr)

void genmerge(int ofs, int len)
{
	int lenl=len/2,lenr=len-lenl;
	int ll=ofs,lr=ofs+lenl,rl=lr,rr=rl+lenr;
	int xhl,xhr,xh;
	for(xhr=rr;xhr>=rl;xhr--)
		for(xhl=lr;xhl>=ll;xhl--)
		{
			if(xhr==rr&&xhl==lr)
				continue;
			printf("void " MERGEFMT "()\n{\n",
				MERGEARG(xhl,xhr)
			);
			if(xhr==rr)
			{
				for(xh=xhl;xh<lr;xh++)
					printf("\tt%s=%s;\n",getvar(ofs+xh-ll+lenr),getvar(xh));
			}
			else if(xhl==lr)
			{
				for(xh=xhr;xh<rr;xh++)
					printf("\tt%s=%s;\n",getvar(ofs+xh-rl+lenl),getvar(xh));
			}
			else
			{
				printf("\tif(%s>%s)\n",getvar(xhl),getvar(xhr));
				printf("\t{\n");
				printf("\t\tt%s=%s;\n" "\t\t"MERGEFMT"();\n",
					getvar(ofs+xhr-rl+xhl-ll),getvar(xhr),
					MERGEARG(xhl,xhr+1)
				);
				printf("\t}\n" "\telse\n" "\t{\n");
				printf("\t\tt%s=%s;\n" "\t\t"MERGEFMT"();\n",
					getvar(ofs+xhr-rl+xhl-ll),getvar(xhl),
					MERGEARG(xhl+1,xhr)
				);
				printf("\t}\n");
			}
			printf("}\n");
		}
}
void genmergerec(int ofs, int len)
{
	int lenl=len/2,lenr=len-lenl;
	if(len<=1)
		return;
	genmergerec(ofs,lenl);
	genmergerec(ofs+lenl,lenr);
	genmerge(ofs,len);
}
void gencallrec(int ofs, int len)
{
	//printf("gencallrec %d %d\n",ofs,len);
	int lenl=len/2,lenr=len-lenl;
	int xh;
	if(len<=1)
		return;
	gencallrec(ofs,lenl);
	gencallrec(ofs+lenl,lenr);
	printf("\t"MERGEFMT"();\n",
		getvar(ofs),getvar(ofs+len-1),
		getvar(ofs),getvar(ofs+lenl)
	);
	for(xh=ofs;xh<ofs+len;xh++)
		printf("\t%s=t%s;\n",getvar(xh),getvar(xh));
}
int main()
{
	int n;
	int xhl;
	scanf("%d",&n);
	if(n<1||n>26)
	{
		printf("//Please enter 1~26\n");
		return 0;
	}
	printf(
		"#include <stdio.h>\n"
	);
	printf("int ");
	for(xhl=0;xhl<n;xhl++)
		printf("%s%c",getvar(xhl),(xhl==n-1)?';':',');
	printf("\n");
	printf("int ");
	for(xhl=0;xhl<n;xhl++)
		printf("t%s%c",getvar(xhl),(xhl==n-1)?';':',');
	printf("\n");
	
	genmergerec(0,n);
	
	printf(
		"int main(void)\n"
		"{\n"
	);
	printf("\tprintf(\"Please enter %d numbers:\\n\");\n",n);
	printf("\tscanf(\"");
	for(xhl=0;xhl<n;xhl++)
		printf("%%d");
	printf("\"");
	for(xhl=0;xhl<n;xhl++)
		printf(",&%s",getvar(xhl));
	printf(");\n");
	
	gencallrec(0,n);
	
	printf("\tprintf(\"");
	for(xhl=0;xhl<n;xhl++)
	{
		printf("%%d");
		if(xhl==n-1)
			printf("\\n\"");
		else
			printf(" ");
	}
	for(xhl=0;xhl<n;xhl++)
	{
		printf(",%s",getvar(xhl));
	}
	printf(");\n");
	printf(
		"\treturn 0;\n"
		"}\n"
	);
}
