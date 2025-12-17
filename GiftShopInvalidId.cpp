
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#define file "./misc_files/invalid_ids.txt"

void read_file() {
  std::ifstream inf{file};

  if (!inf) {
    std::cerr << "encountered some error while opening file";
    return;
  }

  std::string strInput{};
  while (inf >> strInput) {

    // std::cout << strInput[i] << "\n";
    size_t start = 0;
    size_t pos;

    while ((pos = strInput.find(',', start)) != std::string::npos) {
      std::cout << strInput.substr(start, pos - start) << "\n";
      start = pos + 1;
    }
    // auto id = strInput.substr(0, strInput.find(","));
    // auto id_first = id.substr(0, id.find("-"));
    // auto id_last = id.substr(1, id.find("-"));
    // std::cout << "first id:" << id_first << " last id:" << id_last << "\n";
  }
}
void store_data() {}

int main() {
  read_file();
  return 0;
}
