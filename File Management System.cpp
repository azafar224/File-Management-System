#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;

int fileInfoCounter = 0, fileDataCounter = 0;	// File Info and File data counter

struct FileInfo
{
	char fileName[50];
	char fileExt[4];
	int  start;
	int  fileIndex;
}fileInfo[10];			//File Information Structure Array

struct FileData
{
	char data;
	int nextIndex;
}fileData[1000];		//File Data Structure Array

void FileInfo ();
void FileData ();
bool createFile ();
void deleteFile (char fName[], char fExt[]);
void viewFile ();


void FileInfo ()
{
	for (int i = 0; i < 10; i++)
	{
	    fileInfo[i].fileIndex = -1;
    }
	fileInfo[9].fileIndex = -3;
}

void FileData ()
{
	for (int i = 0; i < 1000; i++)
	{
		fileData[i].nextIndex = -1;
	}
	fileData[999].nextIndex = -3;
}


bool CreateFile ()
{
	int j = 0, k = 0, h = 0, avaIndex = 0;
	char fName = '\0', fExt = '\0', fData = '\0';
	
	if (fileInfo[fileInfoCounter].fileIndex == -3) 			//STORING FILE INF0
	{
	    cout << "\n End Of Space";
	    return false;
	}
	
	for (int i = 0; i < 30; i++)
	{
	    if (fileInfo[i].fileIndex == -1)		//Checking availability to store File Information
		{
			fileInfoCounter = i;
			break;
		}
	}
	
	if (fileInfo[fileInfoCounter].fileIndex == -1)
	{
	    cout << "\nEnter File Name: ";
	    while (true)
		{
			fName = getchar ();
			if (fName == '\n')
		    {
		    	break;
		    }
			fileInfo[fileInfoCounter].fileName[j++] = fName;	//Storing File Name
		}
		cout << "\nEnter File Extension: ";
		while (true)
		{
			fExt = getchar ();
			if (fExt == '\n')
		    {
		    	break;
		    }
			fileInfo[fileInfoCounter].fileExt[k++] = fExt;	//Storing File Extension
		}
	    
		if (fileDataCounter > 0)
		{
			fileInfo[fileInfoCounter].start = fileDataCounter + 1;	//Storing File Start
		}
	    else
		{
			fileInfo[fileInfoCounter].start = fileDataCounter;
		}
	    fileInfo[fileInfoCounter].fileIndex = 1;	//Storing File Index
	    fileInfoCounter++;
	}
	
	else
	{
	    cout << "\n FIle Info File Index is not -1";
	}

    //STORING FILE DATA/
	if (fileData[fileDataCounter].nextIndex == -3)
    {
    	cout << "\nEnd of Space";
    }
	cout << "\nEnter File Data: ";
	if (fileData[fileDataCounter].nextIndex == -1)
    {
    	while (true)		//Writing Data on file
		{
			fData = getchar ();
			if (fData == '\n')
			{
	    		break;
			}
			for (int i = 0; i <= 30; i++)
		    {
		    	if (fileData[i].nextIndex == -1)
				{
					fileDataCounter = i;	//Checking availability to store File Data
					break;
				}
		    }
			for (int i = fileDataCounter; i <= 30; i++)			//Setting the next index
		    {
		    	if (fileData[i].nextIndex == -1 && fileData[i + 1].nextIndex == -1)
				{
					avaIndex = i + 1;
					break;
				}
		    	if (fileData[i + 1].nextIndex != -1)
				{
					int n = i + 1;
					while (fileData[n].nextIndex != -1)
					{
			    		if (fileData[n].nextIndex == -2)
						{
							avaIndex = n;
							break;
						}
			    		n++;
			    	}
					avaIndex = n + 1;
					break;
				}
		    }
	
			if (fileData[fileDataCounter].nextIndex == -1)
			{
				fileData[fileDataCounter].data = fData;
				fileData[fileDataCounter].nextIndex = avaIndex;	//Writing Data on file
			    fileDataCounter++;
			}
			else
			{			    
				fileDataCounter++;
			}
		}
		
    	fileData[fileDataCounter - 1].nextIndex = -2;	//Setting end of file
    }
	else
    {
    	cout << "\n FIle data next is not -1";
    }
	return true;
}


void deleteFile (char fName[], char fExt[])
{
	char temp[20] = { '0' };
	int l = 1;

	for (int i = 0; i < 30; i++)	//delete file
    {
    	for (int j = 0; j < 20; j++)
		{
			if (fileData[j].nextIndex == l)
	    	{
	    		if (fName[j] == fileInfo[i].fileName[j])
				{
					temp[j] = fileInfo[i].fileName[j];
				}
	      		l++;
	      		continue;
	    	}
			else
	    	{
	    		int flag = j, temp1 = fileData[flag].nextIndex + 1;
	    		if (fileData[j].nextIndex == -2)
				{
					if (fName[j] == fileInfo[i].fileName[j])
		    		{
		    			temp[j] = fileInfo[i].fileName[j];
		    			continue;
		    		}
				}
	    		while (fileData[flag].nextIndex != temp1)
				{
					if (temp1 == fileData[flag].nextIndex)
				    {
				    	if (fName[j] == fileInfo[i].fileName[j])
						{
							temp[j] = fileInfo[i].fileName[j];
						}
				    }
				    
					flag++;
				}
	    	}
		}
	
    	if (strcmp (temp, fName) == 0)
		{
			for (int j = 0; j < 10; j++)
	    	{
	    		fileInfo[i].fileName[j] = '\0';	//Deleting File Name from Array
	    		fileInfo[i].fileExt[j] = '\0';	//Deleting File Extension from Array
			}
			fileInfo[i].start = '\0';	//Deleting File Start from Array
			fileInfo[i].fileIndex = -1;	//Setting File index to -1(Available to write)
			break;
		}
    	fileInfo[i].fileIndex = -1;
    }
    
	int counter = fileInfo[fileInfoCounter].start;
	while (fileData[counter].nextIndex != -2)
    {
	    fileData[counter].data = '\0';	//Deleting File Data from Array
	    fileData[counter].nextIndex = -1;
	    counter++;
    }
	fileData[counter].data = '\0';
	fileData[counter].nextIndex = -1;

	for (int i = 0; i <= 30; i++)
    {
    	if (fileData[i].nextIndex == -1)
		{
			fileDataCounter = i;	//Setting File Data next index to -1(Available to write)
			break;
		}
	}

}


void ViewFile ()
{
	cout << "\nFILE INFO\n";	//File Info
	for (int i = 0; i < 10; i++)
    {
    	for (int j = 0; j < 5; j++)
		{
			cout << fileInfo[i].fileName[j];	//For viewing File Name
		}
    	cout << "\t\t";
    }
	cout << "\n";
	for (int i = 0; i < 10; i++)
    {
	    for (int j = 0; j < 5; j++)
		{
			cout << fileInfo[i].fileExt[j];	//For viewing File Extension
		}
		cout << "\t\t";
    }

	cout << "\nFILE DATA\n";	//FILE INFO
	for (int i = 0; i < 20; i++)
    {
    	cout << fileData[i].data;	//For viewing File Data
    }

}


int main ()
{

	char ch;
	FileInfo ();			//Setting File Information Structured Array to -1(Available to Write) and End of Array to -3(End of File)
	FileData ();			//Setting File Data Structured Array to -1(Available to Write) and End of Array to -3(End of File)
	while (true)
    {
    	cout <<
		"\nPress...\n1.To Create File\n2.To Delete File\n3.To View File\n4.To Exit\nEnter your choice:\t";
    	ch = getche ();
    	switch (ch)
		{
			case '1':
			{
				CreateFile ();
			    break;
			}
			case '2':
			{
		    	char fName[20] = { '0' }, fExt[3] ={'0'};
			    int i = 0;
			    cout << "\nEnter File Name which you want to delete: ";
			    while (ch != '\n')
		    	{
					ch = getchar ();
					if (ch == '\n')
					{
			    		break;
					}
					fName[i++] = ch;
		    	}
			    i = 0;
			    ch = '\0';
			    cout << "\nEnter File Extension: ";
			    while (true)
			    {
					ch = getchar ();
					if (ch == '\n')
					{
				    	break;
					}
					fExt[i++] = ch;
			    }
			    deleteFile (fName, fExt);
			    break;
			}
			case '3':
			{
			    ViewFile ();
			    break;
			}
			case '4':
			{
			    exit (0);
			    break;
			}
			default:
			{
			    cout << "\nWrong Input.";
			}
		}
    }

	return 0;
}
