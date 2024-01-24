# DDL - DATE DEFINITION LANGUAGE
# L Create
# 	L database
# 	L table
#
# DML - DATE MANIPULATION LANGUAGE
# L insert
#	L into

# seleciona o banco cadastro
use cadatro;

#inserir os dados na tabela pessoas
insert into pessoas
#nome da tabela do banco de dados
(nome, nascimento, sexo, peso, altura, nacionalidade)
values #os dados que vou colocar no banco de dados
('Godofredo', '1984-01-02', 'M', '78.5', '1.83', 'Brasil');

#inserindo a segunda pessoa
insert into pessoas
(nome, nascimento, sexo, peso, altura, nacionalidade)
values 
('Maria', '1999-12-30', 'F', '55.2', '1.65', 'Portugal');

#inserido a pessoa com o id e nacionalidade DEFAULT
insert into pessoas
(id, nome, nascimento, sexo, peso, altura, nacionalidade)
values 
(DEFAULT, 'Creuza', '1920-12-30', 'F', '50.2', '1.65', DEFAULT);

#inserindo sem os nomes dos campos da tabela
insert into pessoas values 
(DEFAULT, 'Adalgiza', '1930-11-2', 'F', '63.2', '1.75', 'Irlanda');

#inserindo mais de uma pessoa em um codigo só
insert into pessoas
(id, nome, nascimento, sexo, peso, altura, nacionalidade)
values 
(DEFAULT, 'Cládio', '1975-4-22', 'M', '99.0', '2.15', 'Brasil'),
(default, 'Pedro', '1999-12-3', 'M', '87', '2', default),
(DEFAULT, 'Janaína', '1987-11-12', 'F', '75.4', '1.66', 'EUA');

#ver os valores na tabela
select * from pessoas;