//test_signal.cpp
//man signal 

#include <signal.h> 
#include <unistd.h>
#include <iostream>

using namespace std; 

//in terminal: man signal for more info
//void (*signal(int sig, void(*func)(int)))(int);

void func (int sig) { //prints when ^C is pressed while program runs
  cout << "Oops! -- I got a signal " << sig << endl; 
}

int main(){
  (void) signal (SIGINT, func); //catch terminal interrupts 

  for(int i = 0; i < 20; i++){
    cout << "CSUSB CSE 4600 Operating Systems. Homework on signals" << endl; 
    sleep (1);
  }
  return 0; 
}