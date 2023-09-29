#include <stdint.h>
#include <string>
#include "estados.h"

std::string qual_estado (uint8_t cmd){
    switch (cmd){
    case 0:
        return "Nada";
    
    case 1:
        return "M025";

    case 2:
        return "M050";

    case 4:
        return "M075";
        
    case 8:
        return "M100";

    case 16:
        return "M125";

    case 32:
        return "M150";

    default:
        return "Nada";
    }
}
