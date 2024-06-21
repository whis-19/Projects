#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include<msclr/marshal_cppstd.h>

using namespace std;
fstream input;


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
        loading();
    }

    static Trie* gui;

    static Trie* getInstance() 
    {
        if (!gui)
        {
            gui = new Trie();
        }
        return gui;

    }

    bool insert(string word, string meaning)
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
        return true;
    }

    string searchMeaning(string word)
    {
        int i = 0;
        Node* current = tries;

        for (char ch : word)
        {
            ch = tolower(ch);
            if (current->next[ch - 'a'] == NULL)
            {
                return "";
            }
            current = current->next[ch - 'a'];
            i++;
        }
        if (current->end)
        {

            return current->meaning;
        }
        else
        {
            return "";
        }
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

            return true;
        }
        else
        {
            return false;
        }
    }

 
    void loading()
    {
        string word, meaning;

        
        input.open("Dictionary.txt");

        while (!input.eof())
        {
            input >> word >> meaning;

            insert(word, meaning);
        }
        input.close();

            
        
    }


    bool deleteWord(string word)
    {
        Node* current = tries;
        Node* parent = NULL;


        for (char ch : word)
        {
            ch = tolower(ch);
            parent = current;
            current = current->next[ch - 'a'];
        
        }

        if (current == NULL || !current->end)
        {
            cout << "Word '" << word << "' not found in the dictionary.\n";
            return false;
        }
        else {
            current->end = false;
            
            return true;
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

            return false;
        }
  

        
           current->meaning = newMeaning;

            return true;
        
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


Trie* Trie::gui = NULL;
