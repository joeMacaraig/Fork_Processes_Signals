// test_signal.cpp modified
// man sigaction

#include <signal.h>
#include <unistd.h>
#include <iostream>

using namespace std;

void func(int sig) 
{
  if (sig == SIGINT) //if ^c is hit it will print
    cout << "Oops! -- I got a signal " << sig << endl;
}

int main()
{
  struct sigaction s_a; //declaring sigaction;

  sigemptyset(&s_a.sa_mask); //calling the sigemptyset
  s_a.sa_handler = func; //declating handler to the function func

  while(1){ //changed to while instead of for loop
    cout << "CSUSB CSE 4600 Operating Systems. Homework on signals" << endl; 
    sleep (1);  
    if (sigaction(SIGINT, &s_a, NULL) == -1){ //calls the func and prints out "Oops..."
      perror("SIGACTION");
    }
    //can stop the while loop using ^\ 
  }
  return 0;
}