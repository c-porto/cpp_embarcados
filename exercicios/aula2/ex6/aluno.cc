#include "aluno.hh"
#include <iostream>
#include <random>
#include <string>

Aluno::Aluno(std::string nome) : nome(nome) {
  std::random_device rd;
  std::uniform_int_distribution<int> dist(19000000, 23500000);
  this->matricula = dist(rd);
  this->nota_p1 = 0.0f;
  this->nota_p2 = 0.0f;
}
Aluno::Aluno(std::string Nome, uint64_t matricula)
    : nome(Nome), matricula(matricula) {}

void Aluno::postar_nota_p1() {
  std::cout << "Favor inserir a nota da Prova 1: ";
  std::cin >> nota_p1;
}

void Aluno::postar_nota_p2() {
  std::cout << "Favor inserir a nota da Prova 2: ";
  std::cin >> nota_p2;
}
