#include <stdio.h>
#include <stdlib.h>

// Works as the function below because arrays are
// already treated as arrays.
void updateArray1(int array[]){
    array[0] = 10;
}

void updateArray2(int* array){
    array[0] = 10;
}

int main() {
    int numbers[3] = {1,2,3};

    // Updates array.
    updateArray2(numbers);

    printf("sizeof(int): %lu\n", sizeof(int));
    printf("\n");

    printf("%p\n", &numbers[0]);
    printf("%p\n", &numbers[1]);
    printf("%p\n\n", &numbers[2]);

    printf("%p\n", numbers);
    printf("%p\n", numbers+1);
    printf("%p\n\n", numbers+2);

    printf("%d\n", numbers[0]);
    printf("%d\n", numbers[1]);
    printf("%d\n", numbers[2]);
    return 0;
}