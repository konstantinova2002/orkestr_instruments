#pragma once
#include "Base.h"

class perc_instr :
    public Base
{
public:
    perc_instr();
    perc_instr(char file);
    perc_instr(const perc_instr& other);
    ~perc_instr() override;
    
    char* get_type_perc();
    void set_type_perc(char* TypePerc);

    void show_instrument() override;
    void change() override;
    void save_to_file(std::ofstream& outputFile) override;
    void save_service(std::ofstream& fout) override; 
    void load_file(std::ifstream& fin) override;
private:
    char* type_perc;
};