#include <iostream>
#include <vector>

std::vector<double> readInVector(std::string s)
{
  int prev_location = 0;
  int next_location = 0;
  std::vector<double> result;
  while (s.find(',', prev_location) != std::string::npos)
  {
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

void printVector(std::vector<double> vec)
{
  std::cout << "Vector: [";
  for (int i = 0; i < vec.size(); i++)
  {
    std::cout << vec[i] << ",";
  }
  std::cout << "]" << std::endl;
}

int main()
{
  std::vector<double> x;
  std::vector<double> w;
  std::vector<double> y;
  bool pack_with_zeros = true;

  std::string s;
  std::cin >> s;
  if (s == "false")
  {
    pack_with_zeros = false;
  }
  std::cin >> s;
  x = readInVector(s);
  std::cin >> s;
  w = readInVector(s);

  // TODO write your code here
  // =========== START =========

  printVector(w);
  printVector(x);

  int kSize = w.size();
  int vSize = x.size();

  for (int v = 0; v < vSize; v++)
  {
    y.push_back(0);
    for (int k = 0; k < kSize; k++)
    {
      int vectorIndexToMultiply = v - kSize / 2 + k;
      if (vectorIndexToMultiply < 0)
      {
        if (pack_with_zeros == false)
        {
          y[v] += w[k] * x[0];
        }
        else
        {
          continue;
        }
      }
      else if (vectorIndexToMultiply >= vSize)
      {
        if (pack_with_zeros == false)
        {
          y[v] += w[k] * x[vSize - 1];
        }
        else {
          continue;
        }
      }
      else
      {
        y[v] += w[k] * x[vectorIndexToMultiply];
      }
    }
  }

  std::cout << "{";
  for (int i = 0; i < y.size() - 1; i++)
  {
    std::cout << y[i] << ", ";
  }
  std::cout << y[y.size() - 1];
  std::cout << "}" << std::endl;

  // =========== END ===========

  return 0;
}
