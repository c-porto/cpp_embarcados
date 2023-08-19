#ifndef _ADM_HH
#define _ADM_HH

#include "aluno.hh"
#include <vector>
namespace Adm {
struct Turma {
  Turma() = default;
  ~Turma() = default;
  std::vector<Aluno> cadastro_de_alunos;
  Aluno *procurar_por_matricula();
  Aluno *procurar_por_nome();
  void listar_todos_os_alunos();
  Aluno excluir_aluno();
};
};     // namespace Adm
#endif // !_ADM_HH
