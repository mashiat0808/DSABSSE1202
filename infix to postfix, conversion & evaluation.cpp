#include<bits/stdc++.h>
using namespace std;

char stackk[100];
int output[100],top = -1,h=-1;

//To push elements in stackk
void push(char x)
{
    stackk[++top] = x;
}

//To gradually get elements out from stackk and display them
char pop()
{
    return stackk[top--];
}

//To calculate the precedence of different operators
int priority(char x)
{
    if(x == '(' ) return 0;
    if(x== '+' || x== '-') return 1;
    if(x=='*' || x=='/') return 2;
}

//To convert a number to a string
string numToStr(int x)
{
    string str="";
    int temp;
    while(x!=0){
        temp=x%10;
        str += temp +'0';
        x/=10;

    }
    reverse(str.begin(),str.end());
    return str;
}

int operation(int a,char c,int b)
{

    int result=0;
    if(c=='+')
        return a+b;
    else if(c=='-')
        return a-b;
    else if(c=='*')
        return a*b;
    else if(c=='/')
        return a/b;
}

int evaluate(string str)
{
    int num=0,result=0,operand1,operand2;


    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]==' ')continue;

        else if(isalnum (str[i]) )
        {
            if(!isalnum  (str[i-1])  )
            num=0;
            num = num*10+ str[i] -'0';

            if(!isalnum (str[i+1]) )
            output[++h] = num;
        }

        else
        {
            operand2 = output[h--];
            operand1 = output[h--];
            result = operation (operand1, str[i], operand2);
            output[++h] = result;
        }
    }
return result;
}

int main()
{
    char inputExpression[100], *ptr;
    string  outputExpression="";
    int number=0;
    char ch;

    cout << "Enter the expression:";
    cin >> inputExpression;

    ptr = inputExpression;

    while(*ptr != '\0')

    {
        if(*ptr==' ')continue;
        else if(isalnum(*ptr))
        {

           if(!(isalnum (*(ptr -1))) )
                number=0;

           number = number*10+ *ptr -'0';

           if(!(isalnum (*(ptr +1))) )
            {
            cout <<number <<" ";
            outputExpression += numToStr(number);
            outputExpression += ' ';
            }
        }
        else if(*ptr == '(') push(*ptr);

        else if(*ptr == ')')
        {
            while (stackk[top] != '(' )
            {
                outputExpression += stackk[top];
                outputExpression += ' ';
                cout << pop() << " ";
            }
                pop();

        }

        else
        {
            while ( priority(stackk[top]) >= priority(*ptr) )
            {
                outputExpression += stackk[top];
                outputExpression += ' ';
                cout << pop() << " ";
            }
        push(*ptr);
        }
    ptr++;
    }

while(top!= -1)
    {
    outputExpression += stackk[top];
    outputExpression += ' ';
    cout << pop() <<" ";
    if(top>=0) cout <<" ";
    }
//        cout << outputExpression;

    cout <<"\n" << "Value: " << evaluate(outputExpression);


}
