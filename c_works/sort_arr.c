#include<stdio.h>
#include<stdlib.h>
int complete[101][101];
int coor[100][3];
int main(){

    int i,n,mod;
    printf("Specify Number of Chromosomes(n):\n");
    scanf("%d",&n);
    printf("\n");
    printf("Please Select Type of Problem:\n\t1.Min-Min\n\t2.Min-Max\n\t3.Max-Min\n\t4.Max-Max\n");
    scanf("%d",&mod);
    printf("\n");
    printf("Enter data for coordinates as: x y\n");
    for (i = 0; i < n; i++)
    {
        printf("%d chromosome co-prdinates:",i+1);
        scanf("%d %d",&coor[i][0],&coor[i][1]);
    }
    coor[n][0]=coor[n][1]=-1;
    
    for (i = 0; i < n; i++)
    {
        printf("\n%d chromosome co-ordinates:%d %d",i+1,coor[i][0],coor[i][1]);
    }    
    printf("\n");

    
}