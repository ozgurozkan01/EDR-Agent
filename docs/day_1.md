# EDR Agent Development - Day 1 Summary

## Accomplishments
Today we successfully built the foundation for a high-performance **Linux EDR Agent** using C++17 and CMake.

### 1. Thread-Safe Logger
- **Mechanism:** Used `std::mutex` with `std::lock_guard` for concurrent safety.
- **Optimization:** Employed `std::string_view` for zero-allocation logging.
- **Modern C++:** Used `inline static` for cleaner header-only variable definition.

### 2. Process Discovery via /proc
- **Implementation:** Used the low-level `<dirent.h>` API to scan the `/proc` virtual filesystem.
- **Path Resolution:** Utilized `readlink` to resolve absolute paths of running binaries.
- **Decision:** Chose `dirent` over `std::filesystem` for better performance and robustness in the ephemeral `/proc` environment.


