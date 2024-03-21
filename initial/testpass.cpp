#include <cstring>
#include <iostream>
#include <string>
bool isDigit(char c)
{
    return c >= '0' && c <= '9';
}

bool isAlpha(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int checkPassword(const char *s, const char *email)
{
    const int MIN_LENGTH = 8;
    const int MAX_LENGTH = 20;
    const char *specialChars = "@#%$!";
    const char *SS = strtok((char *)email, "@");
    int len = strlen(s);
    if (len < MIN_LENGTH)
        return -1;
    if (len > MAX_LENGTH)
        return -2;
    if (strstr(s, SS) != NULL)
        return -(300 + (strstr(s, SS) - s)); // s la vi tri dau tien cua chuoi s, co s = 0
    for (int i = 0; i < len - 2; ++i)
    {
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2])
            return -(400 + i);
    }
    bool hasSpecialChar = false;
    for (int i = 0; i < len; ++i)
    {
        if (!isDigit(s[i]) && !isAlpha(s[i]) && strchr(specialChars, s[i]) == NULL)
            return i;
        if (strchr(specialChars, s[i]) != NULL)
            hasSpecialChar = true;
    }
    if (!hasSpecialChar)
        return -5;
    return -10;
}

using namespace std;

int main()
{
    string email = "pink@gmail.com";
    string pass = "012345pink#pink";
    const char *mail = &email[0];
    const char *pas = &pass[0];
    cout << checkPassword(pas, mail);
    return 0;
}