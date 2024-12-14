#  **Text Editor in C++**

A lightweight, command-line text editor built in C++ with dynamic memory handling. This project provides essential features for text manipulation, such as loading, viewing, searching, replacing, and saving text files. Perfect for showcasing skills in file handling, dynamic memory allocation, and string manipulation.

---

##  **Features**
- **Load File**: Load a text file into memory for editing.
- **Display Text**: View the content of the loaded file.
- **Search Text**: Find specific words or phrases in the text.
- **Replace Text**: Replace all occurrences of a word or phrase with another.
- **Save File**: Save the modified text back to a file.
- **Dynamic Memory Handling**: Efficiently stores text using dynamically allocated memory, allowing flexible line management.

---

##  **How to Use**
### **Compilation**
1. Save the file as `texteditor.cpp`.
2. Open a terminal and navigate to the directory containing the file.
3. Compile the program:
   ```bash
   g++ -o texteditor texteditor.cpp
   ```
4.	Run the executable:
   ```bash
   ./texteditor
   ```


## **Menu Options**
1. Load File:
	•	Load a text file into memory for viewing and editing.
	•	Example:
      Enter filename: input.txt
      File loaded successfully
  
2.	Display Text:
	•	Displays the content of the loaded text file.
3.	Search Text:
	•	Find occurrences of a specific word or phrase in the text.
	•	Example:
       Enter text to search: hello
       Searching for 'hello'...
       Text found in line 3: hello world
4.	Replace Text:
	•	Replace all occurrences of a word/phrase with another.
	•	Example:
        Enter text to search: oldword
        Enter replacement text: newword
        Replacing 'oldword' with 'newword'...
5.	Save File:
	•	Save the modified text back to a file.
	•	Example:
        Enter filename to save: output.txt
        File saved successfully
6.	Exit:
	•	Ends the program.

## **How It Works**
### 1.	Dynamic Memory Management:
	•	Uses a dynamically allocated 2D array (char**) to store lines of text.
	•	Expands the array when the number of lines exceeds the current capacity.
### 2.	File Handling:
	•	loadFile: Reads the contents of a file line by line and stores it in memory.
	•	saveFile: Writes the current text content to a file.
### 3.	String Manipulation:
	•	searchText: Finds occurrences of a word/phrase using strstr.
	•	replaceText: Replaces all occurrences of a word/phrase using strcpy and strstr.

## **Future Enhancements**
	1.	Add undo/redo functionality for editing.
	2.	Include syntax highlighting in the displa yed text.
	3.	Support for large files with pagination.
	4.	Replace char** with std::vector<std::string> for better memory management.
	5.	Add functionality for line-specific edits (e.g., insert, delete lines).

## **Credits**

Developed by Abdullah Munir 
