//     SELECTION SORT


#include<stdio.h>

void SS(int arr[],int n){
    int temp;
    for(int i=0;i<n-1;i++){
        int inx=i;
        for (int j=i+1;j<n;j++){
            if(arr[j]>arr[inx]){
                inx=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[inx];
        arr[inx]=temp;
    }

}
int main(){
    int n,i;
    printf("enter number of elements : ");
    scanf("%d",&n);
    int arr[n];                             
    printf("enter the values for the array: ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("the arrar is: ");
    for (i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    SS(arr,n);
    printf("the sorted array is: ");
    for (i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
return 0;
}
