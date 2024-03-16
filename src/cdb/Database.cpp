#include "cdb/Database.hpp"

void cdb::Database::run()
{
    while (1)
    {
        int opc;
        std::cin >> opc;
        Opcode cmd = static_cast<Opcode>(opc);

        std::string table, key;
        int32_t value;
        switch (cmd)
        {
        case Opcode::AddEntry:
            std::cin >> table >> key >> value;
            if (engine.tableExists(table))
            {
                engine.addTableEntry(table, key, value);
            }
            else
            {
                std::cout << "Table does not exist!" << std::endl;
            }
            break;
        case Opcode::GetEntry:
            std::cin >> table >> key;
            if (engine.tableExists(table))
            {
                std::cout << "value: " << engine.getTableEntry(table, key) << std::endl;
            }
            else
            {
                std::cout << "Table does not exist!" << std::endl;
            }
            break;
        case Opcode::CreateTable:
            std::cin >> table;
            if (engine.tableExists(table))
            {
                std::cout << "Table already exists!" << std::endl;
            }
            else
            {
                engine.createTable(table);
            }
            break;
        case Opcode::DeleteTable:
            std::cin >> table;
            if (engine.tableExists(table))
            {
                engine.deleteTable(table);
            }
        default:
            break;
        }
    }
}