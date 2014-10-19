#include "iostream"
#include <stack>
#include <string>

using namespace std;
void convertToPrefix(string postfix, string &prefix);

int main(int argc, char **argv) {

	string prefix = "";
	convertToPrefix("abc-+de-fg-h+/*", prefix);
	//*+a-bc/-de+-fgh
	cout<<prefix;
	return 0;
}

void convertToPrefix(string postfix, string &prefix) {

	if(postfix.empty())
		return;

	prefix.clear();

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

				string c = postfix[index] + b + a;
				operand.push(c);
			}
		}

		index++;
	}

	if(operand.size() != 1)
		return;

	prefix = operand.top();
}