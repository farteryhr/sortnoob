sortnoob
========

Write<sup>~~generate~~</sup> sorting algorithms like a noob.

Like...
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
And...
```c
#include <stdio.h>
int main(void)
{
	int a,b,c,t;
	printf("Please enter 3 numbers:\n");
	scanf("%d%d%d",&a,&b,&c);
	if(a>b)
	{
		t=a;
		a=b;
		b=t;
	}
	if(a>c)
	{
		t=a;
		a=c;
		c=t;
	}
	if(b>c)
	{
		t=b;
		b=c;
		c=t;
	}
	printf("%d %d %d\n",a,b,c);
	return 0;
}
```
etc.

In a word, no array indexing for input numbers.

We might need to introduce a new complexity property of an algorithm, "Expanding complexity".
