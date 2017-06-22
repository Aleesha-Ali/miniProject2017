typedef struct stack
{
	float num;
	struct stack *next;
}sl;

sl *tp = NULL;
int i;
float n,x,y,ans;

void pushToStack(float n)
{
	sl *p;
	p = (sl*)malloc(sizeof(sl));
	if(p == NULL)
	{
		printf("\n Memory can't be allocated\n");
	}
	else
	{
		p->num = n;
		p->next = tp;
		tp = p;
	}
}

float popFromStack()
{
	sl *t;
	t = tp;
	float topElem = tp->num;
	tp = tp->next;
	free(t);
	return(topElem);
}

void add()
{
	x=popFromStack();
	y=popFromStack();
	ans=y+x;
	pushToStack(ans);
}

void substract()
{
	x=popFromStack();
	y=popFromStack();
	ans=y-x;
	pushToStack(ans);
}

void multiply()
{
	x=popFromStack();
	y=popFromStack();
	ans=y*x;
	pushToStack(ans);
}

void divide()
{
	x=popFromStack();
	y=popFromStack();
	ans=y/x;
	pushToStack(ans);
}

void showResult();

void evalatePostfixExpression(char str[])
{
	int i,x,y,ans;
	float n;
	
	if(str[0]=='+'||str[0]=='-'||str[0]=='*'||str[0]=='/'||str[0]=='%'||str[0]=='$')
		printf("\nThe expression is in Prefix form,please enter in Postfix form\n");
	else if(str[1]=='+'||str[1]=='-'||str[1]=='*'||str[1]=='/'||str[1]=='%'||str[1]=='$')
    	printf("\nThe expression is in Infix form,please enter in Postfix form\n");
	else
	{
		i=0;
		do
	 	{
			if((str[i]>=65&&str[i]<=90)||(str[i]>=97&&str[i]<=122))
	   		{
				printf("\nEnter the value for %c:-\n",str[i]);
	      		scanf("%f",&n);
	      		pushToStack(n);
	    	}
	    	else if(str[i]>=49&&str[i]<=57)
	    	{
	    		pushToStack(str[i]);
			}
	  		else
			{
				switch(str[i])
				{
					case '$':
					{
						x=popFromStack();
						y=popFromStack();
						ans=pow(y,x);
						pushToStack(ans);
					}break;
		    		case '%':
					{
						x=popFromStack();
						y=popFromStack();
						ans=y%x;
						pushToStack(ans);
					}break;
		       		case '*':
					{
						multiply();
					}break;
		       		case '/':
					{
						divide();
					}break;
		       		case '+':
					{
						add();
					}break;
		       		case '-':
					{
						substract();
					}break;
		      	}
		    }
	  		i++;
		}while(str[i]!='\0');

		showResult();
	}   	
}



void showResult()
{
	printf("\n\n ------------- The answer = %.2f --------------- \n", tp->num);
}
