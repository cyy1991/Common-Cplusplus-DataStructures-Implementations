#include <iostream>
#include <string>
using namespace std;

#include "stack.cpp"

int isValid ( string );
int isOpeningBracket ( char );

int isClosingBracket ( char );
string evaluateToPrefix ( string );

int isOperand ( char );
int isOperator ( char );

int precedence ( char );

void main ( )
{
	string s ( "A * B / C" );

	try
	{
		if ( isValid ( s ) )
			cout << "Valid" << endl;
		else 
			cout << "Invalid" << endl;

		cout << evaluateToPostfix ( s ) << endl;
	}

	catch ( exception & e )
	{
		cout << "Execption occurred : " << e.what ( ) << endl;
	}
}

int isValid ( string str )
{
	int i = 0;
	Stack<int> s;

	while ( str[i] != '\0' )
	{
		if ( isOpeningBracket ( str[i] ) )
				s.push ( str[i] );
		else if ( isClosingBracket ( str[i] ) )
		{
			if ( s.isEmpty ( ) )
				return 0;
			else if ( s.stackTop ( ) == '(' )
				s.pop ( );
			else
				return 0;
		}

		i++;
	}

	if ( s.isEmpty ( ) )
		return 1;

	return 0;
}

string evaluateToPrefix ( string str )
{
	Stack<char> stack;
	string result;

	int i = str.length ( );

	while ( i >= 0 )
	{
		if ( isOperand ( str[i] ) )
		{
			string temp= str[i] + result;
			result = temp;

		}
		else if ( isOpeningBracket ( str[i] ) )
			stack.push ( str[i] );
		else if ( isOperator ( str[i] ) )
		{
			while ( !stack.isEmpty ( ) && precedence ( stack.stackTop ( ) ) >= 
				precedence ( str[i] ) )
			{
				char character = stack.pop ( );

				if ( !isOpeningBracket ( character ) )
				{
					string s = character + result;
					
					result = s;
				}
			}

			if ( !isClosingBracket ( str[i] ) )
			{
				stack.push ( str[i] );
			}
		}
		
		
		i--;
	}

	while ( !stack.isEmpty ( ) )
	{
		string s= stack.pop ( ) + result;
		result = s;
	}

	return result;
}

int precedence ( char ch )
{
	if ( ch == '(' || ch == ')' )
		return 0;
	else if ( ch == '=' )
		return 1;
	else if ( ch == '+' || ch == '-' )
		return 2;
	else if ( ch == '/' || ch == '%' || ch == '*' )
		return 3;

	return -1;
}

int isOperand ( char ch )
{
	return ( ch >= 'A' && ch <= 'z' );
}

int isOperator ( char ch )
{
	return ( ch >= '!' && ch <= '/' );
}

int isOpeningBracket ( char ch )
{
	if ( ch == '(' )
		return 1;

	return 0;
}

int isClosingBracket ( char ch )
{
	if ( ch == ')' )
		return 1;

	return 0;
}