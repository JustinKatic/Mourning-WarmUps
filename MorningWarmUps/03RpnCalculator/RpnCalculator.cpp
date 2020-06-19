#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> Explode(char seperator, const char* str)
{
    std::vector<std::string> result;
    int i = 0;
    std::string subString;

    while (str[i] != '\0')
    {
        if (str[i] != seperator)
        {
            subString.push_back(str[i]);
        }
        else
        {
            if (subString != "")
            {
                result.push_back(subString);
            }
            subString.clear();
        }
        i++;
    }
    if (subString != "")
    {
        result.push_back(subString);
    }
    return result;
}

float RPN(const std::string equation)
{
    // STEPS:
    // - explode the equasion by space ' ' and store in variable called 'tokens'
    auto tokens = Explode(' ', equation.c_str());
    // - loop through each token... if its a number push its integer value onto the 'stack'

    std::vector<float> stack;
    for (auto& token : tokens)
    {
        //if (c != "+" || c != "-" || c != "/"|| c != "*")
        //{            
        //     stack.push_back(std::stoi(c));
        //}
         if (token == "+")
        {
            float rhs = stack.back();
            stack.pop_back();

            float lhs = stack.back();
            stack.pop_back();
            stack.push_back(lhs + rhs);
        }
        else if (token == "-")
        {
             float rhs = stack.back();
            stack.pop_back();

            float lhs = stack.back();
            stack.pop_back();
            stack.push_back(lhs - rhs);
        }
        else if (token == "/")
        {
             float rhs = stack.back();
            stack.pop_back();

            float lhs = stack.back();
            stack.pop_back();
            stack.push_back(lhs / rhs);
        }
        else if (token == "*")
        {
             float rhs = stack.back();
            stack.pop_back();

            float lhs = stack.back();
            stack.pop_back();

            stack.push_back(lhs * rhs);
        }
        else
         {
             float number = std::stoi(token);
             stack.push_back(number);
         }
        
    }
    //      HINT: use std::stoi to convert string to an int
    //      HINT: create an std::vector<int> to represent the 'stack'
    // - if the token is a symbol ('+', '-', '/', '*') pop the last 2 values off the stack,
    //   do math on them ( one of the + - / * ), and push the result back onto the stack.
    //
    // - once you've iterated over all tokens, the final result of the equasion will be the first and only
    //   item left in the stack.
    //
    // NOTE: at the end, if the stack has more than 1 value, the equasion was not correctly formed.
    //       dont worry about error handeling for now...
    // 


    return stack.back();
}

int main(int argc, char** argv)
{
    {
        std::string equation = "10 20 +";
        std::cout << equation << " = " << RPN(equation) << "\t\t\tExpected: 30" << std::endl;
    }
    {
        std::string equation = "10 20 30 + *";
        std::cout << equation << " = " << RPN(equation) << "\t\t\tExpected: 500" << std::endl;
    }
    {
        std::string equation = "20 10 / 4 *";
        std::cout << equation << " = " << RPN(equation) << "\t\t\tExpected: 8" << std::endl;
    }
    {
        std::string equation = "20 10 - 15 +";
        std::cout << equation << " = " << RPN(equation) << "\t\t\tExpected: 25" << std::endl;
    }

    return 0;
}