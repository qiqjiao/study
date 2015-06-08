#include <unistd.h>
#include <sys/prctl.h>
#include <signal.h>

#include <iostream>

int main()
{
    if (fork() == 0) {
      // with this the child will exit when parent exists. or the child's parent
      // will be set to 0 when parent exists, and will exit until it finishes.
      prctl(PR_SET_PDEATHSIG, SIGHUP);
      std::cout << "child start" << std::endl;
      // process name will be 'mysleep'
      execl("/bin/sleep", "mysleep", "15", 0);
      std::cout << "child exit" << std::endl;
    }
    sleep(5);
    std::cout << "main exit" << std::endl;
    return 0;
}
