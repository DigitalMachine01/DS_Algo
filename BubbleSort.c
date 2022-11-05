#include <stdio.h>

typedef enum{
    ERROR_NULL_POINTER,
    SUCCESS
} error_t;

error_t BubbleSort(int * arr, int length);

int main()
{
    int arr[6] = { 2, 4, 1 , 6, 3, 0};
    int i, length;

    length = sizeof(arr)/sizeof(arr[0]);

    error_t error;

    printf("The initial array is: ");
    for(i = 0; i < length; i++)
    {
        printf("%d, ", *(arr + i));
    }

    putc('\n', stdout);

    error = BubbleSort(arr, length);

    if(error == SUCCESS)
    {
        printf("The sorted array is: ");
        for(i = 0; i < length; i++)
        {
            printf("%d, ", *(arr + i));
        }
        putc('\n', stdout);
    }

    else{
        fprintf(stderr, " We tried  to accessa Null pointer");
    }
}

error_t BubbleSort(int * arr, int length){
    if (arr == NULL){
        return ERROR_NULL_POINTER;
    }

    else{

        int pass, place, temp;

        for(pass = 0; pass < length - 1; pass++)
        {
            for(place = 0; place < (length - pass - 1); place++)
            {
                if(arr[place] > arr[place + 1]){
                    temp = arr[place];
                    arr[place] = arr[place + 1];
                    arr[place + 1] = temp;
                }
            }
        }

        return SUCCESS;
    }
}