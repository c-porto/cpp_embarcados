#include "adm.hh"
#include "aluno.hh"
#include <iostream>
#include <list>

Adm::Turma::Turma(std::vector<std::string> &nomes,
                  std::vector<uint64_t> &matrículas) {
  if (nomes.size() != matrículas.size()) {
    std::cout << "Incoerência nos dados" << std::endl;
    std::cout << "Por favor cheque se há matrículas ou nomes faltando"
              << std::endl;
  } else {
    for (int i = 0; i < nomes.size(); ++i) {
      Aluno tmp = Aluno(nomes[i], matrículas[i]);
      cadastro_de_alunos[i] = tmp;
    }
  }
}
auto Adm::Turma::procurar_por_nome(std::string nome) -> Aluno {
  for (int i = 0; i < 30; ++i) {
    if (cadastro_de_alunos[i].nome == nome) {
      return cadastro_de_alunos[i];
    }
  }
  std::cout << "Aluno não encontrado" << std::endl;
  return Aluno{"Não encontrado"};
}
auto Adm::Turma::procurar_por_matricula(uint64_t matricula) -> Aluno {
  for (int i = 0; i < 30; ++i) {
    if (cadastro_de_alunos[i].ler_matrícula() == matricula) {
      return cadastro_de_alunos[i];
    }
  }
  std::cout << "Aluno não encontrado" << std::endl;
  return Aluno{"Não encontrado"};
}
auto Adm::Turma::excluir_aluno(std::string nome) -> Aluno {
  for (int i = 0; i < 30; ++i) {
    if (cadastro_de_alunos[i].nome == nome) {
      Aluno tmp = cadastro_de_alunos[i];
      cadastro_de_alunos[i].nome = "Inválido";
      cadastro_de_alunos[i].zerar_matrícula();
      return tmp;
    }
  }
  std::cout << "Aluno não encontrado" << std::endl;
  return Aluno{"Não encontrado"};
}

auto Adm::Turma::excluir_aluno(uint64_t matrícula) -> Aluno {
  for (int i = 0; i < 30; ++i) {
    if (cadastro_de_alunos[i].ler_matrícula() == matrícula) {
      Aluno tmp = cadastro_de_alunos[i];
      cadastro_de_alunos[i].nome = "Inválido";
      cadastro_de_alunos[i].zerar_matrícula();
      return tmp;
    }
  }
  std::cout << "Aluno não encontrado" << std::endl;
  return Aluno{"Não encontrado"};
}
auto Adm::Turma::media() -> float {
  float sum = 0;
  for (int i = 0; i < 30; ++i) {
    sum += (cadastro_de_alunos[i].nota_p1 + cadastro_de_alunos[i].nota_p2) / 2;
  }
  return sum / 30;
}
auto Adm::Turma::listar_todos_os_alunos() -> void {
  for (int i = 0; i < 30; ++i) {
    cadastro_de_alunos[i].print();
  }
}
