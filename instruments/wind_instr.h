#pragma once
#include "Base.h"
class wind_instr :
    public Base
{
public:
    wind_instr();
    wind_instr(char file);
    wind_instr(const wind_instr& other);
    ~wind_instr() override;

    char* get_name_manufacture();
    void set_name_manufacture(char* NameManufacture);
    char* get_defects();
    void set_defects(char* Defects);

    void show_instrument() override;
    void change() override;
    void save_to_file(std::ofstream& outputFile) override;
    void save_service(std::ofstream& fout) override;
    void load_file(std::ifstream& fin) override;
private:
    char* name_manufacture;
    char* defects;
};