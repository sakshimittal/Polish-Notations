#include "iostream"
#include <stack>
#include <string>
using namespace std;
float solvePostfix(string postfix);

int main(int argc, char **argv) {

	float result = solvePostfix("32+42/4*-");
	cout<<result;
	return 0;
}

float solvePostfix(string postfix) {

	if(postfix.empty()) {
		cout<<"Empty string"<<endl;
		return FLT_MIN;
	}

	stack<float> operand;
	int index = 0;
	
	while (index < postfix.size()) {
		
		if(isalnum(postfix[index]))
			operand.push(postfix[index] - '0');
		else {
			if(operand.size() < 2) {
				cout<<"Illegal string entered"<<endl;
				return FLT_MIN;
			}

			float a = operand.top();
			operand.pop();
			float b = operand.top();
			operand.pop();

			if(postfix[index] == '-')
				operand.push(b-a);
			else if(postfix[index] == '+')
				operand.push(b+a);
			else if(postfix[index] == '*')
				operand.push(b*a);
			else if(postfix[index] == '/')
				operand.push(b/a);
			else if(postfix[index] == '^')
				operand.push(powf(b,a));
		}

		index++;
	}

	if(operand.size() != 1) {
		cout<<"Illegal string entered"<<endl;
		return FLT_MIN;
	}

	return operand.top();
}