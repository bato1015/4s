#include<stdio.h>

int main(){
    float gyouretu[3][4]={{-2,1,4,2},{3,-3,3,1},{5,2,-2,1}};
    //int a=gyouretu[1][0]/gyouretu[0][0];
   float c,d;

    for(int m=1;m<3;m++){
        float a=-gyouretu[m][0]/gyouretu[0][0];
        //printf("%f,",a);
        for(int i=0; i<4;i++){
            gyouretu[m][i]=gyouretu[0][i]*a+gyouretu[m][i];
        }
    }
    
    for(int m=0;m<3;m++){
        for(int i=0;i<4;i++){
            printf("%f,",gyouretu[m][i]);
        }
        printf("\n");
    }
   // b=gyouretu[0][1]*a+gyouretu[1][1];
    
    return 0;

}