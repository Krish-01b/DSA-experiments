//         SUM OF n


#include<stdio.h>
int sum(int n){
    if(n==0){
        return 0;
    }
    else {
        return n + sum(n-1);
    }
}
int main(){
    int n;
    printf(" enter number to get sum: ");
    scanf("%d",&n);
     int result = sum(n);
     printf("the sum of first %d numbers is: %d ",n,result);
    return 0;
   
}
