#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

int main(){
  timeval curTime;
  gettimeofday(&curTime, NULL);
  int milli = curTime.tv_usec / 1000;

  time_t rawtime;
  struct tm * timeinfo;
  char buffer [80];

  time(&rawtime);
  timeinfo = localtime(&rawtime);

  strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", timeinfo);

  char currentTime[84] = "";
  sprintf(currentTime, "%s:%d", buffer, milli);
  printf("current time: %s \n", currentTime);

  usleep(20000);
  timeval curTime1;
  gettimeofday(&curTime1, NULL);
  int milli1 = curTime1.tv_usec / 1000;

  printf("time difference =  %d\n",milli1-milli);


  return 0;
}
