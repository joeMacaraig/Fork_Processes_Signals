//forking.cpp 
//Using fork to create 10 processes

#include <sys/types.h> 
#include <unistd.h>
#include <iostream> 
#include <vector>

using namespace std; 

int main(){
  /*
  creates 8 processes... 2^n  n is the amount of forks called
  fork(); 
  fork(); 
  fork(); 
  */
  
  pid_t pid; 
  int n = 10; //number of processes
  vector<int> ids; 

  pid = fork(); //first fork

  for(int i = 0; i < n; i++){
    if (pid == 0){
      cout << "Processes " << i << " PPID: " << getppid() << " is the parent of processes " << i+1 << " PID: " << getpid() << endl;
      ids.push_back(getpid());
      pid = fork(); //without this it will print the same PID and PPID 10 times.
    }
  }

  while (n > 0){
    wait(NULL); 
    n--; //waits for all of n
  }
    return 0; 
}