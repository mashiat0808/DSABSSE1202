#include<stdio.h>

void minheapify(int array[] , int n , int i )
{
    int smallest , left , right ,temp;
    smallest =i;
    left=(2*i)+1;
    right=(2*i)+2;
    while(left<n && array[left]<array[smallest])
    {
        smallest=left;
    }
    while(right<n && array[right]<array[smallest])
    {
        smallest=right;
    }
    if(smallest!=i)
    {
        temp=array[smallest];
        array[smallest]=array[i];
        array[i]=temp;
        minheapify(array, n , smallest);
    }
}


void insertion(int array[] , int n, int value)
{
    array[n-1]=value;
    int i ;
    for(i=n/2-1;i>=0;i--)
    {
        minheapify(array,n,i);
    }

}
int main()
{
    int a[1000] ,n, size=0;
    int i;
    printf("Enter the elements of the array\n");

    for(i=0;;i++)
    {
        if(scanf("%d" , &n)!=EOF)
    {
    size++;
    insertion(a,size,n);
    }
    else break;
    }

    printf("the array\n");
    for(i=0;i<size;i++)
    {
        printf("%d " , a[i]);
    }
}
