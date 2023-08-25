#ifndef _ALUNO_HH
#define _ALUNO_HH

#include <cstdint>
#include <string>
class Aluno {
public:
  std::string nome;
  Aluno();
  Aluno(std::string nome);
  Aluno(std::string Nome, uint64_t matricula);
  ~Aluno() = default;
  void postar_nota_p1();
  void postar_nota_p2();
  uint64_t ler_matrícula();
  void zerar_matrícula();
  void print();
  float nota_p1;
  float nota_p2;

private:
  uint64_t matricula;
};
#endif // !_ALUNO_HH
