#include <iostream>
#include <fstream>
using namespace std;

class TextEditor
{
private:
    char** lines;
    int lineCount = 0;
    int capacity = 1;
    
    void expandCapacity()
    {
        capacity = capacity * 2;
        char** newLines = new char*[capacity];
        
        for(int i = 0; i<lineCount; i++)
        {
            newLines[i] = lines[i];
        }
        delete [] lines;
        lines = newLines;
    }
    
public:
    TextEditor() : lines(nullptr), lineCount(0), capacity(10)
    {
        lines = new char*[capacity];
    }
    
    ~TextEditor()
    {
        for (int i = 0; i < lineCount; i++)
        {
            delete[] lines[i];
        }
        delete[] lines;
    }
    
    void loadFile(const char* fileName)
    {
        ifstream file(fileName);
        if(!file)
        {
            cout << "Error" << endl;
            return;
        }
        
        lineCount = 0;
        string line;
        
        if(lineCount == capacity)
        {
            expandCapacity();
        }
        
        while (getline(file, line))
        {
            lines [lineCount] = new char [line.length() + 1];
            strcpy(lines[lineCount], line.c_str());
            lineCount++;
        }
        
        file.close();
    }
    
    void saveFile(const char* fileName)
    {
        ofstream file(fileName);
        if(!file)
        {
            cout << "Error" << endl;
            return;
        }
        
        for(int i = 0; i<lineCount; i++)
        {
            file << lines[i] << endl;
        }
        
        file.close();
    }
    
    void searchText(const string &toFind)
    {
        for(int i = 0; i<lineCount; i++)
        {
            if (strstr(lines[i], toFind.c_str()))
            {
                cout << "Text found in line " << i + 1 << ": " << lines[i] << endl;
            }
        }
    }
    
    void replaceText(const string& toFind, const string& toReplace)
    {
        for (int i = 0; i < lineCount; ++i)
        {
            char* pos = strstr(lines[i], toFind.c_str());
            
            while (pos)
            {
                string updatedLine = string(lines[i]);
                updatedLine.replace(pos - lines[i], toFind.length(), toReplace);
                delete[] lines[i];
                lines[i] = new char[updatedLine.length() + 1];
                strcpy(lines[i], updatedLine.c_str());
                pos = strstr(lines[i], toFind.c_str());
            }
        }
    }
    
    void displayText()
    {
        for(int i = 0; i<lineCount; i++)
        {
            cout << lines[i] << endl;
        }
    }
    
};

int main ()
{
    TextEditor editor;
    int choice;
    string toFind, toReplace, filename;
    
    do {
        cout << "Text Editor" << endl;
        cout << "1. Load File" << endl;
        cout << "2. Display Text" << endl;
        cout << "3. Search Text" << endl;
        cout << "4. Replace Text" << endl;
        cout << "5. Save File" << endl;
        cout << "6. Exit" << endl;
        cout << endl;
        
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        
        switch (choice)
        {
            case 1:
                cout << "Enter filename: ";
                getline(cin, filename);
                editor.loadFile(filename.c_str());
                cout << "File loaded successfully" << endl;
                break;
                
            case 2:
                cout << "Displaying text: " << endl;
                editor.displayText();
                break;
                
            case 3:
                cout << "Enter text to search: ";
                getline(cin, toFind);
                cout << "Searching for '" << toFind << "'... " << endl;
                editor.searchText(toFind);
                break;
                
            case 4:
                cout << "Enter text to search: ";
                getline(cin, toFind);
                cout << "Enter replacement text: ";
                getline(cin, toReplace);
                cout << "Replacing '" << toFind << "' with '" << toReplace << "'..." << endl;
                editor.replaceText(toFind, toReplace);
                break;
                
            case 5:
                cout << "Enter filename to save: ";
                getline(cin, filename);
                editor.saveFile(filename.c_str());
                cout << "File saved successfully" << endl;
                break;
                
            case 6:
                cout << "Exiting..." << endl;
                break;
                
            default:
                cout << "Invalid choice" << endl;
                break;
        }
        
    } while (choice != 6);
    
    return 0;
}
