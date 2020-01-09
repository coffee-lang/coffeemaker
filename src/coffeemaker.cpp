/*
 * Copyright (c) 2019-present Bowser65 & vinceh121, All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its contributors
 *    may be used to endorse or promote products derived from this software without
 *    specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "coffeemaker.hpp"

#include <stdexcept>
#include <cstdarg>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <fstream> //XXX: eclipse removes this one at optimization

bool quiet = false;
bool isDevelop = false;

void _compiler_info(const std::string& text) {
    if (quiet)
        return;
    std::cout << text << std::endl;
}

void _compiler_err(const std::string& text) {
    if (quiet)
        return;
    std::cerr << text << std::endl;
}

CoffeeMaker::CoffeeMaker() {

}

bool CoffeeMaker::is_brewing(){
    return brewing;
}

void CoffeeMaker::brew(char *path, bool *develop){
    if (brewing) {
        throw std::runtime_error("Tried to start a compiler that is already started");
    }
}

void print_license() {
    std::cout
            << "CoffeeMaker, Coffee compiler to Powdder bytecode readable by the Coffee Pot VM \n\
    Copyright (C) 2019 Coffee Developers \n\
 \n\
    This program is free software: you can redistribute it and/or modify \n\
    it under the terms of the GNU Affero General Public License as \n\
    published by the Free Software Foundation, either version 3 of the \n\
    License, or (at your option) any later version. \n\
 \n\
    This program is distributed in the hope that it will be useful, \n\
    but WITHOUT ANY WARRANTY; without even the implied warranty of \n\
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the \n\
    GNU Affero General Public License for more details. \n\
 \n\
    You should have received a copy of the GNU Affero General Public License \n\
    along with this program.  If not, see <https://www.gnu.org/licenses/>."
            << std::endl;
}

void print_help() {
    std::cout << "CoffeeMaker Compiler v" << COFFEE_MAKER_VERSION << std::endl;
    std::cout << "coffeemaker [options] PATH" << std::endl;
    std::cout << "-- General Options" << std::endl;
    std::cout << "\t-q, --quiet\tPrevents the compiler from printing to stdout and stderr." << std::endl;
    std::cout << "-- Compiler Options" << std::endl;
    std::cout << "\t-d, --dev\tTells the compiler to build in development mode." << std::endl;
    std::cout << "-- About CoffeeMaker" << std::endl;
    std::cout << "\t-h, --help\tShows this help page" << std::endl;
    std::cout << "\t-v, --version\tPrints version information and exists." << std::endl;
    std::cout << "\t--license\tPrints the program's license and exists." << std::endl;
    std::exit(0);
}

void unknown_arg(char *arg) {
    _compiler_err("Unknown argument \"" + std::string(arg) + "\"");
    std::exit(-1);
}

int main(int argc, char **argv) {
    if (argc <= 1)
        print_help();
    CoffeeMaker *maker = new CoffeeMaker();

    if (argc > 2) {
        for (int i = 1; i < argc - 1; i++) {
            if (strcmp("-h", argv[i]) == 0 || strcmp("--help", argv[i]) == 0) {
                print_help();
            } else if (strcmp("-v", argv[i]) == 0 || strcmp("--version", argv[i]) == 0) {
                std::cout << "CoffeeMaker Compiler v" << COFFEE_MAKER_VERSION << std::endl;
                std::exit(0);
            } else if (strcmp("--license", argv[i]) == 0) {
                print_license();
                std::exit(0);
            } else if (strcmp("--quiet", argv[i]) == 0 || strcmp("-q", argv[i]) == 0) {
                quiet = true;
            } else if (strcmp("--dev", argv[i]) == 0 || strcmp("-d", argv[i]) == 0) {
                isDevelop = true;
            } else {
                unknown_arg(argv[i]);
            }
        }
    }

    maker->brew(argv[argc - 1], &isDevelop);
    return 0;
}
