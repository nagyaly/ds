#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Student Student;
struct Student{
	int regnum;
	char name[32];
	float gpa;
};
Student* make(int regnum, char* name, float gpa){
    //allocate a variable of type "struct Student" from the heap
    Student* s1 = (Student*) malloc(sizeof(Student));
    //--------------------------------------------------------------
    //Assign values from the function arguments...
    //notice the arrow operator -> is used, because of the pointer s1
    s1->regnum = regnum;
    strcpy(s1->name, name);          //cannot use "s1->name = name"
    s1->gpa = gpa;
	printf("in make: %d %s %.2f\n", s1->regnum, s1->name, s1->gpa);
    //return the value of pointer s1 thats hols the address of the new student
    return s1;
}
int main(){
    //call the function "make" to receive the address of the variable.
    Student* p = make(100, "Noor", 3.5);
	printf("p dereference: %d %s %.2f\n", p->regnum, p->name, p->gpa);	
	return 0;
}
/*
	#expected output:
    in make: 100 Noor 3.50
    p dereference: 100 Noor 3.50
*/
