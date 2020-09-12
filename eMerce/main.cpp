#include<iostream>
#include"System.h"

int main()
{
		System system("eMerce");

		std::cout << "Welcome to " << system.getName() << "\n";
		std::string systemFileName = system.getName();
		systemFileName += ".txt";
		system.loadSystem(systemFileName);
		system.iterativeMenu();
		system.saveSystem(systemFileName);
		std::cout << "Thank you for using " << system.getName() << "\n";
}