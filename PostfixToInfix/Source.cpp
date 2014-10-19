#include "iostream"
#include <stack>
#include <string>

using namespace std;
void convertToInfix(string postfix, string &infix);

int main(int argc, char **argv) {

	string infix = "";
	convertToInfix("abc-+de-fg-h+/*", infix);
	cout<<infix;
	return 0;
}

void convertToInfix(string postfix, string &infix) {

	if(postfix.empty())
		return;

	infix.clear();

	stack<string> operand;
	int index = 0;

	while (index < postfix.size()) {

		if(isalnum(postfix[index]))
			operand.push(string(1,postfix[index]));

		else {
			if(operand.size() < 2) 
				return;

			else {
				string a = operand.top();
				operand.pop();
				string b = operand.top();
				operand.pop();

				string c = "(" + b + postfix[index] + a + ")";
				operand.push(c);
			}
		}

		index++;
	}

	if(operand.size() != 1)
		return;

	infix = operand.top();
}