/*
 * file: testCShape3d.cpp
 *
 * Descricao: Programa de teste para a Classe.
 *
 * Saida do programa:
 *
 * Volume do paralelograma: 730.17
 * Volume do cone: 5.12707
 * Volume do cilindro: 20.3575
 *
 *
 * Autor: Rob McGregor
 * Data: ??/??/??
 *
 * Ultima Alteracao: Eduardo Augusto Bezerra
 * Data da ultima alteracao: 29/05/2003
 *
 */

#include <cbox.h>
#include <ccone.h>
#include <ccylinder.h>
#include <cshape3d.h>
#include <cstring>
#include <iostream>
#include <memory>
#include <ostream>

int main()
{
    CShape3d *shape;

    // Um ponteiro para CShape3d assume a forma de um CBox
    //
    shape = new CBox(10.5f, 12.2f, 5.7f);
    std::cout << "Volume do paralelogramo: " << shape->volume() << std::endl;
    delete shape;

    // Um ponteiro para CShape3d assume a forma de um CCone
    //
    shape = new CCone(1.2f, 3.4f);
    std::cout << "Volume do cone: " << shape->volume() << std::endl;
    delete shape;

    // Um ponteiro para CShape3d assume a forma de um CCylinder
    //
    shape = new CCylinder(1.2f, 4.5f);
    auto shape2 = std::make_unique<CCylinder>(1.2f, 4.5f);
    std::cout << "Volume do cilindro: " << shape->volume() << std::endl;
    std::cout << "Volume do cilindro: " << shape2->volume() << std::endl;
    std::cout << *shape2 << std::endl;
    auto pdata = shape2->createVolumeDataset();
    for (auto &data : *pdata.get())
    {
        std::cout << data << std::endl;
    }
    shape2->vPrintDimensions(std::cout);
    delete shape;

    return 0;
}
