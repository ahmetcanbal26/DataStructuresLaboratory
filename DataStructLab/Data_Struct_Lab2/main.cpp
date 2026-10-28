#include<iostream>


using namespace std;


// Question 1.A(recursion)
int FactorialRecursion(int x){
if(x<0){
    cout<<"Error! Cant be negative numbers";
    return -1;
}
if(x==0) return 1;
if(x>0){
    return x*FactorialRecursion(x-1);
}
}


//Question 1.B(itaretively)
int Factorialitaretively(int x){
if(x<0){
        cout<<"Error! Cant be negative numbers";
    return -1;
}

int factorial=1;
if(x==0) return 1;
if(x>0){
    for(int i=1;i<=x;i++){
    factorial=factorial*i;

}
 return factorial;
}
}
// Question 2.A--Multiplication Table(Ýteration)
void MultiplicationTable(int y){

 for(int i=1;i<=10;i++){

  cout<<y<<"*"<<i<<" = "<<y*i<<"\n";

 }
}
// Question 2.B--Multiplication Table with User-Defined Range(iteration)
void MultiplicationTable_Range(int y,int z){
 for(int i=1;i<=z;i++){
    cout<<y<<"*"<<i<<" = "<<y*i<<"\n"<<"\n";
}
}
//Question.3--Staircase
int countValidWays(int remainingSteps,int prevMove) {
    if (remainingSteps == 0) {
        return 1;
    }
    if (remainingSteps<0){
        return 0;
    }
    int totalWays = 0;


    for (int i = 1; i <= 3; i++) {
        if (i != prevMove) {
        totalWays += countValidWays(remainingSteps - i, i);
    }
    }
    return totalWays;
}
// Question 4.--Sum of Digits
void SumofDigits(int z){
 int result=0;
 int a=z/1000;
 int b=(z/100)%10;
 int c=(z/10)%10;
 int d=z%10;
 cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\n";
 result=a+b+c+d;
 cout<<"Sum:"<<"\t"<<result;
}
int main(){

int FactorialRecursionValue;
int MultiplicationTableValue;

cin>>FactorialRecursionValue;
cout<<FactorialRecursion(FactorialRecursionValue)<<"\n";
cout<<Factorialitaretively(FactorialRecursionValue)<<"\n";
cin>>MultiplicationTableValue;
MultiplicationTable(MultiplicationTableValue);
cout<<"\n"<<"\n";
int range;
cout<<"Enter the Range"<<"\n";
cin>>range;
MultiplicationTable_Range(MultiplicationTableValue,range);
cout<<"\n";
cout<<"Enter number of steps"<<"\n";
int steps;
cin>>steps;
cout<<countValidWays(steps,0);
cout<<"\n"<<"Enter 4 digits number"<<"\n";
int digits_4;
cin>>digits_4;
SumofDigits(digits_4);
return 0;
}
