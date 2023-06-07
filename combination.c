#include <stdio.h>
void makeCombination(int arr1[], int data[], int st, int end, 
                     int index, int r);

void CombinationDisplay(int arr1[], int n, int r)
{
    int data[r];
    makeCombination(arr1, data, 0, n-1, 0, r);
}

void makeCombination(int arr1[], int data[], int st, int end,
                     int index, int r)
{

    if (index == r)
    {
        for (int j=0; j<r; j++)
            printf("%d ", data[j]);
        printf("\n");
        return;
    }
    for (int i=st; i<=end && end-i+1 >= r-index; i++)
    {
        data[index] = arr1[i];
        makeCombination(arr1, data, i+1, end, index+1, r);
    }
}
int main()
{
    int arr1[] = {1, 5, 4, 6, 8, 12};
    int r = 3,i;
    int n = sizeof(arr1)/sizeof(arr1[0]);
 //------------- print original array ------------------	
	printf("The given array is:  \n");
	for(i = 0; i < n; i++)
		{
			printf("%d  ", arr1[i]);
		}
	printf("\n");
//------------------------------------------------------ 
	printf("The combination from by the number of elements are: %d\n",r);
	printf("The combinations are: \n");	
    CombinationDisplay(arr1, n, r);
}