#ifndef MY_EXCEPTION_H
# define MY_EXCEPTION_H

#include <exception>
#include <string>

class My_Exception : public std::exception{
  public:
    My_Exception(const std::string m);
    std::string getMessage() const;

  private:
    std::string _msg;
};

#endif
