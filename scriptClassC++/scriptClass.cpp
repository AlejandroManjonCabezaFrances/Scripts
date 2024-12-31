#include <iostream>
#include <fstream>
#include <string>
#include <algorithm> // Para std::transform
#include <filesystem> // Para std::filesystem::create_directories c++17

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

/**
 * Checkea si existe directorio "srcs" y lo crea a su altura jerárquica
*/
void    createFileCpp()
{
	std::filesystem::path srcsDir = std::filesystem::current_path() /".."/".."/"srcs";
	if (!std::filesystem::exists(srcsDir))
		std::filesystem::create_directories(srcsDir);
}

void   createClassCpp(std::string className)
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
	file << className << "::" << className << "(const " << className << "& constrCopy)\n{	\n}\n\n";	//Copy constructor
	file << className << "& " << className << "::operator=(const " << className << "& constrCopy)\n";	//Assigned operator
	file << "{\n    if (this != &constrCopy)\n    {\n\n    }\n\n    return (*this);\n}\n\n";
	file << className << "::" << "~" << className << "()\n" << "{\n" << "}\n";	//Destructor
} 

void createColorsHpp(std::string className)
{
    std::ofstream file("../../include/Colors.hpp");
    if (!file)
    {
        std::cerr << "Error creating Colors.hpp!" << std::endl;
        return;
    }

    file << "#ifndef COLORS_HPP\n";
    file << "#define COLORS_HPP\n\n";

    file << "/* ------- COLORS ------- */\n";
    file << "#define BLACK   \"\\x1B[30m\"\n";
    file << "#define RED     \"\\x1b[31m\"\n";
    file << "#define GREEN   \"\\x1b[32m\"\n";
    file << "#define YELLOW  \"\\x1b[33m\"\n";
    file << "#define BLUE    \"\\x1b[34m\"\n";
    file << "#define MAGENTA \"\\x1b[35m\"\n";
    file << "#define CYAN    \"\\x1b[36m\"\n";
    file << "#define WHITE   \"\\x1B[37m\"\n";
    file << "#define ORANGE  \"\\x1B[38;2;255;128;0m\"\n";
    file << "#define ROSE    \"\\x1B[38;2;255;151;203m\"\n";
    file << "#define LBLUE   \"\\x1B[38;2;53;149;240m\"\n";
    file << "#define LGREEN  \"\\x1B[38;2;17;245;120m\"\n";
    file << "#define GRAY    \"\\x1B[38;2;176;174;174m\"\n";
    file << "#define PURPLE  \"\\x1B[38;2;128;0;128m\"\n";
    file << "#define BROWN   \"\\x1B[38;2;165;42;42m\"\n";
    file << "#define PINK    \"\\x1B[38;2;255;192;203m\"\n";
    file << "#define LIME    \"\\x1B[38;2;0;255;0m\"\n";
    file << "#define INDIGO  \"\\x1B[38;2;75;0;130m\"\n";
    file << "#define TEAL    \"\\x1B[38;2;0;128;128m\"\n";
    file << "#define OLIVE   \"\\x1B[38;2;128;128;0m\"\n";
    file << "#define VIOLET  \"\\x1B[38;2;238;130;238m\"\n";
    file << "#define GOLD    \"\\x1B[38;2;255;215;0m\"\n";
    file << "#define SILVER  \"\\x1B[38;2;192;192;192m\"\n";
    file << "#define NAVY    \"\\x1B[38;2;0;0;128m\"\n";
    file << "#define MAROON  \"\\x1B[38;2;128;0;0m\"\n";
    file << "#define RESET   \"\\x1b[0m\"\n\n";

    file << "/* ------- EMOJIS ------- */\n";
    file << "#define HIGHFIVE \"🖐️\"\n\n";

    file << "/* ------- BACKGROUND COLORS ------- */\n";
    file << "#define BG_BLACK   \"\\x1B[40m\"\n";
    file << "#define BG_RED     \"\\x1B[41m\"\n";
    file << "#define BG_GREEN   \"\\x1B[42m\"\n";
    file << "#define BG_YELLOW  \"\\x1B[43m\"\n";
    file << "#define BG_BLUE    \"\\x1B[44m\"\n";
    file << "#define BG_MAGENTA \"\\x1B[45m\"\n";
    file << "#define BG_CYAN    \"\\x1B[46m\"\n";
    file << "#define BG_WHITE   \"\\x1B[47m\"\n";
    file << "#define BG_ORANGE  \"\\x1B[48;2;255;128;0m\"\n";
    file << "#define BG_PURPLE  \"\\x1B[48;2;128;0;128m\"\n";
    file << "#define BG_GRAY    \"\\x1B[48;2;176;174;174m\"\n\n";

    file << "/* -------  EFFECTS ------- */\n";
    file << "#define BOLD      \"\\x1b[1m\"    // Negrita\n";
    file << "#define DIM       \"\\x1b[2m\"    // Atenuado\n";
    file << "#define ITALIC    \"\\x1b[3m\"    // Cursiva\n";
    file << "#define UNDERLINE \"\\x1b[4m\"    // Subrayado\n";
    file << "#define BLINK     \"\\x1b[5m\"    // Parpadeo\n";
    file << "#define REVERSE   \"\\x1b[7m\"    // Invertir colores\n";
    file << "#define HIDDEN    \"\\x1b[8m\"    // Oculto\n";
    file << "#define STRIKETHROUGH \"\\x1b[9m\" // Tachado\n\n";

    file << "#endif\n";

    file.close();
}

int questionCreateSomeFile(std::string param)
{
    std::string input;
    int         flag;

    flag = 0;
    while (1)
    {
        std::cout << "Do you want the script to create a "<< param << "? yes/not" << std::endl;
        std::cin >> input;
        if (input == "yes" || input == "y")
        {
            flag = 1;
            return (flag);
        }
        else if (input == "not" || input == "n")
            return (flag);
    }
}

void	createMakefile(std::string className)
{
    int flag;
    flag = questionCreateSomeFile("Makefile");

    if (flag == 1)
    {
        std::ofstream file("../../Makefile");
        if (!file)
        {
            std::cerr << "Error creating Makefile!" << std::endl;
            return;
        }

        file << "NAME = a.out\n";
        file << "CC = c++\n";
        file << "CFLAGS = -Wall -Wextra -Werror -std=c++98\n";
        file << "SRCS = srcs/main.cpp srcs/" << className << ".cpp\n";  // Usar el nombre de la clase
        file << "DEBUG = -g3 -fsanitize=address\n";
        file << "OBJS = $(SRCS:srcs/%.cpp=objs/%.o)\n\n";
        file << "# Construction of the executable and update obj if necessary\n";
        file << "$(NAME): objs $(OBJS)\n";
        file << "\t$(CC) $(CFLAGS) $(DEBUG) $(OBJS) -o $(NAME)\n\n";
        file << "all: $(NAME)\n\n";
        file << "# Construction of object files (.o) from source files (.cpp)\n";
        file << "objs/%.o: srcs/%.cpp\n";
        file << "\t@$(CC) $(CFLAGS) -c $< -o $@\n\n";
        file << "objs:\n";
        file << "\t@mkdir -p objs/\n\n";
        file << "clean:\n";
        file << "\t@rm -rf objs\n\n";
        file << "fclean: clean\n";
        file << "\t@rm -f $(NAME)\n\n";
        file << "re: fclean all\n\n";
        file << ".PHONY: all clean fclean re\n";

        file.close();
    }
}

void    createMainCpp(std::string className)
{
    int flag;
    flag = questionCreateSomeFile("main.cpp");

    if (flag == 1)
    {
        std::ofstream file("../../srcs/main.cpp");
        if (!file)
        {
            std::cerr << "Error creating main.cpp!" << std::endl;
            return;
        }

        file << "#include \"../include/" << className << ".hpp\"\n\n";
        file << "int main()\n{\n\n";
        file << "    return (0);\n";
        file << "}\n";
    }
}

int main()
{
	std::string className;
	std::string classesNumber;
	int i;

    i = 0;
	classesNumber = howManyClasses();

	while (i < std::stoi(classesNumber))
	{
		std::cout << "Enter the class name: ";
		std::cin >> className;
		createClassHpp(className);
		createClassCpp(className);
		createColorsHpp(className);
		createMakefile(className);
        createMainCpp(className);
		std::cout << "File " << className << ".hpp, " << className << ".cpp and Colors.hpp created successfully!" << std::endl;
        std::cout << "Makefile and main.cpp, depends on your choice" << std::endl;
		i++;
	}

	return (0);
}
