#include "adm.hh"
#include "aluno.hh"
#include <iostream>
#include <list>

Aluno *procurar_por_matricula();
Aluno *procurar_por_nome();
void listar_todos_os_alunos();
Aluno excluir_aluno();

Adm::Turma::Turma(std::vector<std::string> &nomes,
                  std::vector<uint64_t> &matrículas) {
  this->cadastro_de_alunos = new std::list<Aluno>;
  if (nomes.size() != matrículas.size()) {
    std::cout << "Incoerência nos dados" << std::endl;
    std::cout << "Por favor cheque se há matrículas ou nomes faltando"
              << std::endl;
  } else {
    for (int i = 0; i < nomes.size(); ++i) {
      Aluno tmp = Aluno(nomes[0], matrículas[0]);
      cadastro_de_alunos->push_back(tmp);
    }
  }
}
