/**
 * @file truth_table_gen.cpp
 * @author The Viking
 * @brief Generates truth tables for a given boolean expression
 * @version 0.1
 * @date 2022-09-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <iostream>

using namespace std;


// Function Prototypes
bool isAlphabet(char);
string getVariables(string);
string parseInput(string);
string toPostfix(string);
int evaluate(string, bool *);


int main() {
    
    string input, exp, vars, postfix, hor_rule;
    bool value[60]; // To store value of all variables
    char y = 'F';   // Output function
    int n;

    cout << "Truth Table Generator\n\n"
         << "Use ' for NOT\n"
         << "Use + for OR\n"
         << "Use . for AND (optional)\n"
         << "Use () for grouping\n"
         << "Example: (A' + B)C'+(D' + E)\n\n"
         << "Enter any boolean expression (case-insensitive):\n"
         << y << " = ";
    
    getline(cin, input);
    exp = parseInput(input);
    vars = getVariables(exp);
    postfix = toPostfix(exp);
    n = vars.length();

    // Printing the table in ASCII format
    hor_rule = "+-";
    for (int i = 0; i < n; i++) hor_rule += "--";
    hor_rule += "+---+\n";

    // Printing the headers
    cout << "\n" << hor_rule << "| ";
    for (int j = 0; j < n; j++) cout << vars[j] << " ";
    cout << "| " << y << " |\n" << hor_rule;
    
    // Bruteforcing all the possible values of variables
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            bool val = i & (1 << j);
            char variable = vars[n - 1 - j];
            value[variable - 'A'] = val;
            value[toupper(variable) - 'A'] = !val;
        }
        // Printing a row
        cout << "| ";
        for (int j = 0; j < n; j++)
            cout << value[vars[j] - 'A'] << " ";
        cout << "| " << evaluate(postfix, value) << " |\n";
    }

    cout << hor_rule;
    
    return 0;
}


bool isAlphabet(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

string getVariables(string input) {
    bool freq[26];
    for (int i = 0; i < 26; i++) freq[i] = false;

    for (int i = 0; i < input.length(); i++) {
        if (isAlphabet(input[i]))
            freq[tolower(input[i]) - 'a'] = true;
    }
    string variables = "";
    for (int i = 0; i < 26; i++) {
        if (freq[i]) variables += (char)('a' + i);
    }
    return variables;
}

string parseInput(string input) {
    string parsed = "";
    // Removing all the spaces and converting a' to A, b' to B, etc
    for (int i = input.length() - 1; i >= 0; i--) {
        char c = tolower(input[i]);
        if (c == ' ')
            continue;

        else if (c == '\'')
            parsed.push_back(toupper(input[i-- - 1]));

        else if(isAlphabet(c) || c == '(' || c == ')' || c == '+')
            parsed.push_back(c);
    }
    // Reversing the string
    int i = 0, j = parsed.length() - 1;
    while (i < j) swap(parsed[i++], parsed[j--]);
    
    // Now inserting dot (.) between two variables
    string parsed2 = parsed.substr(0, 1);
    for (int i = 1; i < parsed.length(); i++) {
        if (isAlphabet(parsed[i - 1]) && isAlphabet(parsed[i])
            || isAlphabet(parsed[i - 1]) && parsed[i] == '('
            || parsed[i - 1] == ')' && isAlphabet(parsed[i])
            || parsed[i - 1] == ')' && parsed[i] == '(') {
            
                parsed2.push_back('.');
        }
        parsed2.push_back(parsed[i]);
    }
    
    return parsed2;
}

string toPostfix(string exp) {
    string postfix = "", stack = "";
    int n = exp.length();

    for (int i = 0; i < n; i++) {
        char c = exp[i];
        if (isAlphabet(c)) {
            postfix.push_back(c);
        } else if (c == '(') {
            stack.push_back(c);
        } else if (c == ')') {
            while (stack.back() != '(') {
                postfix.push_back(stack.back());
                stack.pop_back();
            }
            stack.pop_back();
        } else if (c == '.') {
            while (stack.length() > 0 && stack.back() == '.') {
                postfix.push_back(stack.back());
                stack.pop_back();
            }
            stack.push_back(c);
        } else if (c == '+') {
            while (stack.length() > 0 && (stack.back() == '.' || stack.back() == '+')) {
                postfix.push_back(stack.back());
                stack.pop_back();
            }
            stack.push_back(c);
        }
    }

    while (stack.length() > 0) {
        postfix.push_back(stack.back());
        stack.pop_back();
    }

    return postfix;    
}

int evaluate(string postfix, bool* value) {
    string stack = "";
    int n = postfix.length();

    for (int i = 0; i < n; i++) {
        char c = postfix[i];
        int val = value[c - 'A'];
        if (isAlphabet(c)) {
            stack.push_back(val);
        } else if (c == '.') {
            int a = stack.back();
            stack.pop_back();
            int b = stack.back();
            stack.pop_back();
            stack.push_back(a && b);
        } else if (c == '+') {
            int a = stack.back();
            stack.pop_back();
            int b = stack.back();
            stack.pop_back();
            stack.push_back(a || b);
        }
    }

    return stack.back();
}
