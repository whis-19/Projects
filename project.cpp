#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>

using namespace std;

void color(int colour)
{
    HANDLE CLR = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(CLR, colour);
}

struct Node
{
    bool end;
    string meaning;
    vector<Node*> next;

    Node()
    {
        end = false;
        next.resize(26, NULL);
    }
};

class Trie
{
private:
    Node* tries;

public:
    Trie()
    {
        tries = new Node();
    }

    void insert(string word, string meaning)
    {
        int i = 0;
        Node* current = tries;
        for (char ch : word)
        {
            ch = tolower(ch);
            if (current->next[ch - 'a'] == NULL)
            {
                current->next[ch - 'a'] = new Node();
            }

            current = current->next[ch - 'a'];
            i++;
        }
        current->end = true;
        current->meaning = meaning;
    }

    bool search(string word)
    {
        int i = 0;
        Node* current = tries;

        for (char ch : word)
        {
            ch = tolower(ch);
            if (current->next[ch - 'a'] == NULL)
            {
                return false;
            }
            current = current->next[ch - 'a'];
            i++;
        }
        if (current->end)
        {
            color(10);
            cout << "Word : " << word << "\tMeaning : " << current->meaning << endl;
            color(07);
            return true;
        }
        else
        {
            return false;
        }
    }

    void printDictionaryHelper(Node* start, string currentWord = "")
    {
        color(10);
        if (start->end)
        {
            cout << currentWord << "\t\t\t" << start->meaning << endl;
        }

        for (int i = 0; i < 26; i++)
        {
            if (start->next[i] != NULL)
            {
                printDictionaryHelper(start->next[i], currentWord + char('a' + i));
            }
        }
    }

    void printDictionary()
    {
        printDictionaryHelper(tries);
    }

    bool deleteWord(string word)
    {
        Node* current = tries;
        Node* parent = NULL;
        int i = 0;

        for (char ch : word)
        {
            ch = tolower(ch);
            parent = current;
            current = current->next[ch - 'a'];
            i++;
        }

        if (current == NULL || !current->end)
        {
            cout << "Word '" << word << "' not found in the dictionary.\n";
            return false;
        }
        color(10);
        cout << "Word: " << word << "\tMeaning: " << current->meaning << endl;
        color(7);
        cout << "Are you sure you want to delete this word? (y/n): ";
        char choice;
        cin >> choice;

        if (choice == 'y' || choice == 'Y')
        {
            current->end = false;
            cout << "Word '" << word << "' deleted from the dictionary.\n\n";
            return true;
        }
        else
        {
            cout << "Deletion canceled.\n\n";
            return false;
        }
    }
    void saveToFile(string filename)
    {
        ofstream output(filename);
        saveToFileHelper(tries, "", output);
        output.close();
    }

    void saveToFileHelper(Node* start, string currentWord, ofstream& output)
    {
        if (start->end)
        {
            output << currentWord << " " << start->meaning << endl;
        }

        for (int i = 0; i < 26; i++)
        {
            if (start->next[i] != NULL)
            {
                saveToFileHelper(start->next[i], currentWord + char('a' + i), output);
            }
        }
    }
    bool updateWord(string word, string newMeaning)
    {
        Node* current = tries;
        int i = 0;

        for (char ch : word)
        {
            ch = tolower(ch);
            current = current->next[ch - 'a'];
            i++;
        }

        if (current == NULL || !current->end)
        {
            cout << "Word '" << word << "' not found in the dictionary.\n";
            return false;
        }
        color(10);
        cout << "Word: " << word << "\tCurrent Meaning: " << current->meaning << endl;
        color(1);
        cout << "New Meaning: " << newMeaning << endl;
        color(7);
        cout << "Are you sure you want to update the meaning of this word? (y/n): ";
        char choice;
        cin >> choice;

        if (choice == 'y' || choice == 'Y')
        {
            current->meaning = newMeaning;
            cout << "Word '" << word << "' updated in the dictionary.\n\n";
            return true;
        }
        else
        {
            cout << "Update canceled.\n\n";
            return false;
        }
    }

    vector<string> suggestWords(string prefix)
    {
        vector<string> suggestions;
        Node* current = tries;

        for (char ch : prefix)
        {
            ch = tolower(ch);
            if (current->next[ch - 'a'] == NULL)
            {
                
                return suggestions;
            }
            current = current->next[ch - 'a'];
        }

        suggestWordsHelper(current, prefix, suggestions);
        return suggestions;
    }

    void suggestWordsHelper(Node* start, string currentWord, vector<string>& suggestions)
    {
        if (start->end)
        {
            suggestions.push_back(currentWord);
        }

        for (int i = 0; i < 26; i++)
        {
            if (start->next[i] != NULL)
            {
                suggestWordsHelper(start->next[i], currentWord + char('a' + i), suggestions);
            }
        }
    }

    ~Trie() {};
};

void loading_screen(fstream& input, Trie* T)
{
    string word, meaning;
    color(10);
    cout << endl
        << "\t\t\t\t\t\t\tDICTIONARY" << endl;
    cout << "\n\n\n\n";
    cout << "\t\t\t\t\t\t\t LOADING\n\t\t\t\t\t";
    for (int i = 0; i < 40; i++)
    {
        Sleep(100);
        cout << ".";
    }
    cout << "\n";
    input.open("Dictionary.txt");
    if (!input)
    {
        cout << "\n\n\n\t\t\t\t\t    Dictionary database not found\n\n\n";
        color(7);
        exit(1);
    }
    else
    {
        while (input >> word >> meaning)
        {
            T->insert(word, meaning);
        }
        input.close();
        system("CLS");
        color(2);
        cout << "\t\t\t\t\tDictionary Loaded Successfully\n\n";
        Sleep(600);
    }
}

int main()
{
    fstream input;
    string word, meaning, searchWord;
    int choice;

    color(15);

    Trie* myTries = new Trie();

    loading_screen(input, myTries);
    cout << "\t\t\t\t\t\tDictionary\n\n\n";
    do
    {
        color(1);
        cout << "\n1. Search Meaning of Word";
        cout << "\n2. Print Dictionary";
        cout << "\n3. Add Word into Dictionary";
        cout << "\n4. Delete Word from Dictionary";
        cout << "\n5. Update Meaning of Word in Dictionary";
        cout << "\n6. Suggest Words";
        color(4);
        cout << "\n0. Exit\n";
        color(7);
        cout << "\n\t\t\t\t\t\tEnter Your Choice Here: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            system("cls");
            cout << "Enter Word to Search : ";
            cin >> word;
            if (!myTries->search(word))
            {
                cout << "Word : " << word << " doesn't exist in our Dictionary.\n\n";
                // Suggest words
                vector<string> suggestions = myTries->suggestWords(word);
                if (!suggestions.empty())
                {
                    cout << "Suggestions:\n";
                    for (const string& suggestedWord : suggestions)
                    {
                        cout << suggestedWord << endl;
                    }
                }
                else
                {
                    cout << "No suggestions available.\n";
                }
            }
            break;
        case 2:
            system("cls");
            cout << "Words\t\t\tMeanings\n";
            myTries->printDictionary();
            break;
        case 3:
            system("cls");
            cout << "Enter Word to add in Dictionary : ";
            cin >> word;
            cout << "Enter meaning of " << word << " to save in Dictionary : ";
            cin >> meaning;
            myTries->insert(word, meaning);
            myTries->saveToFile("Dictionary.txt");
            break;
        case 4:
            system("cls");
            cout << "Enter Word to delete from Dictionary : ";
            cin >> word;
            if (myTries->deleteWord(word))
            {
                cout << "Word '" << word << "' deleted from the dictionary.\n\n";
                myTries->saveToFile("Dictionary.txt");
            }
            else
            {
                cout << "Word '" << word << "' not found in the dictionary.\n\n";
            }
            break;
        case 5:
            system("cls");
            cout << "Enter Word to update in Dictionary : ";
            cin >> word;
            cout << "Enter new meaning of " << word << " to update in Dictionary : ";
            cin >> meaning;
            if (myTries->updateWord(word, meaning))
            {
                cout << "Word '" << word << "' updated in the dictionary.\n\n";
                myTries->saveToFile("Dictionary.txt");
            }
            else
            {
                cout << "Word '" << word << "' not found in the dictionary.\n\n";
            }
            break;
        case 6:
            system("cls");
            cout << "Enter Word to get suggestions : ";
            cin >> searchWord;
            {
                vector<string> suggestions = myTries->suggestWords(searchWord);
                if (!suggestions.empty())
                {
                    int i = 0;
                    cout << "Suggestions:\n";
                    for (const string& suggestedWord : suggestions)
                    {
                        if (i == 10) { break; }
                        cout << i+1 << "- " << suggestedWord << endl;
                        i++;
                    }
                }
                else
                {
                    cout << "No suggestions available.\n";
                }
            }
            break;
        case 0:
            cout << "\nClosing Dictionary....\n\n";
            break;
        default:
            cout << "\nInvalid Choice. Try Again.\n\n";
            system("pause");
            system("cls");
            break;
        }
        color(07);

    } while (choice != 0);

    cout << "\nDictionary Application Closed Successfully\n\n";
    color(07);
    system("pause");

    return 0;
}
