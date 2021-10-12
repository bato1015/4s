#include<stdio.h>


int gyouretu[30][30];
int jikai[30];
FILE *fp = NULL;

double get_x1(double x2, double x3){ //
printf("%d",gyouretu[0][0]);
    return((jikai[0]-gyouretu[0][1]-gyouretu[0][1])/gyouretu[0][0]);
}
double get_x2(double x1, double x3){
    return ((12.0-x1-x3)/4.0);
}
double get_x3(double x1, double x2){
    return ((13.0-2.0*x1-x2)/3.0);
}

void file_open(){ //ファイルを開く 
    fp = fopen("a1.txt", "r");  
    if(fp == NULL){
        printf("ファイルが開けません\n");
    }else{
         printf("ファイルが開けました\n");
    }
}

void file_enter(int gyouretu_num){ //ファイルの代入
    for(int i=0; i<gyouretu_num; i++){
        for(int m=0; m<gyouretu_num;m++){
           fscanf(fp,"%d,",&gyouretu[i][m]); 
           printf("%d,",gyouretu[i][m]);
        }
        fscanf(fp,"%d,",&jikai[i]); 
        printf("\n");
    } 
}

double stop(double num){
    double a=1-num;
    if(a<0){
        a=-1*a;
    }
    return a;
}
int main(){
    double shousuu=0.000001;
    double x1,x2,x3;
    x1=x2=x3=1.0;
    file_open();
    file_enter(3);
    while(20){
        printf("誤差:%lf\n",stop(x1));
        x1=get_x1(x2,x3);
        x2=get_x2(x1,x3);
        x3=get_x3(x1,x2);
        printf("x1=%.10f,x2=%.10f,x3=%.10f\n",x1,x2,x3);
    }
}