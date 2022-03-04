//test_alarm.cpp

#include <signal.h> 
#include <unistd.h> 
#include <iostream>

using namespace std; 

//int raise(int sig); send a signal to itself
//int kill(pid_t pid, int sig); send a signal to another process and itself
//unsigned int alarm (unsigned int seconds); can send SIGALRM signal in the future


//simulates an alarm clock
void alarm_off(int sig){
  cout << "Alarm has gone off " << endl;  
}

//tells child process to wait for 5 sec. before sending a 
//SIGALRM signal to parent 

int main(){
  int pid; 
  
  cout << "Alarm testing!\n";

  if ((pid = fork() == 0)) {//child
    sleep(5);
    //get parent id, send SIGALRM signal to it
    kill(getppid(), SIGALRM);
    return 1; 
  }

  //parent process aranges to catch SIGALRM with call to 
  //signal and then waits for the inevitable

  cout << "Waiting for alarm to go off!" << endl; 
  (void) signal (SIGALRM, alarm_off);

  pause(); //process suspended, waiting for signals to wake up
  cout << "Done!" << endl;

  return 1;
  }