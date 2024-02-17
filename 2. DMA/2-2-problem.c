#include <stdio.h>
#include <string.h>
typedef struct Student Student;
struct Student{
	int regnum;
	char name[32];
	float gpa;
};
Student* make(int regnum, char* name, float gpa){
    Student s1;                     //create a variable of type "struct Student"
    //Assign values from the function arguments...
    //--------------------------------------------------------------
    s1.regnum = regnum;
    strcpy(s1.name, name);          //cannot use "s1.name = name"
    s1.gpa = gpa;
	printf("in make: %d %s %.2f\n", s1.regnum, s1.name, s1.gpa);
    //--------------------------------------------------------------
    return &s1;                     //return the address of this "local" variable
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
    p dereference: 100 "" 3.50

    #there is a problem with the local variable...
    the name is not printed correctly, because then the function finishs,
    all local varibales get reclaimed by other running programs..
*/
