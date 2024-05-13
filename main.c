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

int lineSearch(float a, float* mass, int n)
{
	for (int k =0;k<n;++k)
		if (mass[k]==a) return k;
	
	return -1;
}


int biSearch(float a, float* mass, int n)
{
	int low,middle,high;
	low=0;
	high=n-1;
	while(low<high)
	{
		middle=(low+high)/2;
		if (a<mass[middle])
			high=middle-1;
		else if(a>mass[middle])
			low=middle+1;
		else return middle;
	}
	
	return -1;
	
}



void ShellSort(int n, float* mass, int amount, int* step)
{
   
   int* arr=malloc(amount*sizeof(int));
   if(arr==NULL)return;
   
   for (int i=0;i<amount;++i)
   {
	   arr[i]= (*(step+i));
   }
   for (int k=0;k<amount;++k)
   {
	   for (int i=arr[k];i<n;++i)
	   {
		   float tmp = mass[i];
		   int j=0;
		   for(int j=i;j>=arr[k]; j-= arr[k])
		   {
			   if (tmp<mass[j-arr[k]])
				   mass[j]=mass[j-arr[k]];
			   else 
				   break;
		   }
		   mass[j]=tmp;
		   
	   }
   }
  
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

for (int i=0;i<counter;++i)
	printf("%d\n",arr23[i]);

 float a= 1000.0;
 
  for (int k=0;k<10000;++k)
		arr[k]=(((float)rand()/(float)(RAND_MAX))*a);
 
 
 for (int m=1;m<=10000;++m) // kolichestvo iskomih elementov
 {
	 float* search=malloc(sizeof(float)*m);
	 if (search==NULL) return -1;
	 
	 for (int k=0;k<m;++k)
		 search[k]=(((float)rand()/(float)(RAND_MAX))*a); // рандомно задали искомые элементы
	 
	//int found =0;
	 time_t start1 =clock();
	 for (int n=0;n<m;++n)
	 {
		lineSearch(search[n],arr,10000);
	 }
 time_t end1 = clock();
 time_t time1= (end1-start1)/CLOCKS_PER_SEC;
 
    time_t start2=clock();
   ShellSort(10000, arr, counter, arr23);
   for (int h=0;h<m;++h)
	   biSearch(search[h],arr,10000);
   /*{ int position = biSearch(search[h],arr,10000);
		if (position !=-1)
			printf("%f, at %d position \n",search[h],position);
		else printf("%f doesnt found \n",search[h]);
   }*/
time_t end2 = clock();
time_t time2 = (end2-start2)/CLOCKS_PER_SEC;

if (time2<time1)
{
	printf("m is %d",m);
    break;
}


}

return 0;
}