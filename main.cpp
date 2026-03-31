#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cctype>

#include "ArrayStack.h"

using namespace std;

// Token

struct Token {
    string value;   // number, operator, or parenthesis
};

// Tokenizer

vector<Token> tokenize(const string& line) {
    vector<Token> tokens;
    // TODO
    for (int i = 0; i < line.length(); i++) {
        if (!isspace(line[i])) {
            if (isdigit(line[i])) {
                string token;
                while (i < line.length() && isdigit(line[i])) {
                    token += line[i];
                    i++;
                }
                tokens.push_back({token});
                i--;
            }
            else if (line[i] == '+' || line[i] == '-' || line[i] == '*'
                || line[i] == '/' || line[i] == '(' || line[i] == ')') {
                string token;
                token += line[i];
                tokens.push_back({token});
            }
            else {
                string token;
                token += line[i];
                tokens.push_back({token});
            }
        }
    }
    return tokens;
}

// Helpers

bool isOperator(const string& s) {
    return s == "+" || s == "-" || s == "*" || s == "/";
}

int precedence(const string& op) {
    // TODO
    if (op == "+" || op == "-") {
        return 1;
    }
    if (op == "*" || op == "/") {
        return 2;
    }
    return 0;
}

// Detection

bool isValidPostfix(const vector<Token>& tokens) {
    // TODO
    if (tokens.empty()) {
        return false;
    }
    int stackSize = 0;

    for (int i = 0; i < tokens.size(); i++) {
        Token token = tokens[i];

        if (!token.value.empty() && isdigit(token.value[0])) {
            stackSize++;
        }
        else if (isOperator(token.value)) {
            if (stackSize < 2) {
                return false;
            }
            stackSize--;
        }
        else {
            return false;
        }
    }
    return stackSize == 1;
}

bool isValidInfix(const vector<Token>& tokens) {
    // TODO
    if (tokens.empty()) {
        return false;
    }

    int parenthesesBalance = 0;

    for (int i = 0; i < tokens.size(); i++) {
        Token token = tokens[i];

        if (!token.value.empty() && isdigit(token.value[0])) {
            if (i > 0) {
                string previous = tokens[i - 1].value;
                if ((!previous.empty() && isdigit(previous[0])) || previous == ")") {
                    return false;
                }
            }
        }
        else if (isOperator(token.value)) {
            if (i == 0 || i == tokens.size() - 1) {
                return false;
            }

            string previous = tokens[i - 1].value;
            string next = tokens[i + 1].value;

            if (!((!previous.empty() && isdigit(previous[0])) || previous == ")")) {
                return false;
            }
            if (!((!next.empty() && isdigit(next[0])) || next == "(")) {
                return false;
            }
        }
        else if (token.value == "(") {
            parenthesesBalance++;

            if (i > 0) {
                string previous = tokens[i - 1].value;
                if ((!previous.empty() && isdigit(previous[0])) || previous == ")") {
                    return false;
                }
            }
        }
        else if (token.value == ")") {
            parenthesesBalance--;

            if (parenthesesBalance < 0) {
                return false;
            }

            if (i == 0) {
                return false;
            }

            string previous = tokens[i - 1].value;
            if (!((!previous.empty() && isdigit(previous[0])) || previous == ")")) {
                return false;
            }
        }
        else {
            return false;
        }

    }

    string last = tokens[tokens.size() - 1].value;
    if (!((!last.empty() && isdigit(last[0])) || last == ")")) {
        return false;
    }
    return parenthesesBalance == 0;
}

// Conversion

vector<Token> infixToPostfix(const vector<Token>& tokens) {
    vector<Token> output;
    ArrayStack<Token> stack;
    // TODO
    for (int i = 0; i < tokens.size(); i++) {
        Token token = tokens[i];

        if (!token.value.empty() && isdigit(token.value[0])) {
            output.push_back(token);
        }
        else if (token.value == "(") {
            stack.push(token);
        }
        else if (token.value == ")") {
            while (!stack.empty() && stack.top().value != "(") {
                output.push_back(stack.top());
                stack.pop();
            }
            if (!stack.empty()) {
                stack.pop();
            }
        }
        else if (isOperator(token.value)) {
            while (!stack.empty() && isOperator(stack.top().value) && precedence(stack.top().value) >= precedence(token.value)) {
                output.push_back(stack.top());
                stack.pop();
            }

            stack.push(token);
        }
    }

    while (!stack.empty()) {
        output.push_back(stack.top());
        stack.pop();
    }
    return output;
}

// Evaluation

double evalPostfix(const vector<Token>& tokens) {
    ArrayStack<double> stack;
    // TODO
    for (int i = 0; i < tokens.size(); i++) {
        Token token = tokens[i];

        if (!token.value.empty() && isdigit(token.value[0])) {
            stack.push(stod(token.value));
        }
        else if (isOperator(token.value)) {
            double right = stack.top();
            stack.pop();

            double left = stack.top();
            stack.pop();

            if (token.value == "+") {
                stack.push(left + right);
            }
            else if (token.value == "-") {
                stack.push(left - right);
            }
            else if (token.value == "*") {
                stack.push(left * right);
            }
            else if (token.value == "/") {
                stack.push(left / right);
            }
        }
    }
    return stack.top();
}

// Main

int main() {
    string line;
    getline(cin, line);

    vector<Token> tokens = tokenize(line);

    if (isValidPostfix(tokens)) {
        cout << "FORMAT: POSTFIX\n";
        cout << "RESULT: " << evalPostfix(tokens) << "\n";
    }
    else if (isValidInfix(tokens)) {
        vector<Token> postfix = infixToPostfix(tokens);
        cout << "FORMAT: INFIX\n";
        cout << "POSTFIX: ";
        for (const auto& t : postfix) {
            cout << t.value << " ";
        }
        cout << "\n";
        cout << "RESULT: " << evalPostfix(postfix) << "\n";
    }
    else {
        cout << "FORMAT: NEITHER\n";
        cout << "ERROR: invalid expression\n";
    }

    return 0;
}
