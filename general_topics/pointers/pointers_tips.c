// This file contains a general notes on pointers.
// this code is a part of preparing to a tech interview serries with in two weeks

// include standard input output library
#include <stdio.h>

// ========================================================
// global namespace
// ========================================================

// The address of a variable can be stored in another variable known as a pointer variable.
// dataType *pointerVariableName = &variableName;

void main()
{
    // Local name space. 
    int digit_value = 42;
    printf("Pointer of digit_value= %p \n", &digit_value);    // print the addresses of the integer location
    printf("Pointer of digit_value= %d \n", *(&digit_value)); // print the content of the location at the given address using the indirection operator* or dereferencing.
    
    //An integer pointer (like addressOfDigit) can only store the address of variables of integer type.
    // A pointer variable is a special variable in the sense that it is used to store an address of another variable.
    int *addressOfDigit = &digit_value;                       // A pointer to int (integer) addressOfDigit stores the address of(&) digit variable.

    // ------------------------------------------------------------------------------
    // Example
    int num = 5;
    int *p = &num;
    printf("Address using %%p = %p \n",p);
    printf("Address using %%d = %d \n",p);
    printf("Address using %%o = %o \n",p);

    // ------------------------------------------------------------------------------
    /*Such pointers are known as wild pointers. They store a garbage value (that is, memory address) of a byte that we don't know is reserved or not*/
    char *alphabetAddress;                                  /* uninitialized or wild pointer */
    char alphabet = "a";
    alphabetAddress = &alphabet;                            /* now, not a wild pointer */

    /* Suppose we dereference a wild pointer and assign a value to the memory address it is pointing at. 
    This will lead to unexpected behaviour since we will write data at a  memory block that may be free or reserved.
    To make sure that we do not have a wild pointer, we can initialize a pointer with a NULL value, making it a null pointer.
    A null pointer points at nothing, or at a memory address that users can not access.*/

    char *alphabetAddress = NULL                            /* Null pointer */ 

    // A void pointer can be used to point at a variable of any data type. It can be reused to point at any data type we want to
    void *pointerVariableName = NULL;                       // generic pointers.

    // Void pointers cannot be dereferenced as any other pointer. Appropriate typecasting is necessary.
    void *pointer = NULL;                                   // void pointer points to a NULL address
    int number = 54;                                        // reserve an integer variable with 54 value
    char alphabet = "z";                                    // reserve a char variable with 'z' value
    pointer = &number;                                      // store the address of the number variable to the pointer


    // printf("The value of number = ", *pointer);             /* Compilation Error */

    /* Correct Method */
    printf("The value of number = ", *(int *)pointer);      /* prints "The value at number = 54" */

    pointer = &alphabet;
    // printf("The value of alphabet = ", *pointer);           /* Compilation Error */

    printf("The value of alphabet = ", *(char *)pointer);      /* prints "The value at alphabet = z */


    // Library functions malloc() and calloc() which dynamically allocate memory return void pointers.
    // qsort(), an inbuilt sorting function in C, has a function as its argument which itself takes void pointers as its argument.

    // ------------------------------------------------------------------------------------------------
    /* Dangling Pointer: A dangling pointer points to a memory address which used to hold a variable. 
    Since the address it points at is no longer reserved, using it will lead to unexpected results.*/
    int *ptr;
    ptr = (int *)malloc(sizeof(int));

    *ptr = 1;
    printf("%d",*ptr);                                        /* prints 1 */

    free(ptr);                                                /* deallocation */

    *ptr = 5;
    printf("%d",*ptr);                                        /* may or may not print 5 */

    // ---------------------------------------------------------------------------------------------------
    // You can only add or subtract integers to pointers.
    int myArray = {3,6,9,12,15};
    int *pointerToMyArray = &myArray[0];
    pointerToMyArray += 3; /* Valid */
    // pointerToMyArray *= 3; /* Invalid */

    /*When you add (or subtract) an integer (say n) to a pointer, you are not actually adding
     (or subtracting) n bytes to the pointer value. You are actually adding (or subtracting) n-times
      the size of the data type of the variable being pointed bytes.
    */
   int number = 5;
    /* Suppose the address of number is 100 */
    int *ptr = &number;
    int newAddress = ptr + 3;                                   // The value stored in newAddress will not be 103, rather 112.
    /* Same as ptr + 3 * sizeof(int) */


    // Subtraction and comparison of pointers is valid only if both are members of the same array. 
    // The subtraction of pointers gives the number of elements separating them.

    
    




}