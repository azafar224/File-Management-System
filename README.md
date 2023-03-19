File Management System
This program is a file management system that allows users to create, view, and delete files. The program stores both file information and file data in arrays.

How to use
The program menu provides the following options:

Create file
Delete file
View files
Exit
To create a file, select option 1 and enter the file name, file extension, and file data. The program will store the file information and file data in separate arrays. The program can store up to 10 files.

To delete a file, select option 2 and enter the file name and file extension of the file you want to delete. The program will delete the file and its associated data from the arrays.

To view the list of files, select option 3. The program will display the file names and file extensions of all the files that have been created.

To exit the program, select option 4.

Code explanation
The program is written in C++ and consists of a main function and several helper functions. The helper functions include:

FileInfo: Initializes the file information array with -1 values.
FileData: Initializes the file data array with -1 values.
createFile: Creates a new file and stores the file information and file data in the arrays.
deleteFile: Deletes a file and its associated data from the arrays.
viewFile: Displays the list of files that have been created.
The program uses two structures to store file information and file data. The FileInfo structure includes the file name, file extension, starting index, and file index. The FileData structure includes the file data and the next index.

The program limits the number of files that can be created to 10 and limits the amount of data that can be stored to 1000 characters. If the program runs out of space in either array, it will display an error message.
