#include <stdio.h>
int main()
{
    int n;
    printf("Enter the number of elements of array:  ");
    scanf("%d",&n);
    int a[n];

    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
       
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
   
   int b[n];
   for(int i=0;i<n;i++){
    b[i]=a[n-1-i];

   }

   printf("The reversed array is\n");
   
    for(int i=0;i<n;i++){
        printf("%d ",b[i]);
    }
    return 0;
}