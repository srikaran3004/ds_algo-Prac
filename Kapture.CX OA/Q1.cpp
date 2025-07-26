#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string CodelandUsernameValidation(string str)
{
    // Rule 1: Length between 4 and 25
    if (str.length() < 4 || str.length() > 25)
        return "false";

    // Rule 2: Starts with a letter
    if (!isalpha(str[0]))
        return "false";

    // Rule 3: Only letters, digits, or underscore
    for (char ch : str)
    {
        if (!(isalnum(ch) || ch == '_'))
            return "false";
    }

    // Rule 4: Doesn't end with underscore
    if (str.back() == '_')
        return "false";

    return "true";
}

int main()
{
    string input;
    getline(cin, input); // Use getline to read input
    cout << CodelandUsernameValidation(input);
    return 0;
}
