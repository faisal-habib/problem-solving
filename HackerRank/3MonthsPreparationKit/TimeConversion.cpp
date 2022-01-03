/*
Problem link:
https://www.hackerrank.com/challenges/three-month-preparation-kit-time-conversion/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=preparation-kits&playlist_slugs%5B%5D=three-month-preparation-kit&playlist_slugs%5B%5D=three-month-week-one
*/

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

// copy till am | pm
void _stringCopy(string &s, int startIndex, string &output)
{
    int sz = s.size();
    for (int i = startIndex; i < sz-2; i++)
    {
        output += s[i];
    }
}

string timeConversion(string s)
{
    string output = "";

    if (s[8] == 'P')
    {
        // PM
        if (s[0] == '1' && s[1] == '2')
        {
            _stringCopy(s, 0, output);
        }
        else
        {
            int hour = 0;
            hour = (s[0] - '0') * 10;
            hour += (s[1] - '0');

            hour += 12;

            output = (hour / 10) + '0';
            output += (hour % 10) + '0';
            _stringCopy(s, 2, output);
        }
    }
    else
    {
        // AM
        if (s[0] == '1' && s[1] == '2')
        {
            output = "00";
            _stringCopy(s, 2, output);
        }
        else
        {
            _stringCopy(s, 0, output);
        }
    }

    return output;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
