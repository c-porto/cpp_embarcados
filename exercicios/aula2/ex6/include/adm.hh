#ifndef _ADM_HH
#define _ADM_HH

#include "aluno.hh"
#include <cstdint>
#include <list>
#include <string>
#include <vector>

namespace Adm {
class Turma {
public:
  Turma(std::vector<std::string> &nomes, std::vector<uint64_t> &matrículas);
  ~Turma() = default;
  Aluno cadastro_de_alunos[30];
  auto procurar_por_matricula(uint64_t matricula) -> Aluno;
  auto procurar_por_nome(std::string nome) -> Aluno;
  auto listar_todos_os_alunos() -> void;
  auto excluir_aluno(std::string nome) -> Aluno;
  auto excluir_aluno(uint64_t matrícula) -> Aluno;
  auto media() -> float;
};
};     // namespace Adm
#endif // !_ADM_HH
