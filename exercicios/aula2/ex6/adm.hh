#ifndef _ADM_HH
#define _ADM_HH

#include "aluno.hh"
#include <cstdint>
#include <list>
#include <string>
#include <vector>

namespace Adm {
struct Turma {
  Turma(std::vector<std::string> &nomes, std::vector<uint64_t> &matrículas);
  ~Turma() = default;
  std::list<Aluno> *cadastro_de_alunos;
  auto procurar_por_matricula() -> Aluno *;
  auto procurar_por_nome() -> Aluno *;
  auto listar_todos_os_alunos() -> void;
  auto excluir_aluno() -> Aluno *;
};
};     // namespace Adm
#endif // !_ADM_HH
