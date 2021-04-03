/* assignment 3 */ 

#include <bits/stdc++.h>
using namespace std;
int a[1000];

void heapify(int n, int root)
{
   int minimum = root;
   int left = 2*root + 1;
   int right = 2*root + 2;

   if (left < n && a[left] < a[minimum])
   minimum = left;

   if (right < n && a[right] < a[minimum])
   minimum = right;

   if (minimum != root)
      {
      swap(a[root], a[minimum]);
      heapify(n, minimum);
      }
}
void heapSort(int n)
{
   for (int i = n/2-1; i >= 0; i--)
   heapify(n, i);

  printf("Sorted list : \n");
   for (int i = n-1; i >= 0; i--)
   {
      printf("%d ",a[0]);
      swap(a[0], a[i]);
      heapify(i, 0);
   }
}
int main()
{

   int n;
   printf("Enter the number of elements you want to insert: \n");
   scanf("%d",&n);

   printf("Enter the elements: \n");
   for(int i=0;i<n;i++)
   scanf("%d",&a[i]);

   heapSort(n);
}
