//
// Created by Diego Santos Seabra on 02/02/21.
//

#include <iostream>
#include "log.h"

void Log::debug(const char *message)
{
#ifdef __APPLE__
    std::cout << WHITE << "DEBUG: " << message << RESET << std::endl;
#endif
}

void Log::info(const char *message)
{
#ifdef __APPLE__
    std::cout << BLUE << "INFO: " << message << RESET << std::endl;
#endif
}

void Log::warning(const char *message)
{
#ifdef __APPLE__
    std::cout << YELLOW << "WARN: " << message << RESET << std::endl;
#endif
}

void Log::error(const char *message)
{
#ifdef __APPLE__
    std::cout << RED << "ERROR: " << message << RESET << std::endl;
#endif
}
