#ifndef EXECUTE_H
# define EXECUTE_H

#include <list>
#include <map>
#include <string>
#include <iomanip>
#include "Type.hpp"
#include "IOperand.hpp"
#include "eOperandType.hpp"
#include "My_Exception.hpp"


class Execute{
public:
  Execute();
  ~Execute();
  void exec(std:: list<struct pars>::iterator line);
  void loop();
  void clean();
  void pop();
  void assert(std:: list<struct pars>::iterator line);
  void add();
  void sub();
  void mul();
  void div();
  void mod();
  void print();

private:
  std::list<const IOperand *> _lst;

  IOperand const * _createOperand(eOperandType type, std::string const & value )const;
  IOperand const * _createInt8(std::string const & value )const;
  IOperand const * _createInt16(std::string const & value )const;
  IOperand const * _createInt32(std::string const & value )const;
  IOperand const * _createFloat(std::string const & value )const;
  IOperand const * _createDouble(std::string const & value )const;

};

#endif
