#include <Windows.h>

extern "C" __declspec(dllexport) int listOfFiles()
{
	WIN32_FIND_DATA* files=0;
	int countOfFiles = 0;
	HANDLE hFiles = FindFirstFile(TEXT("./"), files);
	if (hFiles != INVALID_HANDLE_VALUE)
	{
		do
		{
			countOfFiles++;
		} while (FindNextFile(hFiles, files));
	}
	return countOfFiles;
}