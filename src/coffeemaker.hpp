/*
 * CoffeeMaker, Coffee compiler to Powdder bytecode readable by the Coffee Pot VM
 * Copyright (C) 2019 Coffee Developers
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef COFFEEMAKER_HPP_
#define COFFEEMAKER_HPP_

#include <string>
#include <coffee/coffeetypes.hpp>

#define COFFEE_MAKER // Used by implementing programs to detect presence of API
#define COFFEE_MAKER_VERSION "0.0.1"
#define POWDDER_MAGIC_NUMBER 0xC0FFEE

void _compiler_info(const std::string& text);
void _compiler_err(const std::string& text);

class CoffeeMaker {
private:
    bool brewing = false;
public:
    CoffeeMaker();
    /**
     * Start compiling a project into a .cup file
     */
    void brew(char *path, bool *develop);
    /**
     * Returns whether the CoffeeMaker::brew() method has been called.
     */
    bool is_brewing();
};

#endif /* COFFEEMAKER_HPP_ */
