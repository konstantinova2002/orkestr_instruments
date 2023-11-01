#pragma once
#include "Base.h"
class string_instr :
    public Base
{
public:
    string_instr();
    string_instr(char file);
    string_instr(const string_instr& other);
    ~string_instr() override;

    char* get_name_manufacture();
    void set_name_manufacture(char* NameManufacture);
    char* get_text_description();
    void set_text_description(char* TextDescription);

    void show_instrument() override;
    void change() override;
    void save_to_file(std::ofstream& outputFile) override;
    void save_service(std::ofstream& fout) override;
    void load_file(std::ifstream& fin) override;
private:
    char* name_manufacture;
    char* text_description;
};