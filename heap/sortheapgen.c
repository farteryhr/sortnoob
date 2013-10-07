#include <stdio.h>
#include <string.h>

typedef char* cstring;
const cstring strtab[]=
{
	"",
	"\t",
	"\t\t",
	"\t\t\t",
	"\t\t\t\t",
	"\t\t\t\t\t",
	"\t\t\t\t\t\t",
	"\t\t\t\t\t\t\t",
};
const cstring varname[]=
{
	"a","b","c","d","e","f","g","h","i","j","k","l","m","n",
	"o","p","q","r","s","t","u","v","w","x","y","z"
};
const char *varxt="t",*varxlong="tmp",*varx;

const char* getvar(int num)
{
	return varname[num];
}

void itemxchg(int idx0, int idx1, int depth)
{
	printf
	(
		"%s"
		"%s=%s;"
		"%s=%s;"
		"%s=%s;\n"
		,
		strtab[depth],
		varx,getvar(idx0),
		getvar(idx0),getvar(idx1),
		getvar(idx1),varx
	);
}
void heapadjust(int index, int sizeall, int depth)
{
	//printf("heapadjust %d %d %d\n",index,sizeall,depth);
	int nchild=index*2+1;
	//printf("nchild: %d\n",nchild);
	//scanf("%d",&nchild);
	if(nchild<sizeall)
	{
		if (nchild==sizeall-1)
		{
			printf
			(
				"%sif(%s>%s)\n"
				"%s{\n"
				,
				strtab[depth],getvar(nchild),getvar(index),
				strtab[depth]
			);
			itemxchg(nchild,index,depth+1);
			printf("%s}\n",strtab[depth]);
		}
		else
		{
			printf
			(
				"%sif(%s>%s&&%s>=%s)\n"
				"%s{\n"
				,
				strtab[depth],getvar(nchild),getvar(index),getvar(nchild),getvar(nchild+1),
				strtab[depth]
			);
			itemxchg(nchild,index,depth+1);
			heapadjust(nchild,sizeall,depth+1);
			printf("%s}\n",strtab[depth]);
			
			printf
			(
				"%sif(%s>%s&&%s>=%s)\n"
				"%s{\n"
				,
				strtab[depth],getvar(nchild+1),getvar(index),getvar(nchild+1),getvar(nchild),
				strtab[depth]
			);
			itemxchg(nchild+1,index,depth+1);
			heapadjust(nchild+1,sizeall,depth+1);
			printf("%s}\n",strtab[depth]);
		}
	}
}

int main(void)
{
	int n;
	int xhl;
	scanf("%d",&n);
	if(n<1||n>26)
	{
		printf("//Please enter 1~26\n");
		return 0;
	}
	varx=
	(
		(n<='t'-'a')?
		varxt:
		varxlong
	);
	printf(
		"#include <stdio.h>\n"
		"int main(void)\n"
		"{\n"
		"\tint "
	);
	for(xhl=0;xhl<n;xhl++)
		printf("%s,",getvar(xhl));
	printf("%s;\n",varx);
	printf("\tprintf(\"Please enter %d numbers:\\n\");\n",n);
	printf("\tscanf(\"");
	for(xhl=0;xhl<n;xhl++)
		printf("%%d");
	printf("\"");
	for(xhl=0;xhl<n;xhl++)
		printf(",&%s",getvar(xhl));
	printf(");\n");
	
	for(xhl=n/2-1;xhl>=0;xhl--)
		heapadjust(xhl,n,1);
	for(xhl=n-1;xhl>0;xhl--)
	{
		itemxchg(0,xhl,1);
		heapadjust(0,xhl,1);
	}
	
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
