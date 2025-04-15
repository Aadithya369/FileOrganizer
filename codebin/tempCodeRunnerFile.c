#include<stdio.h>
int lowest(int n, int arr[n]){
    int smallest=arr[0];
    int sum;
    for(int i=0;i<n;i++){
      if(smallest>arr[i]){
        smallest=arr[i];
      }
    }
    return smallest;
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("%d",lowest(n,arr));
}