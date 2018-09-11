#ifndef MY_EXCEPTION_H
# define MY_EXCEPTION_H

#include <exception>
#include <string>

class My_Exception : public std::exception{
  public:
    My_Exception(const std::string m);
    My_Exception(My_Exception const & src);
    My_Exception & operator=(My_Exception const & rhs);
    std::string getMessage() const;

  private:
    std::string _msg;
};

#endif
