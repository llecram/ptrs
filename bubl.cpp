#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;
void cambiazo(int* &a, int* &b){
	int aux=*a;
	*a=*b;
	*b=aux;
}
void buble(int *arr,int len){
    bool swapp=true;
    int start=0;
    int endd=len-1;
    while(swapp){
        swapp=false;
        for(int* j=arr;j<arr+endd;j++){
            if(*j>*(j+1)){
                int* a=j+1;
                cambiazo(j,a);
                swapp=true;
            }
        }
        if(!swapp){
            break;
        }
        swapp=false;
        --endd;
        for(int* i=arr+endd;i>=arr;--i){
            if(*i>*(i+1)){
                int* a=i+1;
                cambiazo(i,a);
                swapp=true;
            }
        }
        start++;
        if(!swapp){
            break;
        }
    }
}
int main(){
    unsigned t0,t1;
    srand(time(NULL));
    int arr[10000];
    for(int i=0;i<10000;i++){
        arr[i]=rand()%10000;
    }
    t0=clock();
    buble(arr,10000);
    t1=clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    for(int i=0;i<10000;i++){
        cout<<arr[i]<<endl;
    }
    cout<<"Execution Time: " << time << endl;
    return 0;
}
