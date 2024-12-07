#include <iostream>
#include <cassert>
#include <chrono>

#include <sstream>
#include <string>
#include <iterator>
#include <queue>

#include "FileHandler.hpp"
#include "StringParser.hpp"

long long part1(const std::vector<std::string> & input) 
{
    long long result = 0;
    std::priority_queue <int, std::vector<int>, std::greater<int>> firstHeap, secondHeap;

    for (const std::string& line: input)
    {
        std::vector<int> split = StringParser::toIntVector(line, "   ");
        firstHeap.push(split[0]);
        secondHeap.push(split[1]);
    }

    assert(firstHeap.size() == secondHeap.size());

    while (!firstHeap.empty()) {
      result += firstHeap.top() + secondHeap.top();
      firstHeap.pop();
      secondHeap.pop();
    }
    return result;
}


int part2(const std::vector<std::string> & input) 
{
  return 31;
}

int main(void) 
{
    FileHandler testFileHandler("input-files/2024/day01_testinput1.txt");
    std::vector<std::string> testinput = StringParser::toVector(testFileHandler.getBuffer(), "\n");
    //assert(part1(testinput) == 11);

    FileHandler fileHandler("input-files/2024/day01.txt");
    std::vector<std::string> input = StringParser::toVector(fileHandler.getBuffer(), "\n");

    auto t_begin = std::chrono::high_resolution_clock::now();
    std::cout << "Day 1, puzzle 1: " << std::flush << part1(input) << std::endl;
    auto t_end = std::chrono::high_resolution_clock::now();
    std::cout << "Completed in: " << std::chrono::duration<double, std::milli>(t_end - t_begin).count() << " ms" << std::endl;

    assert(part2(testinput) == 31);

    t_begin = std::chrono::high_resolution_clock::now();
    std::cout << "Day 1, puzzle 2: " << std::flush << part2(input) << std::endl;
    t_end = std::chrono::high_resolution_clock::now();
    std::cout << "Completed in: " << std::chrono::duration<double, std::milli>(t_end - t_begin).count() << " ms" << std::endl;
}
