#include "Logger.hpp"
Logger::Logger(void) : _logfile(NULL)
{
    return;
}

Logger::Logger(const char* file)
{
    _logfile.open(file, std::ios::trunc);

    if (!(_logfile.is_open()))
    {
        std::cerr << "Couldn't open file: " << file << std::endl;
        this->~Logger();
    }
}

Logger::Logger(const std::string & file)
{
    _logfile.open(file, std::ios::trunc);

    if (!(_logfile.is_open()))
    {
        std::cerr << "Couldn't open file: " << file << std::endl;
        this->~Logger();
    }
}

Logger::~Logger(void)
{
    if (_logfile.is_open())
        _logfile.close();
}

bool    Logger::open(const char * file)
{
    _logfile.open(file, std::ios::trunc);

    if (!(_logfile.is_open()))
    {
        std::cerr << "Couldn't open file: " << file << std::endl;
        return false;
    }
    return true;
}

bool    Logger::open(const std::string & file)
{
    _logfile.open(file, std::ios::trunc);

    if (!(_logfile.is_open()))
    {
        std::cerr << "Couldn't open file: " << file << std::endl;
        return false;
    }
    return true;
}