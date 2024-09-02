#include <bits/stdc++.h>
using namespace std;
int getLongest(string text, string regex)
{
    int n = text.size();
    int m = regex.size();
    string s1 = "";
    string s2 = "";
    int sign = 0;
    for (int i = 0; i < m; i++)
    {
        if (regex[i] == '*')
        {
            sign = 1;
        }
        if (sign == 0 && regex[i] != '*')
        {
            s1 += regex[i];
        }
        if (sign == 1 && regex[i] != '*')
        {
            s2 += regex[i];
        }
    }

    int x = text.find(s1);
    reverse(text.begin(), text.end());
    reverse(s2.begin(), s2.end());
    int y = n - text.find(s2);
    if (x == -1 || y == -1)
    {
        return -1;
    }
    if (x > y)
    {
        return -1;
    }
    return y - x;
}
int main()
{
    string s1 = "hackerrank";
    string s2 = "ack*r";
    cout<<getLongest(s1, s2);
}