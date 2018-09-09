#include "../inc/Type.hpp"
#include "../inc/Parser.hpp"
#include "../inc/Lexser.hpp"
#include "../inc/Execute.hpp"
#include <iostream>
#include "../inc/My_Exception.hpp"

int main(int argc, char *argv[]){
    Parser                  worker(argc, argv);
    Lexser                  analyse;
    Execute                 stack;
    std::list<struct pars>  lst;

    try{
      lst = worker.makeList();
      for (std::list<struct pars>::iterator it = lst.begin(); it != lst.end(); it++){
        if ((it->nline == true || it->comment) && it->command.empty()){
          continue;
        }
        analyse.input(it);
        stack.exec(it);
      }
      throw(My_Exception("Error exit()"));
    } catch (My_Exception& e){
      if (e.getMessage() != "exit")
        std::cout << e.getMessage() << std::endl;
    }
  return (0);
}
