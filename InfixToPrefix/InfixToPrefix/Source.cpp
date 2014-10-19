#include "iostream"
#include <stack>
#include <string>

using namespace std;

void convertToPrefix(string infix, string &prefix);
bool precedence(char operatorOnStackTop, char operatorInInfix);
void reverse(string &input);

int main(int argc, char **argv) {

	string prefix = ""; 
	convertToPrefix("(A+B^C)*D+E^5",prefix);
	cout<<prefix;
	return 0;
}

void convertToPrefix(string infix, string &prefix) {
	
	if(infix.empty())
		return;

	prefix.clear();

	stack<char> operatorStack;

	int index = infix.size() - 1;
	int flag = 0;

	while(index >= 0) {
		
		flag = 0;

		if(infix[index] == ' ')
			;
		
		else if(isalnum(infix[index]))
			prefix.push_back(infix[index]);

		else if(infix[index] == ')') {
			operatorStack.push(infix[index]);
			flag = 1;
		}

		else if(infix[index] == '(') {

			while (operatorStack.top() != ')') {
				char c = operatorStack.top();
				operatorStack.pop();
				prefix.push_back(c);
			}

			operatorStack.pop();
		}

		else {
		
			while (!operatorStack.empty() && precedence(operatorStack.top(),infix[index])) {
				char c = operatorStack.top();
				operatorStack.pop();
				prefix.push_back(c);
			}

			operatorStack.push(infix[index]);
			flag = 1;
		}

		if(flag == 1 && !prefix.empty() && prefix.back() != ' ')
			prefix.push_back(' ');

		index--;
	}

	while (!operatorStack.empty()) {
		char c = operatorStack.top();
		operatorStack.pop();
		prefix.push_back(c);
	}

	reverse(prefix);
}

bool precedence(char operatorOnStackTop, char operatorInInfix) {

	if(operatorOnStackTop == ')')
		return false;
	if(operatorOnStackTop == '^')
		return true;
	if(operatorInInfix == '^')
		return false;
	if((operatorOnStackTop == '*' || operatorOnStackTop == '/') && (operatorInInfix == '*' || operatorInInfix == '/'))
		return false;
	if((operatorOnStackTop == '*' || operatorOnStackTop == '/'))
		return true;
	if((operatorOnStackTop == '+' || operatorOnStackTop == '-') && (operatorInInfix == '+' || operatorInInfix == '-'))
		return false;

	return false;
}

void reverse(string &input) {

	if(input.empty())
		return;

	int len = input.length();

	char *end = &input[len-1];
	char *start = &input[0];
	char temp;

	while(start < end) {
		temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}