//CH.SC.U4CSE24140 - Rohith S
#include<stdio.h>
int main(){
    int n,result,i,j;
    int matrix[3][3];
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("Enter row %d column %d element: ",i+1,j+1);
            scanf("%d",&matrix[i][j]);
        }
    }
printf("\n");
printf("You've Entered Matrix \n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    printf("Transpose of The Above Matrix is: \n");
    int transpose[3][3];
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            transpose[j][i]=matrix[i][j];
        }
    }
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%d ",transpose[i][j]);
        }
        printf("\n");
    }
return 0;
}