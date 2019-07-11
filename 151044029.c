/*ANIL AKBULUT HW03,Num:151044029*/
#include <stdio.h>/*Used this library*/
/*Used this definitions*/
#define PART1_ARR 6
#define PART2_ARR1 10
#define PART2_ARR2 2
/*I have defined the functions I used*/
void menu();
int take_grades(int [] );
int take_exam_grades(int[]);
double calculate_homework(int[]);
double calculate_lab(int[]);
double calculate_all(int ,int[],int);
void shape(int height);
int add(int ,int );
int sub(int ,int );
int mul(int ,int );
int div(int ,int );
int mod(int ,int );
int power(int ,int );
int doit(int f(int ,int ),int ,int );
/*This function takes 10 element into the array.*/
int take_grades(int arr[] ){
	int i;
	for(i=0;i<PART2_ARR1;i++) scanf("%d",&arr[i]);
}
/*This function calculates homework grades average and return it*/
double calculate_homework(int hw[]){
	int i,result=0;
	take_grades(hw);
	for(i=0;i<PART2_ARR1 ;i++){
		result += hw[i];
	}
	return ((double)result / PART2_ARR1 );
}
/*This function calculates lab grades average and return it*/
double calculate_lab(int lab[]){
	int i,result=0;
	take_grades(lab);
	for(i=0;i<PART2_ARR1 ;i++){
		result += lab[i];
	}
	return ((double)result / PART2_ARR1 );	
}
/*This function takes 2 element into the array.*/
int take_exam_grades(int mid_fin[]){
	int i;
	for(i=0;i<PART2_ARR2 ;i++) scanf("%d",&mid_fin[i]);
}
/*This function calculates all grades average and return it*/
double calculate_all(int avg_hw,int mid_fin[],int avg_lab){
	double result;
	take_exam_grades(mid_fin);
	result = (double)avg_hw*0.1 + (double)avg_lab*0.2 + (double)mid_fin[0]*0.3 + (double)mid_fin[1]*0.4;
	return result;
}
/*This function returns 2 numbers addition*/
int add(int first_number,int second_number){
	return first_number + second_number;
}
/*This function returns 2 numbers substraction*/
int sub(int first_number,int second_number){
	return first_number - second_number;
}
/*This function returns 2 numbers multiplication*/
int mul(int first_number,int second_number){
	return first_number * second_number;
}
/*This function returns 2 numbers division*/
int div(int first_number,int second_number){
	return first_number / second_number;
}
/*This function returns 2 numbers modulo*/
int mod(int first_number,int second_number){
	return first_number % second_number;
}
/*This function returns 2 numbers power*/
int power(int first_number,int second_number){
	int i,result=1;
	if(second_number==0) return 1;
	for(i=1;i<=second_number;i++) result = result * first_number;
	return result;
}
/*This function takes function as an argument and takes first and second number*/
int doit(int f(int first_number,int second_number),int first_number,int second_number){
	return f(first_number,second_number);
}
/*This function,you should take height of the shape from user.A triangle must
be created from the combination of stars*/
void shape(int height){
	int i;
	int star=0;
	int space=height-1;
	while(star<= (height-1)*2){
		for(i=1;i<=space;i++) printf(" ");
		printf("/");
		for(i=1;i<=star;i++) printf("*");
		printf("\\\n");
		star+=2;
		space--;	
	}
	star-=2;
	space++;
	while(star>=0){
		for(i=1;i<=space;i++) printf(" ");
		printf("\\");
		for(i=1;i<=star;i++) printf("*");
		printf("/\n");
		star-=2;
		space++;	
	}
}
/*This function is menu function.Repetitions can be used repeatedly. */
void menu(){
	int num=1,status,result=0; /*part1 variables*/
	int hw[PART2_ARR1],lab[PART2_ARR1],mid_fin[PART2_ARR2]; /*part2 variables*/
	int avg_hw,avg_lab; /*part2 variables*/
	char arr[PART1_ARR]; /*part1 variables*/
	int first_number,second_number;/*part1 variables*/
	char first_op='c',second_op;/*part1 variables*/
	while(num!=0){ /*If number is not zero,while loop continues*/
		printf("Menu:\n");
		printf("1.Part1\n2.Part2\n3.Part3\n0.Exit\n");
		printf("Please choice part:");
		scanf("%d",&num);
		printf("\n");
		switch(num){
			case 1:
				printf("Simple calculator program,format ex: +(space)num(space)");
				printf(" or **(space)num\n");
				printf("Press 'e' for return to the menu\n");
				do{
					scanf(" %[^\n]",arr);/*scanf takes number to array until user press to enter*/
					/*With sscanf,the array is divided into elements,and the status is number of elements*/
					status=sscanf(arr,"%c%c%d%d",&first_op,&second_op,&first_number,&second_number);
					/*If status is 3(for example + 5) */
					if(status==3){ 
						second_number=first_number;	
						first_number=result;
					}
					if(first_op=='+') {
						result=doit(add,first_number,second_number);		
					}
					if(first_op=='-') result=doit(sub,first_number,second_number);
					if(first_op=='*'){
						if(second_op=='*') result=doit(power,first_number,second_number);
							else result=doit(mul,first_number,second_number);
					}
					if(first_op=='/') result=doit(div,first_number,second_number);
					if(first_op=='%') result=doit(mod,first_number,second_number);
					if(first_op!='e')printf("%d\n", result);
				}while(first_op!='e'); /*If user press 'e',break from while loop*/
				printf("\n");
				break;
			case 2:
				printf("Please enter homework grades\n");
				avg_hw=calculate_homework(hw); /*Average hw grades are calculated*/
				printf("Please enter lab grades\n");
				avg_lab=calculate_lab(lab);/*Average lab grades are calculated*/
				printf("Please enter midterm and final grades\n");
				/*Average all grades are calculated*/
				printf("The weighted average all of grades: %.3f\n\n",calculate_all(avg_hw,mid_fin,avg_lab));
				break;
			case 3:
				printf("Press '-1' for return to the menu\n");
				do{
					printf("Please enter the height:");
					scanf("%d",&num);
					shape(num);				
				}while(num!=-1); /*If number is '-1',break from while loop*/
				printf("\n");
				break;
			case 0:
				break;
			default:
				printf("Please choice 0,1,2 or 3\n");/*Error message*/
				break;
		}
	}
}
void main()
{
	menu();
}