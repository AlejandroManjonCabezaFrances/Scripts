#include <iostream>
#include <fstream>
#include <string>
#include <algorithm> // Para std::transform

/* int main()
{
    std::string className;
    std::cout << "Enter the class name: ";
    std::cin >> className;

    // Convertir className a mayúsculas para las guardas de inclusión
    std::string classNameUpper = className;
    std::transform(classNameUpper.begin(), classNameUpper.end(), classNameUpper.begin(), ::toupper);

    std::ofstream file(className + ".hpp");
    if (!file)
    {
        std::cerr << "Error creating file!" << std::endl;
        return (1);
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
    std::cout << "Header file " << className << ".hpp created successfully!" << std::endl;

    return (0);
} */

void   createCpp(std::string className)
{
	std::ofstream file(className + ".cpp");
	if (!file)
    {
        std::cerr << "Error creating .cpp!" << std::endl;
    }

	file << "#include \"../include/" << className << ".hpp\n\n";
	file << className << "::" << className << "()\n" << "{\n" << "}\n\n";	//Constructor
	file << className << "::" << className << "()\n" << "{\n" << "}\n\n";	//Constructor parameter
	file << className << "::" << "~" << className << "()\n" << "{\n" << "}\n\n";	//Destructor
	file << className << "::" << className << "(const " << className << "& constrCopy)\n{\n\n}";	//Copy constructor
	file << className << "& " << className << "::operator=(const " << className << "& constrCopy)\n";	//Assigned operator
	file << "{\n    if (this != &constrCopy)\n    {\n\n    }\n\n    return (*this);\n}\n";

} 

std::string	createClassHpp()
{
    std::string className;
    std::cout << "Enter the class name: ";
    std::cin >> className;

    // Convertir className a mayúsculas
    std::string classNameUpper = className;
    std::transform(classNameUpper.begin(), classNameUpper.end(), classNameUpper.begin(), ::toupper);

    std::ofstream file(className + ".hpp");
    if (!file)
    {
        std::cerr << "Error creating .hpp!" << std::endl;
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
    std::cout << "Header file " << className << ".hpp created successfully!" << std::endl;

    return (className);
}

int main()
{
    std::string className;

    className = createClassHpp();
    createCpp(className);
    return (0);
}



