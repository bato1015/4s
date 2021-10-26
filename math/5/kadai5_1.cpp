#include<iostream>
#include<stdio.h>
#include<math.h>

double f1(double x);
double bibun(double a);

double delta(double a){ //傾き
    return -f1(a)/bibun(a);
}

double f1(double x){ //関数
    //return log(x)+x;
   return x*x;
   // return cos(x)+log(x);
}

double bibun(double a){ //微分
    double h=1.0e-10;
    double dfa;
    dfa=(f1(h+a)-f1(a))/h;
    //printf("答え:%lf\n",dfa);
    return (f1(h+a)-f1(a))/h;
}

bool hantei(int i,double a){ //収束確認
    const double mnum=1.0e-10;
    const int i_max=100;
    if(i>i_max){//最大100回まで計算をする
        printf("error");
        return false;
    }else if(mnum>fabs(delta(a))){//1.0e-10の範囲に入るまで計算する
        printf("%d回で収束　答え%lf\n",i,a);//収束回数の表示　
        return false;
    }
    return true;
}
void keisan(double a){ //ニュートン法
    int i=0;
    
     do {
            i++;
            a+=delta(a);//f(x)=0の解を求める
            printf("%d回 x:%lf\n",i,a);//解の変位を表示する
        }while(hantei(i,a));

   // printf("\n");    
}

int main(){
    //double a=1.0; //初期値
    double c=2;
    //keisan(a);
    keisan(c);
    return 0;
}