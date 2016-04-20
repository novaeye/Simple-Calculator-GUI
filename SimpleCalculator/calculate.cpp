#include "stdafx.h"
#include <iostream>
#include <stack>
#include <string>
#include <regex>
#include "calculate.h"

using namespace std;

bool Calculator::isOperator(char character)
{
	if (character == '+' || character == '-' || character == '*' || character == '/')
	{
		return true;
	}
	return false;
}

bool Calculator::isOperand(char character)
{
	if (!isOperator(character) && character != '(' && character != ')')
	{
		return true;
	}
	return false;
}

// Compare operator precedence of main operators.
// Return 0 if equal, -1 if op2 is less than op1, and 1 if op2 is greater than op1.
int Calculator::compareOperators(char op1, char op2)
{
	if ((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-')) { return -1; }
	else if ((op1 == '+' || op1 == '-') && (op2 == '*' || op2 == '/')) { return 1; }
	return 0;
}

double Calculator::performOperation(double op1, double op2, char op)
{
	double ans;
	switch (op)
	{
	case '+':
		ans = op2 + op1;
		break;
	case '-':
		ans = op2 - op1;
		break;
	case '*':
		ans = op2 * op1;
		break;
	case '/':
		ans = op2 / op1;
		break;
	}
	return ans;
}

double Calculator::toPostfix(CString exp, int &iState)
{
	stack<char> opStack;
	string postFixString = "";
	char input[100];
	USES_CONVERSION;
	strcpy_s(input, T2A(exp));

	if (strlen(input) > 100)
	{
		//printf("Error: Too lengthy expression!!!");
		iState = 2;
		return 0;
	}

	regex num("(((-?[[:digit:]]+)?)(\\.(([[:digit:]]+)?))?)");
	regex valid("\\(?((\\(?-?([[:digit:]]+)?(\\.([[:digit:]]+)?)?\\)?)(\\+|-|/|\\*)(\\(?-?([[:digit:]]+)?(\\.([[:digit:]]+)?)?\\)?)(\\+|-|/|\\*)*)+\\)?");

	if (regex_match(input, valid))
	{
		char *cPtr = input;
		while (*cPtr != '\0')
		{
			// If operand, simply add it to our postfix string.
			// If it is an operator, pop operators off the stack until it is empty, an open parenthesis or an operator with less than or equal precedence.
			if (isOperand(*cPtr)) { postFixString += *cPtr; }

			else if (isOperator(*cPtr))
			{
				if (isOperator(*(++cPtr)))
				{
					//printf("Error: Invalid sequence of operators");
					iState = 0;
					return 0;
				}
				else if (*(--cPtr) == '-')
				{
					if (--cPtr <input)
					{
						iState = 0;
						return 0;
					}
					else if (*(cPtr) == '(')
					{
						cPtr++;
						postFixString += *cPtr;
						cPtr++;
						postFixString += *cPtr;
					}
					else
					{
						postFixString += " ";
						cPtr++;
						opStack.push(*cPtr);
					}
				}
				else
				{
					postFixString += " ";
					while (!opStack.empty() && opStack.top() != '(' && compareOperators(opStack.top(), *cPtr) <= 0)
					{
						postFixString += " ";
						postFixString += opStack.top();
						opStack.pop();
					}
					opStack.push(*cPtr);
				}
			}
			// Push all open parenthesis into the stack
			// When we reach a closing one, start popping off operators until we run into the opening parenthesis.
			else if (*cPtr == '(') { opStack.push(*cPtr); }
			else if (*cPtr == ')')
			{
				while (!opStack.empty())
				{
					if (opStack.top() == '(')
					{
						opStack.pop();
						if (opStack.empty())
							break;
						if (*(++cPtr) != '\0')
						{
							if (*cPtr == '*')
							{
								opStack.push(*cPtr);
								postFixString += " ";
								break;
							}
							else if (*cPtr == '/')
							{
								opStack.push(*cPtr);
								postFixString += " ";
								break;
							}
							else if (*cPtr == '+' || *cPtr == '-')
							{
								opStack.push(*cPtr);
								++cPtr;
								postFixString += " ";
								postFixString += *cPtr;

							}
						}//if
					}//if
					postFixString += " ";
					postFixString += opStack.top();
					opStack.pop();
				}//while
			}

			// Advance the pointer to next character in string.
			cPtr++;
		}

		// After the input expression has been ran through, if there is any remaining operators left on the stack
		// pop them off and put them onto the postfix string.
		while (!opStack.empty())
		{
			postFixString += " ";
			postFixString += opStack.top();
			opStack.pop();
		}

		// display the postfix string
		//cout << "Postfix is: " << postFixString << endl;

		char buffer[50];
		int i, len, j;
		double op1, op2, x;
		stack<double> s;
		len = postFixString.length();
		j = 0;

		for (i = 0; i<len; i++)
		{
			if ((postFixString[i] >= '0' && postFixString[i] <= '9') || postFixString[i] == '.' || (postFixString[i] == '-' && (postFixString[i + 1] >= '0' && postFixString[i + 1] <= '9')))
			{
				buffer[j++] = postFixString[i];
			}
			else if (postFixString[i] == ' ')
			{
				if (j>0){
					buffer[j] = '\0';
					if (strlen(buffer) > 16)
					{
						//printf("Error: You have entered a too lengthy number");
						iState = 3;
						return 0;
					}
					x = stod(buffer);
					s.push(x);
					j = 0;
				}
			}
			else if (isOperator(postFixString[i]))
			{
				if (s.size() <= 1)
				{
					//printf("Error:Invalid input");
					iState = 0;
					return 0;
				}
				op1 = s.top();
				s.pop();
				op2 = s.top();
				s.pop();
				if (postFixString[i] == '/' && op1 == 0)
				{
					//printf("Error: Cannot divide by zero");
					iState = -1;
					return 0;
				}
				else
					s.push(performOperation(op1, op2, postFixString[i]));
			}
		}
		//cout << s.top() << endl;
		iState = 1;
		return s.top();
	}
	else if (regex_match(input, num))
	{
		//cout << input << endl;
		if (strlen(input) > 16)
		{
			iState = 3;
			return 0;
		}
		else
		{
			iState = 1;
			double number = stod(input);
			return number;
		}
	}
	else
	{
		//cout <<"Error: Invalid input" << endl;
		iState = 0;
		return 0;
	}
}
