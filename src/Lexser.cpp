#include "../inc/Lexser.hpp"

Lexser::Lexser(){};

void Lexser::input(std:: list<struct pars>::iterator it){
      this->checkInput(it);
      if (it->command == "push" || it->command == "assert")
        this->getValue(it);
      if (it->command == "exit")
        throw(My_Exception("exit"));
}

void Lexser::checkInput(std:: list<struct pars>::iterator line) throw(My_Exception &){
  if (line->nline)
    return ;
  if ((line->err && !line->comment) ||
   ((line->command == "push" || line->command == "assert") && line->type.empty()) ||
   ((line->command != "push" && line->command != "assert") && !line->type.empty())){
    throw(My_Exception("Lexsical error"));
  }
  if (line->value.find(".") != std::string::npos && line->type != "float" && line->type != "double"){
    throw(My_Exception("Lexsical error"));
  }

}

void Lexser::getValue(std:: list<struct pars>::iterator line){
    this->typeError(line->type, line->value);
    if (line->type == "float"){
      line->floatValue = std::stof(line->value);
    } else if (line->type == "double"){
      line->doubleValue = std::stod(line->value);
    }
    else {
      line->intValue = std::stoi(line->value);
    }
}

void Lexser::typeError(std::string type, std::string value){
  int                     tmpInt;
  long long int           tmpLong;
  unsigned long long int  UtmpLong;
  std::string             tmp;

  if (type == "int32"){
    if (value.size() > 10 && value.at(0) != '-')
      throw(My_Exception("Overflow on a value int32"));
    else if (value.size() > 11 && value.at(0) == '-')
      throw(My_Exception("Underflow on a value int32"));
    tmpLong = std::stoll(value);
    if (tmpLong > 2147483647)
      throw(My_Exception("Overflow on a value int32"));
    else if (tmpLong + 1 < -2147483648 + 1)
      throw(My_Exception("Underflow on a value int32"));
  } else if (type == "float"){
    if (value.find(".") != std::string::npos)
      tmp = value.substr(0, value.find("."));
    else
      tmp = value;
    if (tmp.size() > 10 && value.at(0) != '-')
      throw(My_Exception("Overflow on a value float"));
    else if (tmp.size() < 11 && tmp.at(0) == '-')
      throw(My_Exception("Underflow on a value float"));
    tmpLong = std::stoll(tmp);
    if (tmpLong > 2147483647)
      throw(My_Exception("Overflow on a value float"));
    else if (tmpLong < -2147483648)
      throw(My_Exception("Underflow on a value float"));
  } else if (type == "double"){
    if (value.find(".") != std::string::npos)
      tmp = value.substr(0, value.find("."));
    else
      tmp = value;
    if (tmp.size() > 19 && value.at(0) != '-')
      throw(My_Exception("Overflow on a value float"));
    else if (tmp.size() < 20 && tmp.at(0) == '-')
      throw(My_Exception("Underflow on a value float"));
    if (tmp.at(0) != '-'){
     UtmpLong = std::stoull(tmp);
     if (UtmpLong > 9223372036854775807)
       throw(My_Exception("Overflow on a value double"));
   }
    else{
      UtmpLong = std::stoull(tmp.substr(1, tmp.find(".")));
      if (UtmpLong - 1 > 9223372036854775807)
        throw(My_Exception("Underflow on a value double"));
    }
  } else{
    if (value.size() > 9 && value.at(0) != '-')
      throw(My_Exception("Overflow on a value"));
    if (value.size() > 9 && value.at(0) == '-')
      throw(My_Exception("Underflow on a value"));
    tmpInt = std::stoi(value);
    if (type == "int8" and tmpInt > 127)
      throw(My_Exception("Overflow on a value int8"));
    else if (type == "int8" and tmpInt < -128)
      throw(My_Exception("Underflow on a value int8"));
    else if (type == "int16" and tmpInt > 32767)
      throw(My_Exception("Overflow on a value int16"));
    else if (type == "int16" and tmpInt < -32768)
      throw(My_Exception("Underflow on a value int16"));
  }
}
