#include "iostream"
#include <stack>
#include <string>

using namespace std;
void convertToInfix(string prefix, string &infix);

int main(int argc, char **argv) {

	string infix = "";
	convertToInfix("*+a-bc/-de+-fgh", infix);
	cout<<infix;
	return 0;
}

void convertToInfix(string prefix, string &infix) {

	if(prefix.empty())
		return;

	infix.clear();

	stack<string> operand;
	int index = prefix.size() - 1;

	while (index >= 0) {

		if(isalnum(prefix[index]))
			operand.push(string(1,prefix[index]));

		else {
			if(operand.size() < 2) 
				return;

			else {
				string a = operand.top();
				operand.pop();
				string b = operand.top();
				operand.pop();

				string c = "(" + a + prefix[index] + b + ")";
				operand.push(c);
			}
		}

		index--;
	}

	if(operand.size() != 1)
		return;

	infix = operand.top();
}