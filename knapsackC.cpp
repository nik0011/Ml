#include<iostream>
using namespace std;

int fibonacciRecursive(int n){
    if(n<=1) return n;
    return fibonacciRecursive(n-1) + fibonacciRecursive(n-2);
}

int fibCount(int n){
   
    if(n<=1) return 1;
    return fibCount(n-1) + fibCount(n-2);
}



int fibonacciIterative(int n, int &stepcount){
    
    int first=0 , second=1, next=0;
    for(int i=2;i<=n;i++){
    next=first + second;
    first=second;
    second=next;
    stepcount++;
    }
    return next;


}

int main(){
    int stepcount=0;
    cout<<"Enter the number of f number to cal:";
    int num;
    cin>>num;
    cout<<"Fibonacci Iterative:"<< fibonacciIterative(num,stepcount)<<endl;
    cout<<"Fibonacci Recursive:"<< fibonacciRecursive(num)<<endl;
    cout<<"Iterative stepcount:"<<stepcount<<endl;
    cout<<"Recursive stepcount:"<< fibCount(num);
return 0;

}