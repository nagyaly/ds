#include <stdio.h>
int main(){
	//a variable of type integer, name x, and value 10.
	int x = 10;
	//--------------------------------------------------------------
	//the value of x can be displayed and changed using varibale name (x).
	printf("x value: %d\n", x);
	//--------------------------------------------------------------
	//while the address/location of variable in the memory, 
	//can be displayed only using & before the variable name (&x).
	printf("x address: %d\n", &x);
	//--------------------------------------------------------------
	//a pointer of type int*, name p, and value of &x,
	//the value of the pointer = the address of x.
	//now p is a pointer to x
	int *p = &x;
	//--------------------------------------------------------------
	//same as x, the value of p can be displayed and changed using pointer name (p).
	printf("p value: %d\n", p);
	//--------------------------------------------------------------
	//same as x, add the address/location of pointer in the memory ,
	//can be displayed only using & before the pointer name (&p)
	printf("p address: %d\n", &p);
	//--------------------------------------------------------------
	//in extra, the value of x can be accessed using p,
	//by dereference the pointer p by adding * before the pointer (*p)
	printf("p dereference: %d\n", *p);	
	return 0;
}
/*
	#expected ouput:
	x value: 		10
	x address: 		1868411640
	p value: 		1868411640
	p address: 		1868411632
	p dereference: 	10
	#notice the value of p is equal to the address of x...


	#note: int* p = &x; can be written on 2 lines as follow:
	int* p;			//declare int* pointer named p;
	p = x&;			//set the value of pointer p withe the address of x (&x)
*/
