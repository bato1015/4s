#include<stdio.h>

double get_x1(double x2, double x3){ //
    return((10-x2-x3)/5);
}
double get_x2(double x1, double x3){
    return ((12.0-x1-x3)/4.0);
}
double get_x3(double x1, double x2){
    return ((13.0-2.0*x1-x2)/3.0);
}

double stop(double num){
    double a=1-num;
    if(a<0){
        a=-1*a;
    }
    return a;
}
int main(){
    double x1,x2,x3;
    x1=x2=x3=1.0;
    while(stop(get_x1(x2,x3))>0.000001&&stop(get_x2(x1,x3))>0.000001&&stop(get_x3(x1,x2))>0.000001){
        printf("誤差:%lf\n",stop(x1));
        x1=get_x1(x2,x3);
        x2=get_x2(x1,x3);
        x3=get_x3(x1,x2);
        printf("x1=%.10f,x2=%.10f,x3=%.10f\n",x1,x2,x3);
    }
}