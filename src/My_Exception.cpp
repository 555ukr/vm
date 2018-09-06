#include "../inc/My_Exception.hpp"

My_Exception::My_Exception(const std::string m) : _msg(m){ }

std::string My_Exception::getMessage() const {return(_msg);}
