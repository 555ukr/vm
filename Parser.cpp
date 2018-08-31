#include "Parser.hpp"

Parser::Parser(int input, char *file[]){
  if (input == 1)
    this->_input = 1;
}

std::list<struct pars> Parser::makeList(){
  std::list<struct pars> tmp;
  struct pars *line;

  while(1){
    line = this->getLine();
    if (line->end == true){
      delete line;
      break;
    }
    tmp.push_back(*line);
    delete line;
  }
  return tmp;
}

struct pars * Parser::getLine(){
  std::string line;
  struct pars *tmp = new struct pars;
  std::regex primary ("(^ *(push|pop|dump|assert|add|sub|mul|div|mod|print|exit) *(((int8|int16|int32|float|double)\\(([-]?[0-9]+(.[0-9]+)?)\\))?( *)(;.*)?))|( *;.*)");

  if (_input == 1){
    std::getline (std::cin, line);
    if (line.empty()){
      tmp->nline = true;
      return tmp;
    }
    if (!regex_match(line, primary)){
      tmp->err = true;
      return tmp;
    }
    delete tmp;
    return this->parse(line);
  }
  //TODO read from file
  delete tmp;
  return this->parse(line);
}

struct pars * Parser::parse(std::string line){
  struct pars * tmp = new struct pars;
  std::regex command ("(push|pop|dump|assert|add|sub|mul|div|mod|print|exit)");
  std::regex type ("(int8|int16|int32|float|double)");
  std::regex val ("(\\([-]?[0-9]+(.[0-9]+)?+\\))");
  std::regex comment("( *;.*)");
  std::regex end(" *;;(( +;.*)|( *))");
  std::regex_iterator<std::string::iterator> rend;

  std::regex_iterator<std::string::iterator> com ( line.begin(), line.end(), command);
  if (std::distance(com, rend) != 0)
    tmp->command = com->str();
  else
    tmp->err = true;

  std::regex_iterator<std::string::iterator> tp ( line.begin(), line.end(), type);
  if (std::distance(tp, rend) != 0)
    tmp->type = tp->str();

  std::regex_iterator<std::string::iterator> vl ( line.begin(), line.end(), val);
  if (std::distance(vl, rend) != 0){
    tmp->value = vl->str();
    tmp->value = tmp->value.substr(1, tmp->value.size() - 2);
  }

  std::regex_iterator<std::string::iterator> comme ( line.begin(), line.end(), comment);
  if (std::distance(comme, rend) != 0)
    tmp->comment = true;

  std::regex_iterator<std::string::iterator> finish ( line.begin(), line.end(), end);
  if (std::distance(finish, rend) != 0)
    tmp->end = true;
  return tmp;
}
