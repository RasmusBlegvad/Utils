#include <chrono>
#include <ctime>
#include <functional>
#include <iostream>
#include <ostream>
#include <string>

namespace utils
{

/**
 * @brief Measures and prints the execution time of a given function or block of code.
 *
 * This inline function takes a callable object (function, lambda, etc.), executes it,
 * measures its execution time, and prints the duration in the specified time format.
 *
 * @param func A std::function object representing the code block to be timed
 * @param output_format The time unit for output. Valid values are:
 *                     - "milis" (default): milliseconds
 *                     - " sec": seconds
 *                     - "nano": nanoseconds
 * @param timed_block_name Optional name/description of the timed block for output identification
 *
 * @example
 *     // Example 1: Timing a lambda with default output (milliseconds)
 *     timer([]() {
 *         // Code to be timed
 *         for(int i = 0; i < 1000000; i++) { }
 *     });
 *
 *     // Example 2: Timing a function with custom name and time format
 *     timer(someFunction, "sec", "Matrix multiplication");
 *
 *
 *
 */
inline void timer(const std::function<void()> &func, const std::string &output_format = "milis",
                  const std::string &timed_block_name = "Code")
{

    long long duration = 0;
    const auto start_time = std::chrono::high_resolution_clock::now();
    func();
    const auto end_time = std::chrono::high_resolution_clock::now();

    if (output_format == "sec")
    {
        auto duration_seconds = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time);
        duration = duration_seconds.count();
        std::cout << "[" << "\"" << timed_block_name << "\"" << " execution time: " << duration << " seconds" << "]"
                  << std::endl;
        if (duration <= 1)
        {
            std::cout << "Friendly reminder: consider timing your code at a higher resolution";
        }
    }
    else if (output_format == "milis")
    {
        auto duration_second = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
        duration = duration_second.count();

        std::cout << "[" << "\"" << timed_block_name << "\"" << " execution time: " << duration << " miliseconds" << "]"
                  << std::endl;
    }
    else if (output_format == "nano")
    {
        auto duration_second = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
        duration = duration_second.count();
        std::cout << "[" << "\"" << timed_block_name << "\"" << " execution time: " << duration << " nanoseconds" << "]"
                  << std::endl;
    }
}

} // namespace utils
