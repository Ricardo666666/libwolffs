/*
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include <iostream>
#include <sstream>
#include <boost/filesystem.hpp>
#include "wolffs.hpp"

std::string HomeDirPlus(const std::string extra_dir)
{
	return HomeDir + extra_dir;
}

void  dir_list(const std::string &dPath, const bool &R, std::vector<std::string> &list)
{
	//Check if dir is real.
	if(!boost::filesystem::is_directory(dPath))
	{
		std::cout << dPath << " is not a directory." << std::endl;
		return;
	}

	boost::filesystem::directory_iterator enditr;

	for(boost::filesystem::directory_iterator itr(dPath); itr != enditr; ++itr )
	{
		if(boost::filesystem::is_directory(itr->status()) && R)
		{
			dir_list(itr->path().string(), &R, list);
		}

		else
		{
			if(boost::filesystem::is_regular_file(itr->path().string()))
			{
				list.push_back(canonical(itr->path()).string());
			}
		}
	}
}
