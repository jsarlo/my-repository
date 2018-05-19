#include <iostream>
#include <string>
using namespace std;
class Vigenere{
public:
    string key;

Vigenere(string key)
{
    for (int i = 0; i<key.size(); i++)
    {
        if (key[i] >= 'A' && key[i] <= 'Z')
           this ->key += key[i];
        else if (key[i] >= 'a' && key[i] <= 'z')
            this->key+= key[i] + 'A' - 'a';
    }
}
string generateKey(string s, string k)
{
    //This function creates a key out of the keyword given by the user
    //This key must match the length of the message to be encrypted
    int x = s.size(); //create string size

    for (int i = 0; ; i++)
    {
        if (x == i)
            i = 0;
        if (k.size() == s.size())
            break;
        k.push_back(k[i]);
        //keep pushing back until the length of
        //the key is equal to the length of the message
    }
    return k;
}

string cipher(string text)
{
    //This function encrypts the text
    string out;

    for(int i = 0, j = 0; i < text.length(); i++)
    {
        char c = text[i];

        if (c >= 'a' && c <= 'z')
            c += 'A' - 'a';
        else if (c < 'A' || c > 'Z')
            continue;
        out += (c +key[j]-2*'A')%26 + 'A';
        j=(j+1)%key.length();
    }
}

string decrypt(string text)
{
    string out;

    for(int i = 0, j = 0; i < text.length(); i++)
    {
        char c = text[i]; //loop through each character

        if (c >= 'a' && c <= 'z')
            c += 'A' - 'a';
        else if (c < 'A' || c > 'Z')
            continue;
        out += (c +key[j]-2*'A')%26 + 'A';
        j=(j+1)%key.length();
    }
}

int main()
{
    cout << "Hello world";

}

};
