#include <iostream>
#include <fstream>
#include <cereal/archives/binary.hpp>
#include "cereal/types/string.hpp"

class names {
public:
    std::string first_name;
    std::string middle_name;
    std::string last_name;

    template <class Archive>
    void serialize(Archive &ar) {
        ar(first_name, middle_name, last_name);
    }

//    template <class Archive>
//    void save(Archive &ar) {
//        ar(first_name, middle_name, last_name);
//    }
//
//    template <class Archive>
//    void load(Archive &ar) {
//        ar(first_name, middle_name, last_name);
//    }

    friend std::ostream& operator<<(std::ostream &os, const names &name);
};

std::ostream& operator<<(std::ostream &os, const names &name) {
    os << name.first_name << ", " << name.middle_name << ", " << name.last_name;
    return os;
}

int main() {
    names my_name;
//    my_name.first_name = "Xiao";
//    my_name.last_name = "Lu";
//    my_name.middle_name = "Lightol";
//
//    std::ofstream fout("names.cereal", std::ios::binary);
//    cereal::BinaryOutputArchive ar(fout);
//    ar(my_name);

    std::ifstream fin("names.cereal", std::ios::binary);
    cereal::BinaryInputArchive ar(fin);
    ar(my_name);
    std::cout << my_name.first_name << " " << my_name.middle_name << " " << my_name.last_name << std::endl;

    return 0;
}

