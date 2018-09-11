#include "../inc/My_Exception.hpp"

My_Exception::My_Exception(const std::string m) : _msg(m){ }

My_Exception::My_Exception(My_Exception const & src){
  *this = src;
}

My_Exception & My_Exception::operator=(My_Exception const & rhs){
  this->_msg = rhs.getMessage();
  return (*this);
}

std::string My_Exception::getMessage() const {return(_msg);}
