#include<iostream>
#include <type_traits>

int mod(int a, int b) {return (((a%b)+b)%b);}

int mcd(int a, int b){
	while (b>0) {
		int r= mod(a,b);
		a=b;
		b=r;
	}
	return a;
}

int mcdr(int a, int b) {
	std::cout<<"mcd("<<a<<","<<b<<") =";
	if (b==0) {
		return a;
	}else{
		int r= mod(a,b);
		return mcdr(b,r);
	}
}

void  bezoutIdentity(int arr[], int a, int b) {
	int s1=1;
	int t1=0;
	int s=0;
	int t=1;

	while (b>0) {
		int r= mod(a,b);
		int q= a/b;

		a=b;
		b=r;

		int sAux = s1;
		s1= s;
		s= sAux- q*s;

		int tAux = t1;
		t1=t;
		t= tAux- q*t;
	}
	arr[0]= a;
	arr[1]= s1;
	arr[2]= t1;
}

int inversemod(int a, int n){
	int arr[3];
	bezoutIdentity(arr, a, n);
	int b= arr[1];
	return mod(b,n);
}

using namespace std;

int main(){
	
	cout<<"bienvenido al programa"<<endl;
	while (true){

		int a;
		int b;
		int m;
		int arr[3];
		int choice;

		cout<<"opciones: "<<endl;	
		cout<<"  1. calculadora mcd"<<endl;
		cout<<"  2. calculadora recursiva de mcd"<<endl;
		cout<<"  3. identidad de bezout"<<endl;
		cout<<"  4. inverso modular"<<endl;
		cout<<"  0. salir"<<endl;
		cin>>choice;

		switch (choice) {
			case 0:
				return 0;
				break;

			case 1: 
				cout<<"primer numero"<<endl;
				cin>>a;
				cout<<"segundo numero"<<endl;
				cin>>b;
				m= mcd(a,b);
				cout<<m<<endl;
				break;

			case 2:
				cout<<"primer numero"<<endl;
				cin>>a;
				cout<<"segundo numero"<<endl;
				cin>>b;
				m= mcdr(a,b);
				cout<<m<<endl;
				break;

			case 3:
				cout<<"primer numero"<<endl;
				cin>>a;
				cout<<"segundo numero"<<endl;
				cin>>b;
				bezoutIdentity(arr, a, b);
				cout<<arr[0]<<"="<<arr[1]<<"*"<<a<<"+"<<arr[2]<<"*"<<b<<endl;
				break;

			case 4:
				cout<<"inserte numero a"<<endl;
				cin>>a;
				cout<<"inserte valor n"<<endl;
				cin>>b;
				m= inversemod(a,b);
				cout<<"el inverso de "<<a<<" modulo "<<b<<" es "<<m<<endl;
				cout<<a<<"*"<<m<<"="<< a*m<<"mod "<<b<<"="<<mod(a,b)<<endl;
				break;

			default:
				return 0;
		}
	}
	return 0;
}
