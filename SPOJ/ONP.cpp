#include<bits/stdc++.h>

using namespace std;

int precedenceValue(char op)
{
    switch(op)
    {
        case '^' : return 11;
        case '/' : return 9;
        case '*' : return 9;
        case '+' : return 8;
        case '-' : return 8;

        default  : return 0; //case of operand
    }
}
int main()
{
    int t;

    stack<char> operatorStack;

    scanf("%d",&t);

    char tmp;
    char exp[500];
    while(t--)
    {
        scanf("%s",exp);
        strcat(exp,")");

        //printf("%s\n",exp);

        operatorStack.push('(');

        for(int i=0;exp[i]!=0;++i)
        {
            char a=exp[i];

            if(a=='(')
                operatorStack.push(a);
            else if(a==')')
                {
                    while(operatorStack.top()!='(')
                    {
                        printf("%c",operatorStack.top());
                        operatorStack.pop();
                    }
                    operatorStack.pop();
                }
            else if(precedenceValue(a)==0) //operand
                {
                    printf("%c",a);
                }

            else
                {
                    while(precedenceValue(operatorStack.top()) >= precedenceValue(a))
                    {
                        printf("%c", operatorStack.top());
                        operatorStack.pop();
                    }
                    operatorStack.push(a);
                }
        }
        printf("\n");
    }
}
