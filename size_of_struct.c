
// Print the size of the declared structure.

#include<stdio.h>
struct emp
{
	int eno;
	char ename[20];
	float esal;
};
void main()
{
	struct emp e;
	printf("size of int eno is: %d\n", sizeof(e.eno));
	printf("size of char ename[20] is: %d\n", sizeof(e.ename));
	printf("size of float esal is: %d\n", sizeof(e.esal));
	printf("size of struct emp is: %d\n", sizeof(struct emp));
}


