#include<iostream>    
using namespace std;      
void printFibonacci(int num){    
    static int n1=0, n2=1, n3;    
    if(num>0){    
      n3 = n1 + n2;    
      n1 = n2;    
      n2 = n3;    
      cout<<n3<<" ";    
      printFibonacci(num-1);    
    }    
}    
int main(){    
    int num;    
    cout<<"Enter the number of elements: ";    
    cin>>num;    
    cout<<"Fibonacci Series: ";    
    cout<<"0 "<<"1 ";  
    printFibonacci(num-2);
    return 0;  
}  
