#include<iostream>
#include<cmath>
double desviacion_estandar( int *m , int i, double z);
using namespace std;
int main(){
	int d;
	int lista[]={20,8,13,19,17,16,12,0,19,20};
	d=sizeof(lista)/sizeof(lista[0]);
	int *m= new int[d];
	double lista2[d];
	int i;
	cout<<"[ ";
	for(i=0 ; i<d ; i++){
		m[i]=lista[i];
		cout<<" "<<m[i]<<" ";
	}
	cout<<" ]";
	double s=0;
	double promedio;
	for(i=0 ; i<d ; i++){
		s=m[i]+s;
	}
	promedio=s/d;
	cout<<" La media es :"<<promedio<<endl;
	double t;
	t=(desviacion_estandar( m , d-1 , promedio )/d-1);
	double des;
	des=pow(t,(0.5));
	cout<<" desviacion estandar es :"<<des<<" .";
	for(i=0; i<d ; i++){
		if((m[i]-promedio)<0){
			lista2[i]=(m[i]-promedio)*(-1);
		}
		else{
			lista2[i]=(m[i]-promedio);
		}
	}
	int q=0;
	double menor=lista2[0];
	for(i=0; i<d ; i++){
		if(lista2[i] <= menor){
			menor=lista2[i];
			q=i;
		}
		else{
			menor=menor;
			q=q;
		}
	}
	cout<<"El numero que mas cercano a la media es: "<<m[q]<<endl;
	for(i=0; i<d ; i++){
		if(lista2[i]>(m[q]+(promedio/2)) || lista2[i]<(m[q]-(promedio/2))){
			lista2[i]=m[q];
		}
		else{
			lista2[i]=lista[i];
		}
	}
	for(i=0 ; i<d ; i++){
		cout<<" "<<lista2[i]<<" ";
	}	
	return 0;
}
double desviacion_estandar(int *m, int i, double z){
	if(i==0){
		return ((m[i]-z)*(m[i]-z));
	}
	else{
		return  ((m[i]-z)*(m[i]-z)+desviacion_estandar( m , i-1 , z)); 
	}
}

	
	
	
	
	
	
