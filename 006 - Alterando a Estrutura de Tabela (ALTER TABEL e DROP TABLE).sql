#DDL - Data Definition Languagem
# L create
#   L database
#   L table
# L alter
#   L table
# L drop
# 	L table

#DML - Data Manipulation Languagem
# L insert
#   L into

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

#criando tabela existente
create table if not exists gafanhotos (teste int);

#criando uma nova tabela cursos com parametro de condiciona nao se existe a tabela
create table if not exists cursos (
nome varchar(30) not null unique, #coluna nao pode ser nula e unica
descricao text,
carga int unsigned, # nao pode ter sinal ou seja negativo
totaulas int unsigned,
ano year default '2016' #ano padrao definido para 2016
) default charset = utf8;

#adicionando id cursos
alter table cursos
add column idcursos int first;

#adicionar chave primaria
alter table cursos
add primary key (idcursos);

alter table pessoas
#para renomear a tabela
rename to gafanhotos;

#criando tabela teste
create table if not exists teste(
id int,
nome varchar(10),
idade int
);

#inserindo valores na tabela teste
insert into teste value
('1', 'Pedro', 22),
('2', 'Maria', 12),
('3', 'Maricota', '77');

#selecionando tabela para visualizar os dados
select * from teste;

#para apagar tabela usa drop alunos que nao existe
drop table if exists alunos;

#para apagar tabela usa drop table
drop table if exists teste;

#descreve a tabela renomeada
desc gafanhotos;
desc cursos;

#listar as pessoas do banco
select * from pessoas;

# --------------------------------------

#criando um nova tabela cursos
