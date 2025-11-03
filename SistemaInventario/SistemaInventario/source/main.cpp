#include"Prerequisites.h"

int main() {
    json j = {
        {"name", "Clau"},
        {"project", "Inventario"},
        {"active", true}
    };

    std::cout << j.dump(4) << std::endl;
	return 0; 
}