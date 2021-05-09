#include "WorkingWithFiles.h"

void WorkingWithFiles::help()
{
	std::cout << "The following commands are supported:" << std::endl;
	std::cout << "open<file>		opens <file>" << std::endl;
	std::cout << "close				closes curently opened file" << std::endl;
	std::cout << "save				saves the currently open file" << std::endl;
	std::cout << "save				saves the currently open file" << std::endl;
	std::cout << "saveAs <file>		saves the currently open file in <file>" << std::endl;
	std::cout << "help				print this information" << std::endl;
}
