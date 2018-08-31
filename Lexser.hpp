#ifndef LEXSER_H
# define LEXSER_H

#include <string>
#include <iostream>
#include <list>
#include "eOperandType.hpp"
#include "My_Exception.hpp"

class Lexser{
  public:
    Lexser();
    void input(std:: list<struct pars>::iterator line);

  private:
    void checkInput(std::list<struct pars>::iterator line) throw(My_Exception &);
    void getValue(std:: list<struct pars>::iterator line);
    void typeError(std::string type, std::string value);

};

#endif
