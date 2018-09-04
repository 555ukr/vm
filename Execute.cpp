#include "Execute.hpp"

Execute::Execute(){}

Execute::~Execute(){
  this->clean();
}

void Execute::exec(std:: list<struct pars>::iterator line){
  std::map <std::string, eOperandType> myMap = {
    {"int8", int8_e},
    {"int16", int16_e},
    {"int32", int32_e},
    {"float", float_e},
    {"double", double_e}
  };
  if (line->command == "push"){
    this->_lst.push_front(this->_createOperand(myMap[line->type], line->value));
  }
  else if (line->command == "dump"){
    this->loop();
  } else if (line->command == "pop"){
    this->pop();
  }else if(line->command == "assert"){
    this->assert(line);
  }else if(line->command == "add"){
    this->add();
  }else if(line->command == "sub"){
    this->sub();
  }else if(line->command == "mul"){
    this->mul();
  }else if(line->command == "div"){
    this->div();
  }else if(line->command == "mod"){
    this->mod();
  }else if(line->command == "print"){
    this->print();
  }
}

void Execute::mul(){
  IOperand const * first;
  IOperand const * second;

  if (_lst.size() < 2){
    throw(My_Exception("Stack is less then 2 mul()"));
  }
  first = this->_lst.front();
  this->_lst.pop_front();
  second = this->_lst.front();
  this->_lst.pop_front();
  this->_lst.push_front(*first * *second);
  delete first;
  delete second;
}

void Execute::mod(){
  IOperand const * first;
  IOperand const * second;

  if (_lst.size() < 2){
    throw(My_Exception("Stack is less then 2 mod()"));
  }
  first = this->_lst.front();
  this->_lst.pop_front();
  second = this->_lst.front();
  this->_lst.pop_front();
  if (second->getValue() == "0" || second->getValue() == "0.00"){
    delete first;
    delete second;
    throw(My_Exception("Stack error div on 0 mod()"));
  }
  this->_lst.push_front(*first % *second);
  delete first;
  delete second;
}

void Execute::div(){
  IOperand const * first;
  IOperand const * second;

  if (_lst.size() < 2){
    throw(My_Exception("Stack is less then 2 div()"));
  }
  first = this->_lst.front();
  this->_lst.pop_front();
  second = this->_lst.front();
  this->_lst.pop_front();
  if (second->getValue() == "0" || second->getValue() == "0.00"){
    delete first;
    delete second;
    throw(My_Exception("Stack error div on 0 div()"));
  }
  this->_lst.push_front(*first / *second);
  delete first;
  delete second;
}

void Execute::sub(){
  IOperand const * first;
  IOperand const * second;

  if (_lst.size() < 2){
    throw(My_Exception("Stack is less then 2 sub()"));
  }
  first = this->_lst.front();
  this->_lst.pop_front();
  second = this->_lst.front();
  this->_lst.pop_front();
  this->_lst.push_front(*first - *second);
  delete first;
  delete second;
}

void Execute::add(){
  IOperand const * first;
  IOperand const * second;

  if (_lst.size() < 2){
    throw(My_Exception("Stack is less then 2 add()"));
  }
  first = this->_lst.front();
  this->_lst.pop_front();
  second = this->_lst.front();
  this->_lst.pop_front();
  this->_lst.push_front(*first + *second);
  delete first;
  delete second;
}

void Execute::assert(std:: list<struct pars>::iterator line){
  IOperand const * tmp;

  std::map <std::string, eOperandType> myMap = {
    {"int8", int8_e},
    {"int16", int16_e},
    {"int32", int32_e},
    {"float", float_e},
    {"double", double_e}
  };
  if (_lst.size() < 1){
    throw(My_Exception("Stack empty assert()"));
  }
  tmp = this->_createOperand(myMap[line->type], line->value);
  if (!(*tmp == **(_lst.begin())))
    throw(My_Exception("Not equel error assert()"));
  delete tmp;
}

void Execute::print(){
  IOperand const * tmp;
  Type <int8_t> * ascii;

  if (_lst.size() < 1){
    throw(My_Exception("Stack empty print()"));
  }
  tmp = *(_lst.begin());
  if (tmp->getType() != 1)
    throw(My_Exception("Not 8-bit integer print()"));
  else{
    ascii = (tmp);
    std::cout << ascii->rtValue << std::endl;
  }
}

void Execute::pop(){
  if (_lst.size() < 1){
    throw(My_Exception("Stack empty pop()"));
  }
  delete (_lst.front());
  _lst.erase(_lst.begin());
}

void Execute::clean(){
  for (std::list<const IOperand *>::iterator l = this->_lst.begin(); l != this->_lst.end(); ++l){
    delete (*l);
  }
}

void Execute::loop(){
  eOperandType f = float_e;
  eOperandType d = double_e;

  for (std::list<const IOperand *>::iterator l = this->_lst.begin(); l != this->_lst.end(); ++l){
    if ((*l)->getType() == f || (*l)->getType() == d)
      std::cout << std::fixed << std::setprecision(3) << (*l)->getValue() << std::endl;
    else
      std::cout << (*l)->getValue() << std::endl;
  }
}

IOperand const * Execute::_createOperand(eOperandType type, std::string const & value )const{
  typedef IOperand const *(Execute::*myfunc)(std::string const &)const;

  std::map <eOperandType, myfunc> myMap = {
    {int8_e, &Execute::_createInt8},
    {int16_e, &Execute::_createInt16},
    {int32_e, &Execute::_createInt32},
    {float_e, &Execute::_createFloat},
    {double_e, &Execute::_createDouble}
  };
  myfunc fct = myMap[type];
  return (this->*fct)(value);
}

IOperand const * Execute::_createInt8(std::string const & value )const{
  eOperandType tmp = int8_e;

  return new Type<int8_t> (tmp, std::stoi(value));
}

IOperand const * Execute::_createInt16(std::string const & value )const{
  eOperandType tmp = int16_e;

  return new Type<int16_t> (tmp, std::stoi(value));
}

IOperand const * Execute::_createInt32(std::string const & value )const{
  eOperandType tmp = int32_e;

  return new Type<int32_t> (tmp, std::stoi(value));
}

IOperand const * Execute::_createFloat(std::string const & value )const{
  eOperandType tmp = float_e;

  return new Type<float> (tmp, std::stof(value));
}

IOperand const * Execute::_createDouble(std::string const & value )const{
  eOperandType tmp = double_e;

  return (new Type<double> (tmp, std::stod(value)));
}
