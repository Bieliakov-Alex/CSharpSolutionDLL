#include <Windows.h>

extern "C" __declspec(dllexport) int listOfFiles()
{
	TCHAR buffer[MAX_PATH];
	GetCurrentDirectory(sizeof(buffer), buffer);

	WIN32_FIND_DATA* files=0;
	int countOfFiles = 0;
	HANDLE hFiles = FindFirstFile(buffer, files);
	if (hFiles != INVALID_HANDLE_VALUE)
	{
		do
		{
			countOfFiles++;
		} while (FindNextFile(hFiles, files));
	}
	return countOfFiles;
}