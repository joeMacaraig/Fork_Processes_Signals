#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std; 

int main(){

  pid_t pid, pid_2;
  const char *message; 
  int n; 
  int exit_code; 

  cout << "fork program starting\n";
  pid = fork();
  switch(pid){
    case -1: 
      cout << "Fork failure!\n";
      return 1; 
    case 0: 
      message = "This is the child\n";
      n = 5; 
      exit_code = 9;
      break;
    default:
      message = "This is the parent\n";
      n = 3; 
      exit_code = 0; 
      break; 
  }

  for(int i = 0; i < n; i++){
    cout << message; 
    sleep (1);
  }

  //waiting for child to finish
  if (pid != 0) {
    int stat_val; //parent
    pid_t child_pid, gchild_pid;
    pid_2 = fork();
    child_pid = wait (&stat_val); //wait for child
    gchild_pid = wait (&stat_val); //wait for grandchild
    cout << "Child is finished: PID = " << child_pid << endl; 
    if (WIFEXITED (stat_val)){
      cout << "child exited with code " << WEXITSTATUS (stat_val) << endl; 
    } else {
      cout << "child is terminated abnormally!" << endl; 
    }
    if (pid_2 == 0){
      cout << "grandchild PID :" << getpid() << endl; //prints grandchild pid
      cout << "parent PID :" << child_pid << endl; //prints parent pid
      cout << "grandparent PID :" << getpgid(pid); //prints the pid of grandparents 
    }    
    exit (exit_code); 
  }
  return 0;
}

  /*if (pid == 0){//grandchild
    int val; //child
    pid_t gchild_pid;
    gchild_pid = wait (&val);//wait for grandchild
    pid_2 = fork(); 
    if (pid_2 == 0){
      cout << "grandchild PID :" << getpid() << endl; //prints grandchild pid
      cout << "parent PID :" << getppid() << endl; //prints parent pid
      cout << "grandparent PID :" << getpgid(pid); //prints the pid of grandparents 
    }
  }*/