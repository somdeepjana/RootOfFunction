#include<stdio.h>
#include<math.h>
#include<windows.h>

int decPoint= 0;

//UI Functions
void changeDec();
void mainScreen();

//Operation Functions
void bisection();
void newton();
void RegFalsi();

//mathamatical functions
float f(float x){
	return x*x*x - 4*x - 9;
	
}

float df(float x){
	return 3*x*x - 4;
	
}

int r(float a){
	int multiVal= pow(10, decPoint);
	float correctVal= a* multiVal;
	return round(correctVal);
}


void main(){
	changeDec();
	mainScreen();
	
}

//UI Functions
void changeDec(){
	SetConsoleTitle("Decimal Point");
	system("COLOR 02");
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n				Correct Upto Decimal Point[Highest 5]: ");
OutRangeDecPoint:
	scanf("%d", &decPoint);
	fflush(stdin);
	if(decPoint>5 || decPoint<0){
		printf("\n				[Alert]Enter a value in range: ");
		system("COLOR 04");
		goto OutRangeDecPoint;
	}
	
}

void mainScreen(){
	SetConsoleTitle("Main Menu");
	system("COLOR 03");
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n							Main Menu");
	printf("\n\n\n\n				01. Bisection Method		02. Newton-Raphson Method");
	printf("\n				03. Regular-Falsi Method	04.  Change Decimal Point");
	printf("\n\n\n				Take a Option: ");
	
wrongOptionRepeat:
	
	switch(getch()){
		case '1':
			bisection();
			break;
		case '2':
			newton();
			break;
		case '3':
			RegFalsi();
			break;
		case '4':
			main();
			break;
		default:
			system("COLOR 0C");
			goto wrongOptionRepeat;
	}
	
}

//operational functions
void bisection(){
	system("COLOR 0E");
	SetConsoleTitle("Bisection Method");
	system("cls");
	float cPrev= 0, c=0;
	float a, b;
	
	printf("\n\n							Bisection Method\n\n");
IntervalWrongRepeat:
	printf("		Give Lower Value a= ");
	scanf("%f", &a);
	fflush(stdin);
	printf("		Give Upper Value b= ");
	scanf("%f", &b);
	fflush(stdin);
	if(f(a)*f(b)>=0){
		printf("		Wrong InterVal TryAgain....\n");
		goto IntervalWrongRepeat;
	}else{
		c= ((a+b)/2);
		printf("\n		==================			[ Calculating ]			==================\n");
		while(r(cPrev)!= r(c)){
			if(f(c) == 0){
				printf("		The Exact Root is %f", c);
				break;
			}else if(f(c)<0){
				a= c;
				printf("\n			a=	%f", a);
			}else{
				b= c;
				printf("\n			b=	%f", b);
			}
			cPrev= c;
			c= ((a+b)/2);
		}
		printf("\n		==========================================================================================\n");
		printf("\n\n		The Approximate Root correct upto %d Decimal Point is %f ", decPoint, (r(c)/pow(10,decPoint)));
	}
	printf("\n\n		Press Any key to goBack........");
	getch();
	mainScreen();
}

void newton(){
	system("COLOR 0E");
	SetConsoleTitle("Newton-Raphson Method");
	system("cls");
	float i, cPrev= 0, c=0;
	printf("\n\n							Newton-Raphson Method\n\n");
	printf("		Increment Starting Point: ");
	scanf ("%f", &i);
	c= (i-(f(i)/df(i)));
	printf("\n		==================			[ Calculating ]			==================\n");
	while(r(cPrev)!= r(c)){
		if(f(c) == 0){
			printf("			The Exact Root is %f", c);
			break;
		}else{
			printf("\n			X(next)=	%f", c);
		}
		cPrev= c;
		c= (cPrev-(f(cPrev)/df(cPrev)));
	}
	printf("\n		==========================================================================================\n");
	printf("\n\n		The Approximate Root correct upto %d Decimal Point is %f ", decPoint, (r(c)/pow(10,decPoint)));
	printf("\n\n		Press Any key to goBack........");
	getch();
	mainScreen();
}

void RegFalsi(){
	system("COLOR 0E");
	SetConsoleTitle("Regular-Falsi Method");
	system("cls");
	float cPrev= 0, c=0;
	float a, b;
	
	printf("\n\n							Regular-Falsi Method\n\n");
IntervalWrongRepeatFalsi:
	printf("		Give Lower Value a= ");
	scanf("%f", &a);
	fflush(stdin);
	printf("		Give Upper Value b= ");
	scanf("%f", &b);
	fflush(stdin);
	if(f(a)*f(b)>=0){
		printf("		Wrong InterVal TryAgain....\n");
		goto IntervalWrongRepeatFalsi;
	}else{
		c= (a*f(b) - b*f(a))/ (f(b) - f(a));
		printf("\n		==================			[ Calculating ]			==================\n");
		while(r(cPrev)!= r(c)){
			if(f(c) == 0){
				printf("		The Exact Root is %f", c);
				break;
			}else if(f(c)<0){
				a= c;
				printf("\n			a=	%f", a);
			}else{
				b= c;
				printf("\n			b=	%f", b);
			}
			cPrev= c;
			c= (a*f(b) - b*f(a))/ (f(b) - f(a));
		}
		printf("\n		==========================================================================================\n");
		printf("\n\n		The Approximate Root correct upto %d Decimal Point is %f ", decPoint, (r(c)/pow(10,decPoint)));
	}
	printf("\n\n		Press Any key to goBack........");
	getch();
	mainScreen();
	
}
