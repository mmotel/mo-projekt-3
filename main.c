#include <stdio.h>

double fun(double x, double y){
	return (1-y)*y + x*(x*x*x + x + 2);
}

double abst(double x){
	if(x<0) return -1*x;
	return x;
}

void oblicz(double m, double a, double b){
	double h=abst(b-a)/m, Ey=2, Hy=2, t, y, Eb, EmaxB=0, Hb, HmaxB=0;
	int i = (int) m;

	for(t=a; t<=b+h/2; t=t+h){
		//if(t > b) t = b;
		y = (t*t) + 1;
		if( i % ( (int) m/10) == 0 || t == 3){

		//rozwiazanie dokladne
		printf("[x: %.4lf] [dokladne: %lf] \n", t, y);
		//metoda Eulera
		printf("[Euler: %.16lf] \t [Euler blad: %.16lf] \n", Ey, abst(Ey-y));
	//	Ey = Ey + (h * fun(t,Ey));

		//metoda Huena
		printf("[Heun:  %.16lf] \t [Heun blad:  %.16lf]\n\n", Hy, abst(Hy-y));
		} 
		i--;

		//obliczamy bledy
		Eb = abst(Ey - y);
		if(Eb > EmaxB){ EmaxB = Eb; }
		Hb = abst(Hy - y);
		if(Hb > HmaxB){ HmaxB = Hb; }

		//obliczamy y_k+1
		Ey = Ey + (h * fun(t,Ey));
		Hy = Hy + h * ( fun(t,Hy) + fun(t+h, Hy + fun(t,Hy) * h) ) / 2 ;
	}

	printf("Maksymalny blad:\n");
	printf(" \t Metoda Eulera: %.16lf \n", EmaxB);
	printf(" \t Metoda Heun'a: %.16lf \n\n", HmaxB);
}

int main(){
	double m;
	double a=1, b=3;
	int test;

	while(1){
		printf("Podaj podzial m = ");
		scanf("%lf", &m);
		if(m<0){ continue; }

		oblicz(m,a,b);
		
		printf("Aby kontynuowac nacisnij 1.");
		scanf("%i", &test);
		if(test != 1) break;
	}
	
	return 0;
}
