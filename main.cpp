#include <iostream>
#include <fstream>
#include <unistd.h>
#include <getopt.h>

void print_license() {
  std::cout
    << "forks-and-knives Copyright (C) 2017 Martin Fracker\n"
    << "This program comes with ABSOLUTELY NO WARRANTY.\n"
    << "This is free software, and you are welcome to redistribute it\n"
    << "under certain conditions. Type `show' for details.\n";
}

void print_usage(const char* program_name) {
  std::cerr << "Usage: " << program_name << " [--knives|-k]\n";
}

int main(int argc, char *argv[])
{
  while (true) {
    static struct option long_options[] =
      {
        {"knives", no_argument, NULL, 'k'},
        {0, 0, 0, 0}
      };

    int option_index = 0;
    int c = getopt_long(argc, argv, "k", long_options, &option_index);
    if (c == -1)
      break;
    switch (c) {
    case 'k':
      std::cout << "Fork bomb\n";
      return 0;
    case '?':
      print_usage(argv[0]);
      return 1;
    }
  }

  print_license();
  std::cout << "::> ";
  std::string str;
  std::cin >> str;
  std::ifstream license("LICENSE");
  while(std::getline(license, str)) {
    std::cout << str << std::endl;
  }
  return 0;
}
