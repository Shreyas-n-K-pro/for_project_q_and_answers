#include <iostream>
#include <string>

using namespace std;

#define MOD 1000000007  // Define mod value at the top

void rolling(const string& text, const string& pattern) 
{
    int n = text.length();
    int m = pattern.length();
    int prime = 101;

    long long ph = 0;
    for (int i = 0; i < m; i++) 
    {
        ph = (ph * prime + pattern[i]) % MOD;
    }

    long long th = 0;
    for (int i = 0; i < m; i++) 
    {
        th = (th * prime + text[i]) % MOD;
    }

    long long primep = 1;
    for (int i = 0; i < m - 1; i++) 
    {
        primep = (primep * prime) % MOD;
    }

    if (ph == th) 
    {
        if (text.substr(0, m) == pattern) 
        {
            cout << "Pattern found at index: 0" << endl;
        }
    }

    for (int i = 1; i <= n - m; i++) 
    {
        th = (th - text[i - 1] * primep) % MOD;
        th = (th * prime + text[i + m - 1]) % MOD;

        if (th < 0) 
        {
            th += MOD;
        }

        if (ph == th) 
        {
            if (text.substr(i, m) == pattern) 
            {
                cout << "Pattern found at index: " << i << endl;
            }
        }
    }
}

int main() 
{
    string text, pattern;
    cin >> text >> pattern;
    
    rolling(text, pattern);
    
    return 0;
}
