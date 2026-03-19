#include "Linux/ProcessHelper.hpp"
#include "Logger.hpp"
#include <dirent.h>
#include <algorithm>
#include <unistd.h>
#include <fstream>
#include <climits>

std::vector<ProcessInfo> ProcessHelper::GetAllProcesses()
{
    std::vector<ProcessInfo> processList;
    DIR* dir = opendir("/proc");

    if (!dir) {
        Logger::Log(LogLevel::ERROR, "/proc folder could not be opened!");
        return processList;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != nullptr) {
        std::string pidStr = entry->d_name;
        if (entry->d_type == DT_DIR && std::all_of(pidStr.begin(), pidStr.end(), ::isdigit)) {
            
            ProcessInfo info;
            info.pid = std::stoi(pidStr);
            
            char pathBuf[PATH_MAX];
            std::string exePath = "/proc/" + pidStr + "/exe";
            
            ssize_t len = readlink(exePath.c_str(), pathBuf, sizeof(pathBuf) - 1);
            if (len != -1) {
                pathBuf[len] = '\0'; 
                info.path = pathBuf;
            } else {
                info.path = "[N/A]";
            }

            std::string commPath = "/proc/" + pidStr + "/comm";
            std::ifstream commFile(commPath);
            if (commFile.is_open()) {
                std::getline(commFile, info.name);
            } else {
                info.name = "[Unknown]";
            }

            info.ppid = 0;

            processList.push_back(info);
        }
    }

    closedir(dir);
    return processList;
}