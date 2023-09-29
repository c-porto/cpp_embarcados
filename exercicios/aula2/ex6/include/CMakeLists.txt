project(disciplina)
add_library(disciplina STATIC adm.cc aluno.cc)
target_include_directories(disciplina PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
