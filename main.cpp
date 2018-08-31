#include "Type.hpp"
#include "Parser.hpp"
#include "Lexser.hpp"
#include "Execute.hpp"
#include <iostream>
#include "My_Exception.hpp"

int main(int argc, char *argv[]){
  eOperandType tmp = int8_e;
  //Type <int8_t> test(tmp, 4);
  Type <int8_t> test1(tmp, 8);
    // Parser                  worker(argc, argv);
    // Lexser                  analyse;
    // Execute                 stack;
    // std::list<struct pars>  lst;
    //
    // lst = worker.makeList();
    // try{
    //   for (std::list<struct pars>::iterator it = lst.begin(); it != lst.end(); it++){
    //     if (it->nline == true){
    //       lst.erase(it);
    //     }
    //     analyse.input(it);
    //     stack.exec(it);
    //   }
    //   stack.loop();
    // } catch (My_Exception& e){
    //   std::cout << e.getMessage() << std::endl;
    // }
  return (0);
}
