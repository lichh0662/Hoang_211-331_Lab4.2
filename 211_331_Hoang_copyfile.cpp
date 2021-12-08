#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


int main()
{
	// Open a file and check
	ifstream filein;
	filein.open("File_path_full.txt", ios_base::in);
	if (filein.fail() == true)
	{
		cout << "File_path_full not exxist!" << endl;
		return false;
	}


	// Copy file
	vector<char> arr;
	arr.resize(100);
	for (int i = 0; i < arr.size(); i++)
	{
		filein >> arr[i];
		if (arr[i] == 0)
		{
			break;
		}
	}


	// Create a new file, check and copy from the first file
	ofstream filecopyout;
	filecopyout.open("File_path_full_copy.txt", ios_base::out);
	for (int i = 0; i < arr.size(); i++)
	{
		filecopyout << arr.at(i);
	}
	if (filecopyout.fail() == true)
	{
		cout << "File_path_full_copy.txt not exxist!" << endl;
		return false;
	}

	//close 2 files and return true
	filein.close();
	filecopyout.close();
	return true;
}