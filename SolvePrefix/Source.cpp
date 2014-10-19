#include "iostream"
#include <stack>
#include <string>
using namespace std;
float solvePrefix(string prefix);

int main(int argc, char **argv) {

	float result = solvePrefix("-+32*/424");
	cout<<result;
	return 0;
}

float solvePrefix(string prefix) {

	if(prefix.empty()) {
		cout<<"Empty string"<<endl;
		return FLT_MIN;
	}

	stack<float> operand;
	int index = prefix.size() - 1;
	
	while (index >= 0) {
		
		if(isalnum(prefix[index]))
			operand.push(prefix[index] - '0');
		else {
			if(operand.size() < 2) {
				cout<<"Illegal string entered"<<endl;
				return FLT_MIN;
			}

			float b = operand.top();
			operand.pop();
			float a = operand.top();
			operand.pop();

			if(prefix[index] == '-')
				operand.push(b-a);
			else if(prefix[index] == '+')
				operand.push(b+a);
			else if(prefix[index] == '*')
				operand.push(b*a);
			else if(prefix[index] == '/')
				operand.push(b/a);
			else if(prefix[index] == '^')
				operand.push(powf(b,a));
		}

		index--;
	}

	if(operand.size() != 1) {
		cout<<"Illegal string entered"<<endl;
		return FLT_MIN;
	}

	return operand.top();
}