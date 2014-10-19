#include "iostream"
#include <stack>
#include <string>

using namespace std;
void convertToPostfix(string prefix, string &postfix);

int main(int argc, char **argv) {

	string postfix = "";
	convertToPostfix("*+a-bc/-de+-fgh", postfix);
	//abc-+de-fg-h+/*
	cout<<postfix;
	return 0;
}

void convertToPostfix(string prefix, string &postfix) {

	if(prefix.empty())
		return;

	postfix.clear();

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

				string c = a + b + prefix[index];
				operand.push(c);
			}
		}

		index--;
	}

	if(operand.size() != 1)
		return;

	postfix = operand.top();
}