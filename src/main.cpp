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
    std::list<std::string>  all_err;
    bool                    ex = false;

    try{
        lst = worker.makeList();
        if (argc > 1){
          for (std::list<struct pars>::iterator it = lst.begin(); it != lst.end(); it++){
              if ((it->nline == true || it->comment) && it->command.empty()){
                continue;
              }
            try{
              analyse.input(it);
            }catch (My_Exception& e){
              if (e.getMessage() != "exit")
                all_err.push_back(e.getMessage());
              else{
                ex = true;
                if (all_err.size() > 1)
                  throw(My_Exception("display"));
              }
            }
          }
          if (all_err.size() > 1){
            if (!ex)
              all_err.push_back("Error exit()");
            throw(My_Exception("display"));
          }
      }

      for (std::list<struct pars>::iterator it = lst.begin(); it != lst.end(); it++){
        if ((it->nline == true || it->comment) && it->command.empty()){
          continue;
        }
        analyse.input(it);
        stack.exec(it);
      }
      throw(My_Exception("Error exit()"));
    } catch (My_Exception& e){
      if (e.getMessage() == "display"){
        for (std::list<std::string>::iterator it = all_err.begin(); it != all_err.end(); it++){
          std::cout << (*it) << std::endl;
        }
      }
      else if (e.getMessage() != "exit")
        std::cout << e.getMessage() << std::endl;
    }
  return (0);
}
