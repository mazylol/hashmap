#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include <Hashmap.h>

std::vector<std::string> load_lines(const std::string& file) {
    std::ifstream f(file);

    std::vector<std::string> lines;
    std::string line;

    while (std::getline(f, line)) {
        lines.push_back(line);
    }

    return lines;
}

int main() {
    auto keys = load_lines("keys.txt");
    auto valuesUnconverted = load_lines("values.txt");

    std::vector<int> values = {};

    for (const std::string& value : valuesUnconverted) {
        values.push_back(stoi(value));
    }

    auto start_my = std::chrono::system_clock::now();
    Hashmap<std::string, int> my_map;
    for (int i = 0; i < keys.size(); i++) {
        my_map.add(keys[i], values[i]);
    }
    for (const auto & key : keys) {
        std::cout << my_map.get(key) << std::endl;
    }
    for (const auto & key : keys) {
        my_map.remove(key);
    }
    auto stop_my = std::chrono::system_clock::now();
    auto duration_my = std::chrono::duration_cast<std::chrono::microseconds>(stop_my - start_my);


    auto start_proper = std::chrono::system_clock::now();
    std::unordered_map<std::string, int> proper_map;
    for (int i = 0; i < keys.size(); i++) {
        proper_map[keys[i]] = values[i];
    }
    for (const auto & key : keys) {
        std::cout << proper_map[key] << std::endl;
    }
    for (const auto & key : keys) {
        proper_map.erase(key);
    }
    auto stop_proper = std::chrono::system_clock::now();
    auto duration_proper = std::chrono::duration_cast<std::chrono::microseconds>(stop_proper - start_proper);

    std::cout << "My implementation took " << duration_my.count() << "us" << std::endl;
    std::cout << "Official implementation (unordered_map) took " << duration_proper.count() << "us" << std::endl;

    return 0;
}