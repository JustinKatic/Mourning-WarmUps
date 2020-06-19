#include <iostream>
#include <string>

using namespace std;

string Sort(string word)
{
    bool sorted = false;
    while (!sorted)
    {
        sorted = true;

        for (int i = 0; i < word.size(); i++)
        {
            if (word[i] > word[i + 1])
            {
                char tmp = word[i];
                word[i] = word[i + 1];
                word[i + 1] = tmp;
                sorted = false;
            }
        }
    }
    return word;
}

string ToLower(string word)
{
    for (size_t i = 0; i < word.size(); i++)
    {
        word[i] = tolower(word[i]);
    }
    return word;
}

bool isIsogram(string word)
{
    word = ToLower(word);
    word = Sort(word);

    for (int i = 0; i < word.size(); i++)
    {
        if (word[i] == word[i + 1])
        {
            return false;
        }
    }  
    return true;
}
int main(int argc, char** argv)
{
    std::cout << "Aaron" << "\t" << isIsogram("Aaron") << std::endl;

    // random words from a random word generator :P
    std::cout << "Bake" << "\t" << isIsogram("Bake") << std::endl;
    std::cout << "Lay" << "\t" << isIsogram("Lay") << std::endl;
    std::cout << "Issue" << "\t" << isIsogram("Issue") << std::endl;
    std::cout << "Wood" << "\t" << isIsogram("Wood") << std::endl;
    std::cout << "Swop" << "\t" << isIsogram("Swop") << std::endl;
    std::cout << "Coup" << "\t" << isIsogram("Coup") << std::endl;
    std::cout << "Trouser" << "\t" << isIsogram("Trouser") << std::endl;
    std::cout << "Superior" << "\t" << isIsogram("Superior") << std::endl;
    std::cout << "History" << "\t" << isIsogram("History") << std::endl;
    std::cout << "Disclose" << "\t" << isIsogram("Disclose") << std::endl;

    return 0;
}


//shorter method

//bool isIsogram(const std::string& word)
//{
//    int length = word.length();
//    for (int j = 0; j < length; j++)
//    {
//        for (int i = j + 1; i < length; i++)
//        {
//            if (tolower(word[j]) == tolower(word[i]))
//            {
//                return false;
//            }
//        }
//    }
//    return true;
//}