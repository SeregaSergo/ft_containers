#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <iostream>
#include <fstream>
#include <sstream>

class Logger {

private:
    std::ofstream _logfile;

    Logger(Logger const & src);
    Logger & operator=(Logger const & src);

public:
    Logger(void);
    Logger(const char * file);
    Logger(const std::string & file);
    ~Logger(void);

    bool    open(const char * file);
    bool    open(const std::string & file);

    template <class T>
    Logger& operator<<(const T& out)
    {
        std::cout << out;
        if (_logfile)
            _logfile << out;
        return *this;
    }
};

#endif