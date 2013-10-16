sortnoob
========

Write<sup>~~generate~~</sup> sorting algorithms like a noob.

Everything starts from this...
```c
#include <stdio.h>
int main(void)
{
	int a,b,t;
	printf("Please enter 2 numbers:\n");
	scanf("%d%d",&a,&b);
	if(a>b)
	{
		t=a;
		a=b;
		b=t;
	}
	printf("%d %d\n",a,b);
	return 0;
}
```
etc.

In a word, no array indexing for input numbers.

More strictly, you can use only "if" statements with comparasion operators, and copy values by "=".
The ONLY numbers who can present are "return 0;" (and "Please input x numbers").

Function calling... idk, avoid if possible. We are noobs. If used, you may pass arguments.
But also, the rules above still apply to the functions you wrote.

We might need to introduce a new complexity property of an algorithm, "Expanding complexity".

Any new work is welcomed!
