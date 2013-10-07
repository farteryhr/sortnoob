#include <stdio.h>
int main(void)
{
	int n;
	const char *varnamet="t",*varnamelong="txchg",*varname;
	const char *
	scanf("%d",&n);
	if(n<1||n>26)
	{
		printf("//Please enter 1~26\n");
		return 0;
	}
	varname=
	(
		(n<='t'-'a')?
		varnamet:
		varnamelong
	);
	int xhl,xha,xhb;
	printf(
		"#include <stdio.h>\n"
		"int main(void)\n"
		"{\n"
		"\tint "
	);
	for(xhl=0;xhl<n;xhl++)
		printf("%c,",'a'+xhl);
	printf("%s;\n",varname);
	printf("\tprintf(\"Please enter %d numbers:\\n\");\n",n);
	printf("\tscanf(\"");
	for(xhl=0;xhl<n;xhl++)
		printf("%%d");
	printf("\"");
	for(xhl=0;xhl<n;xhl++)
		printf(",&%c",'a'+xhl);
	printf(");\n");
	for(xha=0;xha<n;xha++)
		for(xhb=xha+1;xhb<n;xhb++)
		{
			printf(
				"\tif(%c>%c)\n"
				"\t{\n"
				"\t\t%s=%c;\n"
				"\t\t%c=%c;\n"
				"\t\t%c=%s;\n"
				"\t}\n"
				,
				xha+'a',xhb+'a',
				varname,xha+'a',
				xha+'a',xhb+'a',
				xhb+'a',varname
			);
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
		printf(",%c",xhl+'a');
	}
	printf(");\n");
	printf(
		"\treturn 0;\n"
		"}\n"
	);
	return 0;
}
