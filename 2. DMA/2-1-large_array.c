#include <stdio.h>
/*
    DMA is also used to allocated very large array size. 
*/
int main(){
    //array reserved from heap (not local)
    int* arr = (int*) malloc(sizeof(int) * 100000);
	//--------------------------------------------------------------
    //if the allocation failed, the pointer will be set with NULL or 0
    if(arr == NULL){
        printf("Allocation Failed :(\n");
    }
    else{
        //print the address of the allocated block
        printf("Allocation Succeed %d\n", arr);
    }
	//--------------------------------------------------------------
    //make sure to free the allocated memory....
    free(arr);
	return 0;
}
