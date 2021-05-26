#include <iostream>
#include <vector>

std::vector<double> readInVector(std::string s) {
  int prev_location = 0;
  int next_location = 0;
  std::vector<double> result;
  while(s.find(',', prev_location) != std::string::npos) {
    next_location = s.find(',', prev_location);
    //std::cout << "prev_location: " << prev_location << std::endl;
    //std::cout << "next_location: " << next_location << std::endl;
    // substr [,]
    //std::cout << s.substr(prev_location, next_location - prev_location) << std::endl;
    result.push_back(std::stod(s.substr(prev_location, next_location - prev_location)));
    next_location++;
    prev_location = next_location;
  }
  result.push_back(std::stod(s.substr(prev_location, std::string::npos)));
  return result;
}

int main() {
  std::vector<double> x;
  std::vector<double> w;
  std::vector<double> y;
  bool pack_with_zeros = true;

  std::string s;
  std::cin >> s;
  if(s == "false") {
    pack_with_zeros = false;
  }
  std::cin >> s;
  x = readInVector(s);
  std::cin >> s;
  w = readInVector(s);

  // TODO write your code here
  // =========== START =========

  int kSize = w.size();
  int vSize = x.size();

  y.push_back(w[0] * 0);
  y[0] += w[1] * x[0];
  y[0] += w[2] * x[0 + 1];

  for (int i = 0; i < x.size(); i++) {

  	if ()

    y.push_back(w[0] * x[i - 1]);
    y[i] += w[1] * x[i];
    y[i] += w[2] * x[i + 1];
  }

  int end = x.size() - 1;

  y.push_back(w[0] * x[end - 1]);
  y[end] += w[1] * x[end];
  y[end] += w[2] * 0;

  std::cout << "{";
  for (int i = 0; i < y.size() - 1; i++) {
  	std::cout << y[i] << ", ";
  }
  std::cout << y[y.size() - 1];
  std::cout << "}" << std::endl;


  // =========== END ===========

  return 0;
}

