#include <iostream>
#include <fstream>
#include <string>
#include <algorithm> // Para std::transform
#include <filesystem> // Para std::filesystem::create_directories c++17

/**
 * Checkea si existe directorio "srcs" y lo crea a su altura jerárquica
*/
void    createFileCpp()
{
	std::filesystem::path srcsDir = std::filesystem::current_path() /".."/".."/"srcs";
	if (!std::filesystem::exists(srcsDir))
		std::filesystem::create_directories(srcsDir);
}

void   createCpp(std::string className)
{

	createFileCpp();

	std::ofstream file("../../srcs/" + className + ".cpp");
	if (!file)
	{
		std::cerr << "Error creating .cpp!" << std::endl;
		return;
	}

	file << "#include \"../include/" << className << ".hpp\"\n\n";
	file << className << "::" << className << "()\n" << "{\n" << "}\n\n";	//Constructor
	file << className << "::" << className << "()\n" << "{\n" << "}\n\n";	//Constructor parameter
	file << className << "::" << className << "(const " << className << "& constrCopy)\n{\n\n}\n\n";	//Copy constructor
	file << className << "& " << className << "::operator=(const " << className << "& constrCopy)\n";	//Assigned operator
	file << "{\n    if (this != &constrCopy)\n    {\n\n    }\n\n    return (*this);\n}\n\n";
	file << className << "::" << "~" << className << "()\n" << "{\n" << "}\n\n";	//Destructor
} 

/**
 * Checkea si existe directorio "include" y lo crea a su altura jerárquica
*/
void    createFileHpp()
{
	std::filesystem::path includeDir = std::filesystem::current_path() /".."/".."/"include";
	if (!std::filesystem::exists(includeDir))
		std::filesystem::create_directories(includeDir);
}

std::string	createClassHpp(std::string className)
{
	std::string classNameUpper = className;
	std::transform(classNameUpper.begin(), classNameUpper.end(), classNameUpper.begin(), ::toupper);

	createFileHpp();

	std::ofstream file("../../include/" + className + ".hpp");
	if (!file)
	{
		std::cerr << "Error creating .hpp!" << std::endl;
		return ("error");
	}

	file << "#ifndef " << classNameUpper << "_HPP\n";
	file << "#define " << classNameUpper << "_HPP\n\n";
	file << "#include <iostream>\n";
	file << "#include <iomanip>\n\n";
	file << "class " << className << "\n";
	file << "{\n";
	file << "    private:\n\n";
	file << "    public:\n";
	file << "        " << className << "();\n";
	file << "        " << className << "(const " << className << "& constrCopy);\n";
	file << "        " << className << "& operator=(const " << className << "& constrCopy);\n";
	file << "        ~" << className << "();\n";
	file << "};\n\n";
	file << "std::ostream& operator<<(std::ostream &output, const " << className << "& constrCopy);\n\n";
	file << "#endif\n";

	file.close();

	return (className);
}

std::string howManyClasses()
{
	std::string classesNumber;

	while (1)
	{
		std::cout << "Introduce el número de clases que quieres crear: " << std::endl;
		std::cin >> classesNumber;
		if (classesNumber.size() == 1 && classesNumber[0] >= '1' && classesNumber[0] <= '9')
			break;
	}
	return (classesNumber);
}

int main()
{
	std::string className;
	std::string classesNumber;
	int i;

	classesNumber = howManyClasses();

	while (i < std::stoi(classesNumber))
	{
		std::cout << "Enter the class name: ";
		std::cin >> className;
		createClassHpp(className);
		createCpp(className);
		std::cout << "Header file " << className << ".hpp and " << className << ".cpp created successfully!" << std::endl;
		i++;
	}

	return (0);
}
