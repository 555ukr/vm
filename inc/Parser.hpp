#ifndef PARSER_H
# define PARSER_H

#include <string>
#include <iostream>
#include <fstream>
#include <regex>
#include "eOperandType.hpp"
#include "Execute.hpp"
#include <list>
/*
  char input = 1 read from standart input;
  char input = 2 read from file;
 */
class Parser{

public:
  Parser(int input, char *file[]);
  ~Parser();
  struct pars * getLine();
  std::list<struct pars> makeList();

private:
  struct pars * parse(std::string line);
  void          valuePars(struct pars *tmp);

  int            _input;
  std::ifstream    myfile;
};

#endif
