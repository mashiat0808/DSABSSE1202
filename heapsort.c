/* assignment 3 */ 

#include<stdio.h>

void maxheapify(int array[] , int n , int i )
{
    int largest , left , right ,temp;
    largest =i;
    left=(2*i)+1;
    right=(2*i)+2;
    while(left<n && array[left]>array[largest])
    {
        largest=left;
    }
    while(right<n && array[right]>array[largest])
    {
        largest=right;
    }
    if(largest!=i)
    {
        temp=array[i];
        array[i]=array[largest];
        array[largest]=temp;
        maxheapify(array, n , largest);
    }
}

void buildmax(int array[] , int n)
    {
    int i ;
    for(i=n/2-1;i>=0;i--)
    {
        maxheapify(array,n,i);
    }
    }

void heapsort(int array[] , int n)
{
    int i , t;
    buildmax(array, n);
    for(i=n-1;i>=0;i--)
    {
        t=array[0];
        array[0]=array[i];
        array[i]=t;
        maxheapify(array,i,0);
    }

}
int main()
{
    int a[1000] , size;
    int i;
    printf("Enter the size of array");
    scanf("%d" , &size);
    printf("Enter the elements of the array\n");
    for(i=0;i<size;i++)
    {
        scanf("%d" , &a[i]);
    }
    heapsort(a,size);
    printf("the sorted array\n");
    for(i=0;i<size;i++)
    {
        printf("%d " , a[i]);
    }
}

