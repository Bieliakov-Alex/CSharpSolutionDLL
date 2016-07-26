#include <Windows.h>

extern "C" __declspec(dllexport) int countOfFiles()
{
	WIN32_FIND_DATA files;
	int countOfFiles = 0;
	HANDLE hFiles = FindFirstFile(TEXT(".\\*.dll"), &files);
	if (hFiles != INVALID_HANDLE_VALUE)
	{
		do
		{
			countOfFiles++;
		} while (FindNextFile(hFiles, &files));
	}
	return countOfFiles;
}

//extern "C" __declspec(dllexport) char** 