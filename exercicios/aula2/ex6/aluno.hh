#ifndef _ALUNO_HH
#define _ALUNO_HH

#include <cstdint>
#include <string>
class Aluno {
public:
  std::string nome;
  float nota_p1;
  float nota_p2;
  Aluno(std::string nome);
  ~Aluno() = default;
  void postar_nota_p1();
  void postar_nota_p2();
  void alterar_notas();

private:
  uint64_t matricula;
};
#endif // !_ALUNO_HH
