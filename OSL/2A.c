#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include <sys/wait.h>
void asc(int *a, int sz);
void desc(int *a, int sz);
int main()
{
int arr[10];
int i, size;
pid_t pid;
printf("\nEnter size of array: ");
scanf("%d", &size);
printf("\nEnter %d elements: \n",size);
for(i=0; i<size; i++)
{
scanf("%d", &arr[i]);
}
pid = fork();
if(pid == 0)
{//sleep(30);
desc(arr, size);
//exit(0);
}
else
{
//sleep(50);
wait(NULL);
asc(arr, size);
}
return 0;
}
void asc(int *a,int sz)
{
int i, j;
int temp;
for(i=0; i<sz; i++)
{
for(j=i+1; j<sz; j++)
{
if(a[i]>a[j])
{
temp = a[i];
a[i] = a[j];
a[j] = temp;
}
}
}
printf("\n Parent Process");
printf("\nSorted array in ascending order is:\n");
for(i=0; i<sz; i++)
{
printf("%d\t", a[i]) ;
}
printf("\n");
}
void desc(int *a, int sz)
{
int i, j;
int temp;
for(i=0; i<sz; i++)
{
for(j=i+1; j<sz; j++)
{
if(a[i]<a[j])
{
temp = a[i];
a[i] = a[j];
a[j] = temp;
}
}
}
printf("\n Child Process");
printf("\nSorted array in descending order is:\n");
for(i=0; i<sz; i++)
{
printf("%d\t", a[i]) ;
}
printf("\n");
}
