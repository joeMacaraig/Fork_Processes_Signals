//test_exec.cpp

//man execl 
//seeing the difference with execlp and execl

#include <unistd.h>
#include <iostream>

using namespace std; 

int main(){
  cout << "running ps with execl\n";
  //cout << "running ps with execlp\n";
  //execlp("ps", "ps", "-ax", 0); prints running ps with execlp and prints PID, TTY, TIME, CMD and not last print
  execl("ps", "ps", "-ax", 0); //prints running ps with execl and the program is exiting

  
  cout << "The program is exiting!\n";

  return 0;
}