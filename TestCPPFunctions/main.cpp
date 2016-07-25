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

int main() {
	std::basic_string<TCHAR> str = ExePath();
	tcout << "my directory is " << str << "\n";
	_getch();
	return 0;
}