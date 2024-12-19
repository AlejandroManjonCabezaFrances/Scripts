#ifndef PEPE_HPP
#define PEPE_HPP

#include <iostream>
#include <iomanip>

class Pepe
{
    private:

    public:
        Pepe();
        Pepe(const Pepe& constrCopy);
        Pepe& operator=(const Pepe& constrCopy);
        ~Pepe();
};

std::ostream& operator<<(std::ostream &output, const Pepe& constrCopy);

#endif
