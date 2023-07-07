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
// Function to extract unique variables from premises and premises 2
vector<char> extract_variables(const string& premise1, const string& premise2)
{
    vector<char> variables; // Create a vector to hold the unique variables
    // Loop through each premise and premise2 character, and add any unique variables to the variables vector
    
    for (char ch : premise1)
    {
        if (isalpha(ch) && find(variables.begin(), variables.end(), ch) == variables.end())
        {
            variables.push_back(ch);
        }
    }
    
    for (char ch : premise2)
    {
        if (isalpha(ch) && find(variables.begin(), variables.end(), ch) == variables.end())
        {
            variables.push_back(ch);
        }
    }
    return variables; // Return the vector of unique variables
}

// Function to check if two premises are logically equivalent
bool check_equivalence(const string& premise1, const string& premise2)
{
    // Get postfix notation for both premises
    string postfix_premise1 = infix_to_postfix(premise1); // Convert premise1 to postfix notation
    string postfix_premise2 = infix_to_postfix(premise2); // Convert premise2 to postfix notation

    // Get all possible variable combinations
    vector<char> variables = extract_variables( premise1, premise2); // Extract all variables from both premises
    vector<vector<pair<char, bool>>> variable_combinations; // Create a vector to store all possible variable combinations
    generate_variable_combinations(variable_combinations, variables); // Generate all possible variable combinations

    // Check if the two premises are equivalent for all variable combinations
    for (const auto& variable_values : variable_combinations)
    {
        bool value1 = evaluate_postfix(postfix_premise1, variable_values); // Evaluate premise1 for the current variable combination
        bool value2 = evaluate_postfix(postfix_premise2, variable_values); // Evaluate premise2 for the current variable combination

        if (value1 != value2)
        {
            return false; // The two premises are not equivalent, return false
        }
    }

    return true; // The two premises are equivalent for all variable combinations, return true
}

// Function to print truth table for two premises
void print_truth_table(const string& premise1, const string& premise2)
{
    // Extract variables from premises
    vector<char> variables = extract_variables( premise1, premise2);

    // Generate all possible variable combinations
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
    for (int i = 0; i < 2; ++i)
    {
        cout << setw(10) << "Premise " << i + 1;
    }
  
    cout << endl;
    cout << string(70, '-') << endl;

    // Print truth values
    for (const auto& variable_values : variable_combinations)
    {
        cout << setw(5) << " ";
        // Print variable values
        for (int i = variable_values.size() - 1; i >= 0; --i) // Print variable values in reverse order (to match the order in which they are evaluated)
        {
            cout << setw(5) << (variable_values[i].second ? "T" : "F");
        }


        // Print premise values
        bool value1 = evaluate_postfix(infix_to_postfix(premise1), variable_values);
        bool value2 = evaluate_postfix(infix_to_postfix(premise2), variable_values);
        cout << setw(10) << (value1 ? "T" : "F");
        cout << setw(10) << (value2 ? "T" : "F");
        cout << endl;
    }
    cout << string(70, '-') << endl;
}



// Function to provide instructions to enter arguments
void instruction()
{
    cout << "Instructions\n";
    cout << "1) Enter '&' for AND operation\n2) Enter '|' for OR operation\n3) Enter '!' for negation \n4) Enter '>' for implication\n5) Enter '=' for double implication\n";
    cout << "6) Enter the premises statement as a whole for input\n\n";
}
int main()
{
    instruction();
    string premise1, premise2;
    cout << "Enter first premise: ";
    getline(cin, premise1); // Read in first premise
    cout << "Enter second premise: ";
    getline(cin, premise2); // Read in second premise

    // Print truth table
    print_truth_table(premise1, premise2);

    // Check if the two premises are logically equivalent
    bool is_equivalent = check_equivalence(premise1, premise2);

    // Print results
    if (is_equivalent)
    {
        cout << "The two premises are logically equivalent" << endl;
    }
    else
    {
        cout << "The two premises are not logically equivalent" << endl;
    }


    return 0;
}
