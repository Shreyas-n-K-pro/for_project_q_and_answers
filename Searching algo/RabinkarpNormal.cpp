#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#define MOD 1000000007  // Define mod value at the top

int calculatehash(const string& str, int prime, int m) 
{
    int hash = 0;
    for (int i = 0; i < str.length(); i++) 
    {
        hash += str[i] * static_cast<int>(pow(prime, i)) % m;
    }
    return hash % m;
}

void rabinkarp(const string& text, const string& pattern) 
{
    int n = text.length();
    int m = pattern.length();
    int prime = 101;

    int ph = calculatehash(pattern, prime, MOD);

    for (int i = 0; i <= n - m; i++) 
    {
        string substr = text.substr(i, m);
        int th = calculatehash(substr, prime, MOD);

        if (th == ph && substr == pattern) 
        {
            cout << "Pattern found at index: " << i << endl;
        }
    }
}

int main() 
{
    string text, pattern;
    cin >> text >> pattern;
    
    rabinkarp(text, pattern);
    
    return 0;
}

