#include <stdio.h>
#include <stdlib.h>

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

int intersezione(int a[], int dim1, int b[], int dim2){
int num=0,i=0,j=0;
  mergeSort(a,0,dim1);
  mergeSort(b,0,dim2);

  while(i<dim1 && j<dim2){
    if (a[i]<b[j])
      i++;
    else if (a[i]>b[j])
      j++;
    else if (a[i]==b[j]) {
      num++;
      i++;
      j++;
    }
  }
return num;
}

int main(){
    int dim1=0, dim2=0,i=0;
    scanf("%d",&dim1);
    int *a=malloc(sizeof(int)*dim1);
    for(i=0;i<dim1;i++){
      scanf("%d",&a[i]);
    }
    scanf("%d",&dim2);
    int *b=malloc(sizeof(int)*dim2);
    for(i=0;i<dim2;i++){
      scanf("%d",&b[i]);
    }
    printf("%d\n",intersezione(a,dim1,b,dim2));

free(a);
free(b);
return 0;
}
