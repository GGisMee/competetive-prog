#include <iostream>
#include <string>
#include <vector>

void print_path(std::vector<std::string> &paths, std::string name) {
  std::string total_path;
  for (const std::string &path : paths) {
    total_path += path + "/";
  }

  if (!total_path.empty()) {
    total_path.back() = '/';
  }
  std::cout << "git add " << total_path << name << "\n";
}

int main() {
  int N;
  std::cin >> N;
  std::vector<std::string> arr(N);
  std::vector<std::string> full_path;
  std::cin.ignore(); // Removes cin
  for (int i = 0; i < N; i++) {
    std::string com;
    std::getline(std::cin, com);
    if (com.starts_with("cd ")) {
      std::string path = com.substr(3); // Tar bort "cd "
      if (path == "..") {
        full_path.pop_back();
      } else {
        full_path.push_back(path);
      };
    } else if (com.starts_with("nano ")) {
      std::string name = com.substr(5);
      print_path(full_path, name);
    } else {
      continue;
    }
  }

  std::cout << "git commit\n";
  std::cout << "git push\n";
}
