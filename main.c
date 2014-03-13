#include <stdio.h>

double input[]={0.3, 0.35, 0.4, 0.5, 0.6, 0.8, 0.95, 1.10};
double expectedOut[]={1.6, 1.4, 1.4, 1.6, 1.7, 2.0, 1.7, 2.1};
double nu=0.3;
double Wx=0.5;
double Wy=0.5;
double deltax=0;
double deltay=0;

double error(double target, double observed);
void deltaRule(double error, double x);
void updateWeight();

int main(){
	int i;
	double output;
	for(i=0;i<8;i++){
		output=Wx*input[i]+Wy;
		printf("Output expected: %e\n", expectedOut[i]);
		printf("Output observed: %e\n", output);
		deltaRule(error(expectedOut[i], output), input[i]);
		updateWeight();
		printf("Weight x in iteration %d: %e\n",i,Wx);
		printf("Weight y in iteration %d: %e\n",i,Wy);
		if((output=Wx*input[i]+Wy) == expectedOut[i]) printf("true\n");
		else printf("false, value: %e \n\n\n", output);
		//printf("Weight in iteration %d: %e\n",i,W+=((expectedOut-(W*input[i]+0.5))*nu*input[i])));
	}
	return 0;
}

double error(double target, double observed){
	return target-observed;
}

void deltaRule(double error, double x){
	deltay=nu*error;
	deltax=nu*error*x;
}

void updateWeight(){
	Wx+=deltax;
	Wy+=deltay;
}
