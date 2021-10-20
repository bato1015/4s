#include<iostream>
#include<stdio.h>
#include<math.h>

int x;
double dfa;

float f1(float x);
double bibun(double);

double yutuu(double a){
    x=a-f1(a)/bibun(a);
    return x;
}

float f1(float x){
    float fx;
   fx= x*sin(x)+log(x);
    return fx;
}
double bibun(double a){
    double da=a+0.1;
   // dfa=((2*da*da+3*da)-(2*a*a+3*a))/0.1;
    dfa=(f1(da)-f1(a))/0.1;
    //printf("答え:%f\n",dfa);
    return dfa;
}
void keisan(){
    int i=0;
    float a=10;
    printf("微分:%lf\n",bibun(50));
    printf("sin:%lf\n",sin(a));
    
    do {
            a=yutuu(a);
            i++;
            printf("a:%lf\n",a);
        }while(i<20);

}

int main(){
  // printf("答え:%lf",f1(2));
    keisan();
    return 0;
}