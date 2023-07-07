#include <iostream> 
#include <vector> 
#include <string> 
#include <sstream> 
#include <iomanip>
#include <algorithm> 
#include <ctype.h>

using namespace std; 
// Function to calculate the implication of two boolean values
bool implies(bool p, bool q)
{
    return !p || q; // Return the result of the implication operation
}

// Function to convert infix notation to postfix notation
string infix_to_postfix(const string& infix)
{
    vector<char> op_stack; // Create a stack to hold operators
    stringstream postfix; // Create a string stream to hold the postfix notation

    // Loop through each character in the infix notation
    for (const char ch : infix)
    {
        switch (ch)
        {
        case ' ': // Ignore whitespace characters
            break;
        case '(': // Push open parentheses onto the operator stack
            op_stack.push_back(ch);
            break;
        case ')': // When a close parentheses is encountered, pop operators off the stack and append them to the postfix string stream until an open parentheses is reached
            while (!op_stack.empty() && op_stack.back() != '(')
            {
                postfix << op_stack.back();
                op_stack.pop_back();
            }
            if (!op_stack.empty() && op_stack.back() == '(') // Pop the open parentheses off the stack
            {
                op_stack.pop_back();
            }
            break;
        case '&': // If an AND operator is encountered, pop operators off the stack and append them to the postfix string stream until a lower-precedence operator is reached or the stack is empty, then push the AND operator onto the stack
        case '|': // If an OR operator is encountered, pop operators off the stack and append them to the postfix string stream until a lower-precedence operator is reached or the stack is empty, then push the OR operator onto the stack
        case '>': // If an implication operator is encountered, pop operators off the stack and append them to the postfix string stream until a lower-precedence operator is reached or the stack is empty, then push the implication operator onto the stack
        case '=': // If a double implication operator is encountered, pop operators off the stack and append them to the postfix string stream until a lower-precedence operator is reached or the stack is empty, then push the double implication operator onto the stack
            while (!op_stack.empty() && op_stack.back() != '(' && op_stack.back() != '&' && op_stack.back() != '|' && op_stack.back() != '>')
            {
                postfix << op_stack.back();
                op_stack.pop_back();
            }
            op_stack.push_back(ch);
            break;
        case '!': // If a negation operator is encountered, push it onto the operator stack
        {
            op_stack.push_back(ch);
            break;
        }
        default: // If a variable or constant is encountered, append it to the postfix string stream
            postfix << ch;
            break;
        }
    }

    // Pop any remaining operators off the stack and append them to the postfix string stream
    while (!op_stack.empty())
    {
        postfix << op_stack.back();
        op_stack.pop_back();
    }

    return postfix.str(); // Return the postfix notation as a string
}

// Function to evaluate a postfix expression
bool evaluate_postfix(const string& postfix, const vector<pair<char, bool>>& variable_values)
{
    vector<bool> eval_stack; // Create a stack to hold boolean values

    // Loop through each character in the postfix expression
    for (const char ch : postfix)
    {
        switch (ch)
        {
        case '&': // If an AND operator is encountered, pop the top two values off the stack, perform the AND operation, and push the result back onto the stack
        {
            bool q = eval_stack.back();
            eval_stack.pop_back();
            bool p = eval_stack.back();
            eval_stack.pop_back();
            eval_stack.push_back(p && q);
            break;
        }
        case '|': // If an OR operator is encountered, pop the top two values off the stack, perform the OR operation, and push the result back onto the stack
        {
            bool q = eval_stack.back();
            eval_stack.pop_back();
            bool p = eval_stack.back();
            eval_stack.pop_back();
            eval_stack.push_back(p || q);
            break;
        }
        case '>': // If an implication operator is encountered, pop the top two values off the stack, perform the implication operation, and push the result back onto the stack
        {
            bool q = eval_stack.back();
            eval_stack.pop_back();
            bool p = eval_stack.back();
            eval_stack.pop_back();
            eval_stack.push_back(implies(p, q));
            break;
        }
        case '!': // If a negation operator is encountered, pop the top value off the stack, perform the negation operation, and push the result back onto the stack
        {
            bool p = eval_stack.back();
            eval_stack.pop_back();
            eval_stack.push_back(!p);
            break;
        }
        case '=': // If a double implication operator is encountered, pop the top two values off the stack, perform the double implication operation, and push the result back onto the stack
        {
            bool q = eval_stack.back();
            eval_stack.pop_back();
            bool p = eval_stack.back();
            eval_stack.pop_back();
            eval_stack.push_back((p && q) || (!p && !q));
            break;
        }
        default: // If a variable is encountered, look up its value in the variable_values vector and push the value onto the stack
            for (const auto& var : variable_values)
            {
                if (var.first == ch)
                {
                    eval_stack.push_back(var.second);
                    break;
                }
            }
            break;
        }
    }

    return eval_stack.back(); // Return the final value on the stack
}

// Function to generate all possible combinations of truth table variables
void generate_variable_combinations(vector<vector<pair<char, bool>>>& variable_combinations, const vector<char>& variables)
{
    int num_variables = variables.size();
    int num_combinations = pow(2, num_variables); // Calculate the number of combinations (2^n where n is the number of variables)

    // Loop through each possible combination of boolean values for the variables
    for (int i = 0; i < num_combinations; ++i)
    {
        vector<pair<char, bool>> variable_values; // Create a vector to hold the values of the variables for this combination
        for (int j = 0; j < num_variables; ++j)
        {
            bool value = (i & (1 << j)) != 0; // Calculate the value of the j-th variable for this combination (by checking the j-th bit of the binary representation of i)
            variable_values.push_back({ variables[j], value }); // Add the variable value to the vector
        }
        variable_combinations.push_back(variable_values); // Add the vector of variable values to the combinations vector
    }
}


// Function to extract unique variables from premises and conclusion
vector<char> extract_variables(const vector<string>& premises, const string& conclusion)
{
    vector<char> variables; // Create a vector to hold the unique variables
    // Loop through each premise and conclusion character, and add any unique variables to the variables vector
    for (const string& premise : premises)
    {
        for (char ch : premise)
        {
            if (isalpha(ch) && find(variables.begin(), variables.end(), ch) == variables.end())
            {
                variables.push_back(ch);
            }
        }
    }
    for (char ch : conclusion)
    {
        if (isalpha(ch) && find(variables.begin(), variables.end(), ch) == variables.end())
        {
            variables.push_back(ch);
        }
    }
    return variables; // Return the vector of unique variables
}

// Function to check if an argument is valid
void check_argument_validity(const vector<string>& premises, const string& conclusion)
{
    vector<char> variables = extract_variables(premises, conclusion); // Get the unique variables in the argument
    vector<vector<pair<char, bool>>> variable_combinations; // Create a vector to hold the variable combinations for the truth table
    generate_variable_combinations(variable_combinations, variables); // Generate all possible combinations of the variables for the truth table
    vector<string> postfix_premises; // Create a vector to hold the premises in postfix notation
    for (const auto& premise : premises) {
        postfix_premises.push_back(infix_to_postfix(premise)); // Convert each premise to postfix notation and add it to the vector
    }
    string postfix_conclusion = infix_to_postfix(conclusion); // Convert the conclusion to postfix notation

    bool argument_valid = true; // Assume the argument is valid unless proven otherwise
    for (const auto& variable_values : variable_combinations) // Loop through each variable combination for the truth table
    {
        bool all_premises_true = true; // Assume all premises are true unless proven otherwise
        for (const auto& postfix_premise : postfix_premises) // Loop through each premise in postfix notation
        {
            bool premise_value = evaluate_postfix(postfix_premise, variable_values); // Evaluate the premise for the current variable combination
            if (!premise_value) // If any premise is false for this variable combination, the assumption that all premises are true is false
            {
                all_premises_true = false;
                break;
            }
        }
        bool conclusion_value = evaluate_postfix(postfix_conclusion, variable_values); // Evaluate the conclusion for the current variable combination

        if (all_premises_true && !conclusion_value) // If all premises are true and the conclusion is false for this variable combination, the argument is not valid
        {
            argument_valid = false;
            break;
        }
    }

    if (argument_valid) // If the argument is valid, print a message saying so
    {
        cout << "The argument is valid." << endl;
    }
    else // Otherwise, print a message saying the argument is not valid
    {
        cout << "The argument is not valid." << endl;
    }
}

// Function to print the truth table for an argument
void print_truth_table(const vector<string>& premises, const string& conclusion)
{
    vector<char> variables = extract_variables(premises, conclusion);
    vector<vector<pair<char, bool>>> variable_combinations;
    generate_variable_combinations(variable_combinations, variables);

    // Print table header
    cout << "Truth Table" << endl;
    cout << string(70, '-') << endl;
    cout << setw(5) << " ";
    for (char var : variables)
    {
        cout << setw(5) << var;
    }
    for (int i = 0; i < premises.size(); ++i)
    {
        cout << setw(10) << "Premise " << i + 1;
    }
    if (!conclusion.empty())
    {
        cout << setw(15) << "Conclusion";
    }
    cout << endl;
    cout << string(70, '-') << endl;

    // Print separator row
    int num_columns = variables.size() + premises.size() + 1;
    for (int i = 0; i < num_columns; ++i) {
        cout << "--------";
    }
    cout << endl;

    // Print truth values
    for (const auto& variable_values : variable_combinations)
    {
        // Print variable values
        cout << setw(5) << " ";
        // Print variable values in reverse order
        for (auto it = variable_values.rbegin(); it != variable_values.rend(); ++it)
        {
            cout << setw(5) << (it->second ? "T" : "F");
        }

        // Print premise values
        for (const string& premise : premises)
        {
            string postfix_premise = infix_to_postfix(premise);
            bool premise_value = evaluate_postfix(postfix_premise, variable_values);
            cout << setw(10) << (premise_value ? "T" : "F");
        }

        // Print conclusion value
        if (!conclusion.empty())
        {
            string postfix_conclusion = infix_to_postfix(conclusion);
            bool conclusion_value = evaluate_postfix(postfix_conclusion, variable_values);
            cout << setw(15) << (conclusion_value ? "T" : "F");
        }

        cout << endl;
    }
}

// Function to provide instructions for entering arguments
void instruction()
{
    cout << "Instructions\n";
    cout << "1) Enter '&' for AND operation\n2) Enter '|' for OR operation\n3) Enter '!' for negation \n4) Enter '>' for implication\n5) Enter '=' for double implication\n";
    cout << "6) Enter the premises statement as a whole for input\n\n";
}

int main()
{
    instruction();
    int num_premises;
    string conclusion;
    cout << "Enter the number of premises: ";
    cin >> num_premises;
    cin.ignore();

    vector<string> premises(num_premises);

    for (int i = 0; i < num_premises; i++)
    {
        cout << "Enter premise " << i + 1 << ": ";
        getline(cin, premises[i]); // Get each premise as a whole line of input
    }

    cout << "Enter conclusion: ";
    getline(cin, conclusion); // Get the conclusion as a whole line of input

    cout << "\nResult : " << endl;
    print_truth_table(premises, conclusion); // Print the truth table for the argument
    check_argument_validity(premises, conclusion); // Check if the argument is valid

    return 0;
}
