#ifndef PROCESS_HELPER_HPP
#define PROCESS_HELPER_HPP

#include <sys/types.h>
#include <string>
#include <vector>

struct ProcessInfo {
    pid_t pid;
    pid_t ppid;
    std::string name;
    std::string path;
};

class ProcessHelper {
public:
    static std::vector<ProcessInfo> GetAllProcesses();
};

#endif
