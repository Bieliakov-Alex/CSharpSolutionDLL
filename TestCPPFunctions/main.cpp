#include <windows.h>
#include <string>
#include <iostream>
#include <tchar.h>
#include <conio.h>
using namespace std;

#if defined(UNICODE) || defined(_UNICODE)
#define tcout std::wcout
#else
#define tcout std::cout
#endif

std::basic_string<TCHAR> ExePath() {
	TCHAR buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH);
	std::basic_string<TCHAR> sBuffer = buffer;
	string::size_type pos = sBuffer.find_last_of(TEXT("\\/"));//.find_last_of("\\/");
	//return string(buffer).substr(0, pos);
	return sBuffer.substr(0, pos);
}

int listOfFiles()
{
	WIN32_FIND_DATA files;
	int countOfFiles = 0;
	HANDLE hFiles = FindFirstFile(TEXT(".\\*.*"), &files);
	if (hFiles != INVALID_HANDLE_VALUE)
	{
		do
		{
			countOfFiles++;
		} while (FindNextFile(hFiles, &files));
	}
	return countOfFiles;

	/*char buf[100];
	size_t len = 0;
	wcstombs_s(&len, buf, 100, files.cFileName, wcslen(files.cFileName));
	if (len > 0u) buf[len] = '\0';
	cout << buf << endl;*/
}

int main()
{	
	listOfFiles();
	_getch();
	return 0;
}