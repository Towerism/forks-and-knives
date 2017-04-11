#include <fstream>
#include <getopt.h>
#include <iostream>
#include <sstream>
#include <unistd.h>

void print_license() {
  std::cout << "forks-and-knives Copyright (C) 2017 Martin Fracker\n"
            << "This program comes with ABSOLUTELY NO WARRANTY.\n"
            << "This is free software, and you are welcome to redistribute it\n"
            << "under certain conditions. Type `show' for details.\n";
}

void print_usage(const char *program_name) {
  std::cerr << "Usage: " << program_name << " [--knives|-k]\n";
}

void run_shell() {
  print_license();
  std::cout << "::> ";
  std::string str;
  std::cin >> str;
  std::ifstream license("LICENSE");
  while (std::getline(license, str)) {
    std::cout << str << std::endl;
  }
}

enum class Status_code { Minus_knives, Shell, Error };

Status_code parse_args(int argc, char *argv[]) {
  while (true) {
    static struct option long_options[] = {{"knives", no_argument, NULL, 'k'},
                                           {0, 0, 0, 0}};

    int option_index = 0;
    int c = getopt_long(argc, argv, "k", long_options, &option_index);
    if (c == -1)
      return Status_code::Error;
    switch (c) {
    case 'k':
      return Status_code::Minus_knives;
    case '?':
      return Status_code::Error;
    }
  }
  return Status_code::Shell;
}

void run_without_knives(std::string str) {
  std::ostringstream oss;
  oss << str << " -k";
  for (;;) system(oss.str().c_str());
}

int main(int argc, char *argv[]) {
  auto status = parse_args(argc, argv);
  switch (status) {
  case Status_code::Minus_knives:
    run_without_knives(argv[0]);
    return 0;
  case Status_code::Error:
    print_usage(argv[0]);
    return 1;
  default:
  case Status_code::Shell:
    break;
  }
  run_shell();
  return 0;
}
