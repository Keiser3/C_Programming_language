
When we execute the above program in C compiler, it produces the given below output in the console screen.

Define the number of elements in an array: 10

 Enter 10 elements of an array:
 57
12
89
32
62
12
89
35
67
75

 Array elements after deletion of the duplicate elements:  57    12      89      32      62      35      67      75
Remove the Duplicate Elements from Sorted Array

Suppose we have a given sorted array and the task is to remove the same number of elements from the array. For example, there is an integer type array whose size is 5 and contains arr[] = {2, 2, 3, 3, 5} elements. In this sorted array, 2 and 3 numbers occurs two times. Hence, these elements are duplicate elements. So, after deleting the duplicate elements from an array arr[], we get 2, 3, 5 elements and the new size of array is 3.

Algorithm to delete the duplicate elements from sorted array

Following is the algorithm to delete the duplicate array's elements from the sorted array in the C programming language.

Define the size of elements of the array.
Read the array elements from the user.
Repeat from i = 1 to num.
if (arr[i] != arr [i + 1]
temp [j++] = arr[i]
temp [j++] = arr[n- 1]
Repeat from i = 1 to j
arr[i] = temp[i]
arr [i] = temp [i]
Return j.
Print unique elements of the array.
Example 2: Program to remove the duplicate elements from sorted array using the user-defined function

Let's consider an example to delete the same number or duplicate elements from sorted array in the C programming language.

/* program to delete the duplicate elements from sorted array in C. */  
#include <stdio.h>  
  
int duplicate_element ( int arr[], int num)  
{  
    // check num is equal to 0 and num == 1  
    if (num == 0 || num == 1)  
        return num;  
          
    // create temp array to store same number     
    int temp [num];   
      
    // declare variable  
    int i, j = 0;  
      
    // use for loop to check duplicate element  
    for (i = 0; i < num - 1; i++)  
    {  
        // check the element of i is not equal to (i + 1) next element  
        if (arr [i] != arr[i + 1])  
            temp[j++] = arr[i];  
    }  
    temp[j++] = arr[ num - 1];  
  
  
    // check the original array's elements with temporary array's elements  
    for (i = 0; i < j; i++)  
    {  
        arr[i] = temp[i];  
        }     
          
    return j;     
}  
  
int main ()  
{  
    int num;  
    printf (" Define the no. of elements of the array: ");  
    scanf (" %d", &num);  
      
      
    int arr[num], i;  
      
    printf (" Enter the elements: ");  
    // use loop to read elements one by one  
    for ( i = 0; i < num; i++)  
    {  
        scanf (" %d", &arr[i]);  
    }  
      
    printf (" \n Elements before removing duplicates: ");  
    for ( i = 0; i < num; i++)  
    {  
        printf (" %d", arr[i]);  
    }  
      
    num = duplicate_element (arr, num);  
      
    // print array after removing duplicates elements  
    printf (" \n Display array's elements after removing duplicates: ");  
    for ( i = 0; i < num; i++)  
    {  
        printf (" %d", arr[i]);  
        }     
          
    return 0;     
      
}  
When we execute the above program in C compiler, it produces the given below output in the console screen.

Define the no. of elements of the array: 10
 Enter the elements: 5
6
6
7
8
8
9
10
11
11

 Elements before removing duplicates:  5 6 6 7 8 8 9 10 11 11
 Display array's elements after removing duplicates:  5 6 7 8 9 10 11
Example 3: Program to remove the duplicate array elements using pointer

Let's consider an example to print the unique array elements by removing the duplicate element using the pointers in the C programming language.

/* program to delete the duplicate elements from sorted array using pointers in C. */  
#include <stdio.h>  
#include <stdlib.h>  
  
// declare variable  
int i, j;  
  
// definition of the function  
int remove_element ( int *ptr, int num)  
{  
int temp;  
  
// use for loop   
  
for ( i = 0; i < num-1; i++)  
{  
    for (j = i + 1; j < num; j++)  
    {  
        // if statement to check the same number int sorted array  
        if ( *(ptr+i) == *(ptr+j))  
        {  
            temp = *(ptr + j);  
            *(ptr + j) = *(ptr + num - 1);  
            *(ptr + num - 1) = temp;  
            num--;  
        }  
    }  
}     
      
    printf (" After removing the duplicate elements: ");  
    for ( i = 0; i < num; i++)  
    {  
        printf (" %d \t", *(ptr+i));  
    }  
    return 0;  
}  
  
  
int main ()  
{  
    // declare local variable  
    int num, *ptr;  
    printf (" Define the size of the array element: ");  
    scanf (" %d", &num);  
      
    ptr = (int *) malloc (num * sizeof(int));  
      
    printf (" \n Enter the elements of the array: \n");  
    // use for loop to read elements  
    for ( i = 0; i < num; i++)  
    {  
        scanf (" %d", (ptr+i));  
    }  
  
    // call function to print the unique elements  
    remove_element (ptr, num);  
    return 0;  
}  
