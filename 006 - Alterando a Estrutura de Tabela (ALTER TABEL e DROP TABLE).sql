#seleciona a banco de dados
use cadastro;

#mostrar a estrutura da tabela
describe pessoas;

#forma comprimida
desc pessoas;

#alterar extrutura da tabela
alter table pessoas
#complemento para adicionar uma coluna profissao
add column profissao varchar(10);

alter table pessoas
#complemento para remover a coluna profissao
drop column profissao;

alter table pessoas
#complemento para adicionar uma coluna profissao depois do nome
add column profissao varchar(10) after nome;

alter table pessoas
#complemento para adicionar de forma simplificada uma coluna codigo na primeira coluna
add codigo int first;

alter table pessoas
#complemento para modficar o valor de quantidade da coluna profissao e bloqueio de nulo
modify column profissao varchar(20) not null default '';

alter table pessoas
#complemento para modficar o nome da coluna, mas tem que adicionar toda a descrição (constrant)
change column profissao prof varchar(20);

alter table pessoas
#para renomear a tabela
rename to gafanhotos;

#descreve a tabela renomeada
desc gafanhotos;

#listar as pessoas do banco
select * from pessoas;

# --------------------------------------

#criando um nova tabela cursos
