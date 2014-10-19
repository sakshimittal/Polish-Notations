#include "iostream"
#include <stack>
#include <string>

using namespace std;

void convertToPostfix(string infix, string &postfix);
bool precedence(char operatorOnStackTop, char operatorInInfix);

int main(int argc, char **argv) {

	string postfix = ""; 
	convertToPostfix("a^b/(c+e*f)-g",postfix);
	cout<<postfix;
	return 0;
}

void convertToPostfix(string infix, string &postfix) {
	
	if(infix.empty())
		return;

	postfix.clear();

	stack<char> operatorStack;

	int index = 0;
	int flag = 0;

	while(index < infix.size()) {
		
		flag = 0;

		if(infix[index] == ' ')
			;
		
		else if(isalnum(infix[index]))
			postfix.push_back(infix[index]);

		else if(infix[index] == '(') {
			operatorStack.push(infix[index]);
			flag = 1;
		}

		else if(infix[index] == ')') {

			while (operatorStack.top() != '(') {
				char c = operatorStack.top();
				operatorStack.pop();
				postfix.push_back(c);
			}

			operatorStack.pop();
		}

		else {
		
			while (!operatorStack.empty() && precedence(operatorStack.top(),infix[index])) {
				char c = operatorStack.top();
				operatorStack.pop();
				postfix.push_back(c);
			}

			operatorStack.push(infix[index]);
			flag = 1;
		}

		if(flag == 1 && !postfix.empty() && postfix.back() != ' ')
			postfix.push_back(' ');

		index++;
	}

	while (!operatorStack.empty()) {
		char c = operatorStack.top();
		operatorStack.pop();
		postfix.push_back(c);
	}
}

bool precedence(char operatorOnStackTop, char operatorInInfix) {

	if(operatorOnStackTop == '(')
		return false;
	if(operatorOnStackTop == '^')
		return true;
	if(operatorInInfix == '^')
		return false;
	if(operatorOnStackTop == '*' || operatorOnStackTop == '/')
		return true;
	if(operatorInInfix == '*' || operatorInInfix == '/')
		return false;

	return true;
}