#include <stdio.h>
int main(){
    // int arr[100];    //array reserved from stack, (local varibale)
	//--------------------------------------------------------------
    //array reserved from heap (not local)
    int* arr = (int*) malloc(sizeof(int) * 100);
	//--------------------------------------------------------------
    int i;
    for(i=0;i<100;i++){
        arr[i] = i * 10;            //set value with anything...
        printf("%d\t%d\n", arr[i], &arr[i]);
    }
	//--------------------------------------------------------------
    //make sure to free the allocated memory....
    free(arr);
	return 0;
}
