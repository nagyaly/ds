#include <stdio.h>
//set short alias name "struct Student" to "Student"
typedef struct Student Student;
struct Student{
	int regnum;
	char name[32];
	float gpa;
};
int main(){
	//create a variable of type "struct Student", with name s1, and some value.
	Student s1 = {100, "Noor", 3.5};
	//--------------------------------------------------------------
	//the members of struct can be accessed using the dot (.)
	printf("s1 Value: %d %s %.2f\n", s1.regnum, s1.name, s1.gpa);
	//--------------------------------------------------------------
	//and of course the address can be displayed using &s1.
	printf("s1 Address: %d\n", &s1);
	//--------------------------------------------------------------
	//a pointer of type Student*, name p, and value of &s1,
	//the value of the pointer = the address of s1.
	//now p is a pointer to s1
	Student* p = &s1;
	//--------------------------------------------------------------
	//same as s1, the value of p can be displayed and changed using pointer name (p).
	printf("p value: %d\n", p);
	//--------------------------------------------------------------
	//same as s1, add the address/location of pointer in the memory ,
	//can be displayed only using & before the pointer name (&p).
	printf("p address: %d\n", &p);
	//--------------------------------------------------------------
	//in extra, the value of s1 can be accessed using p,
	//by dereference the pointer p by adding * before the pointer (*p).
	printf("p dereference: %d %s %.2f\n", (*p).regnum, (*p).name, (*p).gpa);	
	//notice that we need parenthesis around *p, 
	//because the priority of . is greater than *.
	//--------------------------------------------------------------
	//However you can replace this operation "(*p).regnum" 
	//with arrow operator "p->regnum" as a syntactic sugar
	printf("p dereference: %d %s %.2f\n", p->regnum, p->name, p->gpa);	
	return 0;
}
/*
	#expected output:
	s1 Value: 100 Noor 3.50
	s1 Address: 1836823248
	p value: 1836823248
	p address: 1836823232
	p dereference: 100 Noor 3.50
	p dereference: 100 Noor 3.50
*/
