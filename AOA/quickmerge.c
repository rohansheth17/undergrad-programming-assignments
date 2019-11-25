#include<stdio.h>
int n,k=0;
void display(int arr[20],int l, int r)
{
   printf("The changes have been made from element %d to %d.\n",l,r);
   int i;
   for(i=0;i<n;i++)
   printf("%d\t",arr[i]);
   printf("\n");
}

int quicksort(int list[], int low, int high)

    {
      
      static int count1=0;
        int pivot, i, j, temp;

        if (low < high)

        {

            pivot = low;

            i = low;

            j = high;
            
            

            while (i < j) 

            {

                while (list[i] <= list[pivot] && i <= high)

                {

                    i++;

                }

                while (list[j] > list[pivot] && j >= low)

                {

                    j--;

                }

                if (i < j)

                {	count1++;

                    temp = list[i];

                    list[i] = list[j];

                    list[j] = temp;

                }

            }
		count1++;
            temp = list[j];

            list[j] = list[pivot];

            list[pivot] = temp;
			
            	for (i = 0; i < n; i++)

        {

            printf("%d ", list[i]);

        }

        printf("\n");

            quicksort(list, low, j - 1);

            quicksort(list, j + 1, high);

        }
		return count1;
    }

void merge(int arr[], int l, int m, int r)
{
    int i=0, j=0,x=0,y=0,temp=0;
    int n1 = m - l + 1; //Size of left array
    int n2 =  r - m;  //Size of right array
 
 
    /* Copy data to temp arrays L[] and R[] 
    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
     Merge the temp arrays back into arr[l..r]
   while (i < n1 && j < n2 )
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
*/
	while (i < n1)//We will only check the condition for left array as we will only increment i.
    {
        if (arr[l+i] > arr[m+1+j])//l+i is starting index of left array. m+1+j for right array.
        {
            temp=arr[m+1+j];
		  arr[m+1+j]=arr[l+i];
		  arr[l+i]=temp;   //swapping between the two arrays
		  y=n2;
		  x=m+j+1;
            while(y>1)  //swapping within the right array to give the new element its correct position.
            {
          	if(arr[x]<=arr[x+1])
          		break;
          	if(arr[x]>arr[x+1])
          	{
       			temp=arr[x];
          		arr[x]=arr[x+1];
          		arr[x+1]=temp;
          	}
          	x++;
          	y--;	
            }
        }
        i++;
    }
 /*
    // Copy the remaining elements of L[], if there are any 
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of R[], if there are any 
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    */
    display(arr,l,r);
}

// l is for left index and r is right index of the sub-array of arr to be sorted 
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2; //Same as (l+r)/2, but avoids overflow for large l and h
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main()
{
	int arr1[50]={0},arr2[50]={0},i;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{scanf("%d",&arr1[i]);
	arr2[i]=arr1[i];
	}
	printf("\nMERGESORT:\n");
	mergeSort(arr1,0,n-1);
	printf("\nQUICKSORT:\n");
	quicksort(arr2, 0, n - 1);
	for (i = 0; i < n; i++)

        {

            printf("%d ", arr2[i]);

        }

        printf("\n");

	return 0;
}

   /* int main()
   {

        int list[50]={0};

        int size, i;
        printf("Enter the number of elements: ");

        scanf("%d", &size); 

        printf("Enter the elements to be sorted:\n");

        for (i = 0; i < size; i++)

        {

            scanf("%d", &list[i]);

        } 

        quicksort(list, 0, size - 1);

        printf("After applying quick sort\n");

        for (i = 0; i < size; i++)

        {

            printf("%d ", list[i]);

        }

        printf("\n");

     

        return 0;

*/
    
