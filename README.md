**File Management System**

This is a simple file management system implemented in C++. It allows you to create, delete, and view files. The system uses two arrays to store file information and file data.

**Features**
    Create a file: You can create a new file by providing a name, extension, and data.
    Delete a file: You can delete a file by providing its name and extension.
    View files: You can view the list of existing files and their extensions.
    Exit: You can exit the program.
    Usage
    Compile and run the code using a C++ compiler.
    Follow the on-screen instructions to perform various operations.

**Code Explanation**

  The code consists of several functions:

  FileInfo()
  This function initializes the file information structure array, setting all file indexes to -1 except for the last index, which is set to -3.

  FileData()
  This function initializes the file data structure array, setting all next indexes to -1 except for the last index, which is set to -3.

  CreateFile()
  This function allows you to create a new file. It prompts you to enter the file name, extension, and data. The file information is stored in the fileInfo array, and the     file data is stored in the fileData array.

  deleteFile(char fName[], char fExt[])
  This function allows you to delete a file by providing its name and extension. It searches for the file in the fileInfo array and deletes the corresponding file            information and data from the fileData array.

  ViewFile()
  This function displays the file information and data stored in the fileInfo and fileData arrays.

  main()
  The main() function is the entry point of the program. It calls the FileInfo() and FileData() functions to initialize the arrays and then enters a loop to accept user input and perform operations accordingly.

How to Use
Compile the code using a C++ compiler. For example, you can use the following command in a terminal:

    g++ main.cpp -o file_management_system
    
Run the compiled program. For example, using the following command:

    ./file_management_system
    
Follow the on-screen instructions to create, delete, and view files.

Note: This code has a limited capacity to store file information and data. It uses fixed-size arrays, so it can handle up to 10 file information entries and 1000 file data entries.
