#ifndef EOPERANDTYPE_H
# define EOPERANDTYPE_H

#include <string>

enum eOperandType{
  int8_e = 1,
  int16_e = 2,
  int32_e = 3,
  float_e = 4,
  double_e = 5
};

struct pars{
  std::string   command;
  std::string   type;
  std::string   value;
  int           intValue;
  float         floatValue;
  double        doubleValue;
  bool          err = false;
  bool          comment = false;
  bool          nline = false;
  bool          end = false;
};

#endif
