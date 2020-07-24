
#include <iostream>



bool isValidHexCode(const std::string str)
{
    if (str.size() != 7)
        return false;
    if (str[0] != '#')
        return false;

    bool hasUpper = false;
    bool hasLower = false;

    for (int i = 1; i < str.size(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {

        }
        else if (str[i] >= 'A' && str[i] <= 'F')
        {
            hasUpper = true;
        }
          
        else if (str[i] >= 'a' && str[i] <= 'f')
        {
            hasLower = true;
        }
         
        else
        {
            return false;
        }

        if (hasUpper & hasLower)
        {
            return false;
        }     
    }
    return true;
}

int main()
{
	std::cout << isValidHexCode("#CD5C5C") << std::endl;// ➞ true

	std::cout << isValidHexCode("#EAECEE") << std::endl;// ➞ true

	std::cout << isValidHexCode("#eaecee") << std::endl;// ➞ true

	std::cout << isValidHexCode("#CD5C58C") << std::endl;// ➞ false
		// Length exceeds 6

	std::cout << isValidHexCode("#CD5C5Z") << std::endl;// ➞ false

		// Not all alphabetic characters in A-F
	std::cout << isValidHexCode("#CD5C&C") << std::endl;// ➞ false

		// Contains unacceptable character
	std::cout << isValidHexCode("CD5C5C") << std::endl;// ➞ false

		// Missing #
	std::cout << isValidHexCode("#cd5C5D") << std::endl;// ➞ false
		// all aplphabetic characters must match in case
};
