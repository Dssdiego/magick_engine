//
// Created by Diego Santos Seabra on 02/02/21.
//

#include <iostream>
#include "log.h"

void Log::debug(const char *message)
{
    std::cout << WHITE << "DEBUG: " << message << RESET << std::endl;
}

void Log::info(const char *message)
{
    std::cout << BLUE << "INFO: " << message << RESET << std::endl;
}

void Log::warning(const char *message)
{
    std::cout << YELLOW << "WARN: " << message << RESET << std::endl;
}

void Log::error(const char *message)
{
    std::cout << RED << "ERROR: " << message << RESET << std::endl;
}
