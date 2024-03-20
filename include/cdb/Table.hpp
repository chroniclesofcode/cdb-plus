#pragma once
#include <unordered_map>
#include <string>
#include <vector>

namespace cdb
{

class Table
{
public:

    Table();

    Table(std::vector<std::string> _columns, std::vector<std::string> _dtypes);
    
    void addEntry(std::string key, int32_t value);

    int32_t getEntry(std::string key);

private:
    std::vector<std::string> columns;
    std::vector<std::string> dtypes;
    std::unordered_map<std::string, int32_t> data;
};

}