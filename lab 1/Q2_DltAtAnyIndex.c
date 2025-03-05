#include <stdio.h>
int main()
{
    int n;
    printf("Enter the number of elements of array:");
    scanf("%d",&n);
    int a[n];

    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
       
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
  printf("\n");
   
   int b[n-1];
   int index;
   printf("Enter the index you want to delete:  ");
   scanf("%d",&index);

    for(int i=0;i<n-1;i++){
        if(i<index){
            b[i]=a[i];
        }
        else if(i>=index){
            b[i]=a[i+1];
        }
    }
    printf("\n");
    for(int i=0;i<n-1;i++){
        printf("%d ",b[i]);
    }

    return 0;
}