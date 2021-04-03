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

void printHeap(int n)
{
   for (int i=0; i<n; ++i)
   printf("%d ",a[i]);
}

int main()
{
   int n,k=0;
   while(scanf("%d!",&n)!=EOF)
   {
       a[k]=n;
       k++;
   }
   for (int i = k/2; i >= 0; i--)
   heapify(k, i);

   printf("Minimum Heap Tree:\n");
   printHeap(k);
}
