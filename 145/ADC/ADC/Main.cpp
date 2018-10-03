/*	Solution for Challenge #145 from /g/'s Pro/g/ramming Challenges v 4.0
	ASCII Art Digital Clock
	Current solution works well enough. Some things to clean it up would be to fix the flickering caused by the console clearing
	and making the date ASCII art as well. Increasing portability is also worth looking into.
	This was written on Windows 10 in Visual Studio in C++, so I'm not sure how portable it is at the moment.
	Started and finished January 2, 2017.
	Solution by Andrew Roberts
*/

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string>
#include <Windows.h>

void Draw12Time (std::string time);
void Draw24Time (std::string time);
const std::string currentDateTime ();
std::string parseDate(std::string dnt);
std::string parseTime(std::string dnt);
std::string LineNumber(int num, char c);

int main(int argc, char** argv)
{
	std::string t;
	//t = currentDateTime();
	//std::string date = parseDate(t);
	//std::string time = parseTime(t);

	//std::cout << date << "\n" << std::endl;

	while (true)
	{
		system("cls");
		t = currentDateTime();
		std::string date = parseDate(t);
		std::string time = parseTime(t);

		std::cout << date << "\n" << std::endl;
		Draw24Time(time);
		Sleep(500);		
	}

	/*
	t = currentDateTime();
	std::string date = parseDate(t);
	std::string time = parseTime(t);
	std::cout << time << std::endl;
	*/
	getchar();
	return 0;
}

std::string parseDate(std::string dnt)
{
	// Parse out date
	std::string s = dnt;
	std::string date;
	std::string delimit = ".";

	size_t pos = 0;
	std::string token;
	while ((pos = s.find(delimit)) != std::string::npos)
	{
		token = s.substr(0, pos);
		date = token;
		s.erase(0, pos + delimit.length());
	}
	return date;
}

std::string parseTime(std::string dnt)
{
	// Parse out time
	std::string s = dnt;
	std::string time;
	std::string delimit = ".";

	size_t pos = 0;
	std::string token;
	while ((pos = s.find(delimit)) != std::string::npos)
	{
		token = s.substr(pos+1, s.length());
		time = token;
		s.erase(0, pos + delimit.length());
	}
	return time;
}

void Draw12Time(std::string time)
{	

}

void Draw24Time(std::string time)
{
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 0; j < time.length(); j++)
		{
			std::cout << LineNumber(i, time[j]);
		}
		std::cout << std::endl;
	}
}

const std::string currentDateTime()
{
	time_t		now = time(0);
	struct tm	tstruct;
	char		buf[80];
	tstruct = *localtime(&now);

	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

	return buf;
}


/*	Tediously hardcoded ASCII characters.
	Refactor this when you think of a better way of doing it.
*/
std::string LineNumber(int num, char c)
{
	std::string s;
	if (c == '0')
	{
		if (num == 1)
		{
			s = "  /$$$$$$ ";
		}
		else if (num == 2)
		{
			s = " /$$$_  $$";
		}
		else if (num == 3)
		{
			s = "| $$$$\\ $$";
		}
		else if (num == 4)
		{
			s = "| $$ $$ $$";
		}
		else if (num == 5)
		{
			s = "| $$\\ $$$$";
		}
		else if (num == 6)
		{
			s = "| $$ \\ $$$";
		}
		else if (num == 7)
		{
			s = "|  $$$$$$/";
		}
		else if (num == 8)
		{
			s = " \\______/ ";
		}
	}
	else if (c == '1')
	{
		if (num == 1)
		{
			s = "   /$$  ";
		}
		else if (num == 2)
		{
			s = " /$$$$  ";
		}
		else if (num == 3)
		{
			s = "|_  $$  ";
		}
		else if (num == 4)
		{
			s = "  | $$  ";
		}
		else if (num == 5)
		{
			s = "  | $$  ";
		}
		else if (num == 6)
		{
			s = "  | $$  ";
		}
		else if (num == 7)
		{
			s = " /$$$$$$";
		}
		else if (num == 8)
		{
			s = "|______/";
		}
	}
	else if (c == '2')
	{
		if (num == 1)
		{
			s = "  /$$$$$$ ";
		}
		else if (num == 2)
		{
			s = " /$$__  $$";
		}
		else if (num == 3)
		{
			s = "|__/  \\ $$";
		}
		else if (num == 4)
		{
			s = "  /$$$$$$/";
		}
		else if (num == 5)
		{
			s = " /$$____/ ";
		}
		else if (num == 6)
		{
			s = "| $$      ";
		}
		else if (num == 7)
		{
			s = "| $$$$$$$$";
		}
		else if (num == 8)
		{
			s = "|________/";
		}
	}
	else if (c == '3')
	{
		if (num == 1)
		{
			s = "  /$$$$$$ ";
		}
		else if (num == 2)
		{
			s = " /$$__  $$";
		}
		else if (num == 3)
		{
			s = "|__/  \\ $$";
		}
		else if (num == 4)
		{
			s = "   /$$$$$/";
		}
		else if (num == 5)
		{
			s = "  |___  $$";
		}
		else if (num == 6)
		{
			s = " /$$  \\ $$";
		}
		else if (num == 7)
		{
			s = "|  $$$$$$/";
		}
		else if (num == 8)
		{
			s = " \\______/ ";
		}
	}
	else if (c == '4')
	{
		if (num == 1)
		{
			s = " /$$   /$$";
		}
		else if (num == 2)
		{
			s = "| $$  | $$";
		}
		else if (num == 3)
		{
			s = "| $$  | $$";
		}
		else if (num == 4)
		{
			s = "| $$$$$$$$";
		}
		else if (num == 5)
		{
			s = "|_____  $$";
		}
		else if (num == 6)
		{
			s = "      | $$";
		}
		else if (num == 7)
		{
			s = "      | $$";
		}
		else if (num == 8)
		{
			s = "      |__/";
		}
	}
	else if (c == '5')
	{
		if (num == 1)
		{
			s = " /$$$$$$$ ";
		}
		else if (num == 2)
		{
			s = "| $$____/ ";
		}
		else if (num == 3)
		{
			s = "| $$      ";
		}
		else if (num == 4)
		{
			s = "| $$$$$$$ ";
		}
		else if (num == 5)
		{
			s = "|_____  $$";
		}
		else if (num == 6)
		{
			s = " /$$  \\ $$";
		}
		else if (num == 7)
		{
			s = "|  $$$$$$/";
		}
		else if (num == 8)
		{
			s = " \\______/ ";
		}
	}
	else if (c == '6')
	{
		if (num == 1)
		{
			s = "  /$$$$$$ ";
		}
		else if (num == 2)
		{
			s = " /$$__  $$";
		}
		else if (num == 3)
		{
			s = "| $$  \\__/";
		}
		else if (num == 4)
		{
			s = "| $$$$$$$ ";
		}
		else if (num == 5)
		{
			s = "| $$__  $$";
		}
		else if (num == 6)
		{
			s = "| $$  \\ $$";
		}
		else if (num == 7)
		{
			s = "|  $$$$$$/";
		}
		else if (num == 8)
		{
			s = " \\______/ ";
		}
	}
	else if (c == '7')
	{
		if (num == 1)
		{
			s = " /$$$$$$$$";
		}
		else if (num == 2)
		{
			s = "|_____ $$/";
		}
		else if (num == 3)
		{
			s = "     /$$/ ";
		}
		else if (num == 4)
		{
			s = "    /$$/  ";
		}
		else if (num == 5)
		{
			s = "   /$$/   ";
		}
		else if (num == 6)
		{
			s = "  /$$/    ";
		}
		else if (num == 7)
		{
			s = " /$$/     ";
		}
		else if (num == 8)
		{
			s = "|__/      ";
		}
	}
	else if (c == '8')
	{
		if (num == 1)
		{
			s = "  /$$$$$$ ";
		}
		else if (num == 2)
		{
			s = " /$$__  $$";
		}
		else if (num == 3)
		{
			s = "| $$  \\ $$";
		}
		else if (num == 4)
		{
			s = "|  $$$$$$/";
		}
		else if (num == 5)
		{
			s = " >$$__  $$";
		}
		else if (num == 6)
		{
			s = "| $$  \\ $$";
		}
		else if (num == 7)
		{
			s = "|  $$$$$$/";
		}
		else if (num == 8)
		{
			s = " \\______/ ";
		}
	}
	else if (c == '9')
	{
		if (num == 1)
		{
			s = "  /$$$$$$ ";
		}
		else if (num == 2)
		{
			s = " /$$__  $$";
		}
		else if (num == 3)
		{
			s = "| $$  \\ $$";
		}
		else if (num == 4)
		{
			s = "|  $$$$$$$";
		}
		else if (num == 5)
		{
			s = " \\____  $$";
		}
		else if (num == 6)
		{
			s = " /$$  \\ $$";
		}
		else if (num == 7)
		{
			s = "|  $$$$$$/";
		}
		else if (num == 8)
		{
			s = " \\______/ ";
		}
	}
	else if (c == ':')
	{
		if (num == 1)
		{
			s = "    ";
		}
		else if (num == 2)
		{
			s = "    ";
		}
		else if (num == 3)
		{
			s = " /$$";
		}
		else if (num == 4)
		{
			s = "|__/";
		}
		else if (num == 5)
		{
			s = "    ";
		}
		else if (num == 6)
		{
			s = " /$$";
		}
		else if (num == 7)
		{
			s = "|__/";
		}
		else if (num == 8)
		{
			s = "    ";
		}
	}
	else if (c == 'A')
	{
		if (num == 1)
		{
			s = "  /$$$$$$ ";
		}
		else if (num == 2)
		{
			s = " /$$__  $$";
		}
		else if (num == 3)
		{
			s = "| $$  \\ $$";
		}
		else if (num == 4)
		{
			s = "| $$$$$$$$";
		}
		else if (num == 5)
		{
			s = "| $$__  $$";
		}
		else if (num == 6)
		{
			s = "| $$  | $$";
		}
		else if (num == 7)
		{
			s = "| $$  | $$";
		}
		else if (num == 8)
		{
			s = "|__/  |__/";
		}
	}
	else if (c == 'P')
	{
		if (num == 1)
		{
			s = " /$$$$$$$ ";
		}
		else if (num == 2)
		{
			s = "| $$__  $$";
		}
		else if (num == 3)
		{
			s = "| $$  \\ $$";
		}
		else if (num == 4)
		{
			s = "| $$$$$$$/";
		}
		else if (num == 5)
		{
			s = "| $$____/ ";
		}
		else if (num == 6)
		{
			s = "| $$      ";
		}
		else if (num == 7)
		{
			s = "| $$      ";
		}
		else if (num == 8)
		{
			s = "|__/      ";
		}
	}
	else if (c == 'M')
	{
		if (num == 1)
		{
			s = " /$$      /$$";
		}
		else if (num == 2)
		{
			s = "| $$$    /$$$";
		}
		else if (num == 3)
		{
			s = "| $$$$  /$$$$";
		}
		else if (num == 4)
		{
			s = "| $$ $$/$$ $$";
		}
		else if (num == 5)
		{
			s = "| $$  $$$| $$";
		}
		else if (num == 6)
		{
			s = "| $$\\  $ | $$";
		}
		else if (num == 7)
		{
			s = "| $$ \\/  | $$";
		}
		else if (num == 8)
		{
			s = "|__/     |__/";
		}
	}
	return s;
}                                                                                                                              
