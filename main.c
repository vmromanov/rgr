#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int power(int base, int exponent) {
    if (exponent < 0) return -1;
    int result = 1;
    if (exponent == 0)
        return 1;
    for (int i = 0; i < exponent; ++i)
        result = result * base;
    return result;
}

void ShellSort(int n, float* mass, int amount, int* step)
{
   

  
    return;
}


int main()
{
	float arr[10000] = { 0 };
	
    int x, y;
    int counter = 0;
    for (int i = 0; (x = power(2, i)) < 10000; ++i)
        for (int j = 0; (y = power(3, j)) < 10000; ++j)
            if (x * y < 10000)
                counter++;

    int* arr23 = malloc(sizeof(int) * counter);
    
    int u = 0;
    for (int i = 0; (x = power(2, i)) < 10000; ++i)
        for (int j = 0; (y = power(3, j)) < 10000; ++j)
            if (x * y < 10000 && u<counter)
            {
                arr23[u] = x * y;
                ++u;
            }

    for (int i = 0; i < counter - 1; i++) {
        
        for (int j = 0; j < counter - i - 1; j++) {
            if (arr23[j] < arr23[j + 1]) { 

                int temp = arr23[j]; 
                arr23[j] = arr23[j + 1]; 
                arr23[j + 1] = temp; 
            }
        }
    }


    for (int i = 0; i < counter; ++i)
        printf(arr23[i]);
   /* ShellSort(10000, arr, counter, arr23);*/






























   


}