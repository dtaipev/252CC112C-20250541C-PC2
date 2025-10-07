#include<iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;
int contar_primos(int n, int q);
int main(){
	srand(time(NULL));
	int n,i,j,z=0;
	cout<<"Ingrese la dimencion de la matriz cuadrada :"<<endl;
	cin>>n;
	int matriz[n][n];
	for(i=0; i<n; i++){	
		for(j=0 ; j<n; j++){
			matriz[i][j]=rand()%20;
		}
	}
	for(i=0; i<n; i++){
		cout<<"[ ";
		for(j=0 ; j<n; j++){
			cout<<" "<<matriz[i][j]<<" ";
		}
		cout<<" ]"<<endl;
	}
	int a,b;
	for(i=0; i<n; i++){	
		for(j=0 ; j<n; j++){
			a=matriz[i][j];
			b=contar_primos(a,a);
			if(a==0){
				z=z+1;	
			}
			else{
				if(b==a-2){
					z=z+1;
				}
				else{
					z=z+0;
				}
			}
		}
	}
	int s=0;
	int d=0;
	for(i=0; i<n; i++){
		for(j=0 ; j<n; j++){
			if(i==j){
				s=s+matriz[i][j];
			}
			else{
				s=s;
			}
			if((i+j+2)>n+1){
				d=d+matriz[i][j];
			}
			else{
				d=d;
			}
		}
	}
	//la funcion "contar_primos" solo determina si un numero es primo mediante indicadores,
	// pero no toma en cuenta si el numero se repite en la matriz. 
	cout<<"La matriz tiene :"<<z<<" numeros primos :"<<endl;
	cout<<"La suma de los elemntos de la diagonal principal es: "<<s<<endl;
	cout<<"La suma debajo de la diagonal secundaria es: "<<d;
	return 0;
}
int contar_primos(int n, int q){
	if(q==1){
		return 0;
	}
	else{
		if(n%q==0){
			return 0+contar_primos(n,q-1);
		}
		else{
			return 1+contar_primos(n,q-1);
		}
	}
}
