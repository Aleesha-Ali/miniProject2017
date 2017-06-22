typedef struct stackForInFixToPostFix
{
	char symbol;
	struct stackForInFixToPostFix *next;
}st;

st *top = NULL;

void push(char c)
{
	st *p;
	p = (st*)malloc(sizeof(st));
	if(p == NULL)
	{
		printf("\n Memory can't be allocated\n");
	}
	else
	{
		p->symbol = c;
		p->next = top;
		top = p;
	}
}

char pop()
{
	st *t;
	t = top;
	char topElem = top->symbol;
	top = top->next;
	free(t);
	return(topElem);
}


//char postfix[30];
char *postfix;
int p=-1;

void post(char[], char, int *);
char* displayPostfixExression(char[]);

char* covertInfixToPostFix(char str[])
{
	int i,j;
	char x;
	postfix = (char *)malloc(sizeof(str));

	for(i=0; str[i]!='\0';) {
		i++;
	}
 	str[i]=')'; // - Append ')' to the end of original string
 	i++;
 	str[i]='\0';
 	push('('); // - Push '(' to the stack
 	i=0;

	while(str[i]!='\0')
	{
		if((str[i]>=97&&str[i]<=122)||(str[i]>=65&&str[i]<=90))
		{
			post(postfix, str[i], &p);
		}
		else if(str[i]=='(')
	       push(str[i]);
		else
		{
			switch(str[i])
			{
				case '+':
				{
					while(top->symbol=='+' || top->symbol=='-')
		 			{
						x=pop();
		  				post(postfix, x, &p);
		  			}
		  			push(str[i]);
	       		}break;

	    		case '-':
	     		{
					while(top->symbol=='+' || top->symbol=='-')
		   			{
						x=pop();
		    			post(postfix, x, &p);
		    		}
		    		push(str[i]);
	       		}break;

	    		case '/':
	     		{
					while(top->symbol=='+' || top->symbol=='-' || top->symbol=='/' || top->symbol=='*')
	       			{
						x=pop();
						post(postfix, x, &p);
					}
					push(str[i]);
	       		}break;

	    		case '*':
	     		{
					while(top->symbol=='+' || top->symbol=='-' || top->symbol=='/' || top->symbol=='*')
	      			{
						x=pop();
	       				post(postfix, x, &p);
	       			}
	       			push(str[i]);
	      		}break;

	    		case ')':
				{
					while(top!=NULL && top->symbol!='(')
		       		{
						x=pop();
						post(postfix, x, &p);
					}
					if(top!=NULL)
					{
						top = top->next;
					}
		       	}break;
			} // End of switch case
	    } // End of else
	    i++;
	} // End of while loop

	return displayPostfixExression(postfix);
}

void post(char postfix[], char n, int *p)
{
	postfix[++(*p)] = n;
}

char* displayPostfixExression(char postfix[])
{
	return postfix;
}
