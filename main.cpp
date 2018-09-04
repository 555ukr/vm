#include "Type.hpp"
#include "Parser.hpp"
#include "Lexser.hpp"
#include "Execute.hpp"
#include <iostream>
#include "My_Exception.hpp"

int main(int argc, char *argv[]){
  // eOperandType tmp = int8_e;
  // Type <float> test(tmp, 3.5);
  // Type <float> test1(tmp, 8.7);
  // Type <float> const * lol = reinterpret_cast<Type <float> const *>(test1 % test);
  //
  // std::cout << test.getValue() << std::endl;
    Parser                  worker(argc, argv);
    Lexser                  analyse;
    Execute                 stack;
    std::list<struct pars>  lst;

    lst = worker.makeList();
    try{
      for (std::list<struct pars>::iterator it = lst.begin(); it != lst.end(); it++){
        if (it->nline == true){
          lst.erase(it);
        }
        analyse.input(it);
        stack.exec(it);
      }
      stack.loop();
    } catch (My_Exception& e){
      std::cout << e.getMessage() << std::endl;
      std::cout << "lol" << std::endl;
    }
    std::cout << "lol2" << std::endl;
  return (0);
}
