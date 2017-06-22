				/* ---------------------------------------------------------------------- */
				/* PROGRAM TO CONVERT INFIX TO POSTFIX & EVALUATION OF POSTFIX EXPRESSION */
				/* ---------------------------------------------------------------------- */
																														//Presented by-
																														//Aleesha Ali
																														//Sec-A_rollNo-32
																														//University rollNo-2010292

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

#include "infixToPostFix.h"
#include "evaluatePostfix.h"

char *postfixExp;
int checkPrefix(char);
int checkInput(char, char* []);

int main ( int argc, char *argv[] ){
	int i;
	char *str;  // Array of character values to store the passed infix expression
	//system ("cls");
	printf("\n   ---------------------------------------------------------------------- ");
	printf("\n   PROGRAM TO CONVERT INFIX TO POSTFIX & EVALUATION OF POSTFIX EXPRESSION\n");
	printf("\n   ---------------------------------------------------------------------- ");

	if ( argc <= 2 )
	{
		printf("\n\n WRONG INPUT.\n\n --------- There is something wrong with your input -------\n\n");
		getch();
		return 0;
	}

	str = (char *)malloc(sizeof(char)*argc); //Allocating memory to character array str

	for( i = 1; i < argc; i++ ) {
        str[i-1] = *argv[i];
    } // Assigning values to character array str
    str[i-1]='\0'; //Terminating the string with null character

	if ( (checkPrefix(*(argv[1])) == 0) || (checkInput(argc, argv) == 0))
    {
    	return 0; // Exit the program if the input is not in the desired format or it is in Prefix format
	}

    printf("\n\n The given infix expression is:--\n");
    printf("     %s \n\n\n", str);
	fflush(stdin);

 	postfixExp = (char *)malloc(sizeof(char)*argc);
 	strcpy(postfixExp, covertInfixToPostFix(str));
 	printf("\n\n  Corrosponding postfix expression is:-- \n");
 	printf("     %s \n\n", postfixExp);

 	evalatePostfixExpression(postfixExp);

 	getch();
	return 0;
} // End of main function

//Function to determine if the given input is in PreFix form
int checkPrefix(char str)
{
	if(str=='+'||str=='-'||str=='*'||str=='/'||str=='%'||str=='$')
	{
		printf("\nThe expression is in Prefix form,please enter in Infix form\n");
		return 0;
	}
	return 1;
}

int checkInput(char totElements, char *argv[])
{
	int i, flag = 1;
	int countL = 0, countR = 0;
	int countOperands = 0, countOperators = 0;

	// we are starting from i = 1 because argument at i = 0 is the program name itself in case of command line arguments.
	for(i = 1; i < totElements; i++)
	{
		if( (*(argv[i]) >=65 && *(argv[i]) <= 90) || (*(argv[i]) >= 97 && *(argv[i]) <= 122) || (*(argv[i]) == 43) || (*(argv[i]) == 45) || (*(argv[i]) == 42) || (*(argv[i]) == 47) || (*(argv[i]) == 40) || (*(argv[i]) == 41) )
		{
			flag = 1;
		}
		else
		{
			printf("\n\n WRONG INPUT.\n --------- The operand should be between [a-z] or [A-Z] and operator can be either '+', '-', '*', or '/' -------\n\n");
			flag = 0;
			break;
		}

		// Condition to check if 2 operators are given consecutively in the input
		if ( (i != (totElements - 1)) && ((*(argv[i]) == 43) || (*(argv[i]) == 45) || (*(argv[i]) == 42) || (*(argv[i]) == 47)) && ((*(argv[i+1]) == 43) || (*(argv[i+1]) == 45) || (*(argv[i+1]) == 42) || (*(argv[i+1]) == 47)) )
		{
			printf("\n\n WRONG INPUT.\n --------- The given expression is not in INFIX form -------\n\n");
			flag = 0;
			break;
		}

		// Condition to check if 2 operands are given consecutively in the input
		if ( (i != (totElements - 1)) && (((*(argv[i]) >=65 && *(argv[i]) <= 90) || (*(argv[i]) >= 97 && *(argv[i]) <= 122)))  && (((*(argv[i+1]) >=65 && *(argv[i+1]) <= 90) || (*(argv[i+1]) >= 97 && *(argv[i+1]) <= 122))) )
		{
			printf("\n\n WRONG INPUT.\n --------- The given expression is not in INFIX form -------\n\n");
			flag = 0;
			break;
		}

		// Condition to check if 2 brackets ( & ) are coming consecutively in the input
		if ( (i != (totElements - 1)) && ( (((*(argv[i]) == 40)) && ((*(argv[i+1]) == 41))) || (((*(argv[i]) == 41)) && ((*(argv[i+1]) == 40))) ) )
		{
			printf("\n\n WRONG INPUT.\n --------- The given expression is not in INFIX form -------\n\n");
			flag = 0;
			break;
		}

		if ( *(argv[i]) == 40 )
		{
			countL++;
		}

		if ( *(argv[i]) == 41 )
		{
			countR++;
		}

		if ( (*(argv[i]) == 43) || (*(argv[i]) == 45) || (*(argv[i]) == 42) || (*(argv[i]) == 47) )
		{
			countOperators++;
		}

		if ( (*(argv[i]) >=65 && *(argv[i]) <= 90) || (*(argv[i]) >= 97 && *(argv[i]) <= 122) )
		{
			countOperands++;
		}
	} // End of for loop

	if ( countL != countR  )
	{
		printf("\n\n WRONG INPUT.\n --------- The opening & closing brackets are not given correctly -------\n\n");
		flag = 0;
	}

	if ( countOperands != countOperators + 1  )
	{
		printf("\n\n WRONG INPUT.\n --------- There is something wrong with your input -------\n\n");
		flag = 0;
	}

	if( flag == 0 )
	{
		return 0;
	}
	return 1;
}
