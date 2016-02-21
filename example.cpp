#include <iostream>
#include <vector>
#include "Pr0Wolf29/wolffs.hpp"

int main(void)
{
	std::cout << "Home directory: " << HomeDir << std::endl;
	std::cout << "Home directory + '/bin': " << HomeDirPlus("/bin") << std::endl;

	std::vector<std::string> f_list;
	dir_list(".", true, f_list);

	for(const std::string &file : f_list)
	{
		std::cout << file << std::endl;
	}


	return 0;
}
