
#include <iostream>
using namespace std;

int main()
{
    string paragraph;
    cout << "Enter a paragraph:\n";
    getline(cin, paragraph);

    for (int i = 0; i < paragraph.length(); i++)
    {
        if (paragraph[i] >= 'A' && paragraph[i] <= 'Z')
        {
            paragraph[i] = paragraph[i] + ('a' - 'A');
        }
    }

    string words[100];
    int wordCount = 0;

    string currentWord = "";

    for (int i = 0; i <= paragraph.length(); i++)
    {
        if (paragraph[i] != ' ' && paragraph[i] != '\0')
        {
            currentWord += paragraph[i];
        }
        else
        {
            if (currentWord != "")
            {
                words[wordCount] = currentWord;
                wordCount++;
                currentWord = "";
            }
        }
    }

    int freq[100] = {0};
    bool visited[100] = {false};

    for (int i = 0; i < wordCount; i++)
    {
        if (visited[i])
            continue;

        int count = 1;

        for (int j = i + 1; j < wordCount; j++)
        {
            if (words[i] == words[j])
            {
                count++;
                visited[j] = true;
            }
        }

        freq[i] = count;
    }

    cout << "\nWord Frequencies:\n";
    for (int i = 0; i < wordCount; i++)
    {
        if (!visited[i])
        {
            cout << words[i] << " : " << freq[i] << endl;
        }
    }

    return 0;
}

