#OBETENDO DADOS DAS TABELAS

#DDL - Data Definition Language
# L CREATE
# 	L DATABASE
#	L TABLE
# L ALTER
#	L TABLE
# L DROP
#	L TABLE

#DML - Data Manipulation Language
# L INSERT
#	L INTO
# L UPDATE
# L DELETE
# L TRUNCATE
# L SELECT (Alguns autores)

#DQL - Data Query Language
# L SELECT (Alguns autores)

#download do arquivo dump Dump20230914.sql pelo link: https://tinyurl.com/554fz5rm

#selecionar o banco
use cadastro;

#selecionar a tabela gafanhotos
select * from gafanhotos;

#mostrar registro ordenado por nome
select * from cursos
order by nome;

#mostrar registro ordenado por nome  de cima para baixo
select * from cursos
order by nome desc;

#mostrar registro ordenado por nome  de baixo para cima
select * from cursos
order by nome asc;

#comando da a descrição da tabela
desc cursos;

# selecionar nome, carga e ano
select nome, carga, ano from cursos
order by nome;

# selecionar ano, carga e nome em ordem diferente
select ano, carga, nome from cursos
order by nome;

# selecionar ano, carga e nome em ordem diferente e ordenado por ano
select ano, carga, nome from cursos
order by ano;

# selecionar ano, carga e nome em ordem diferente e ordenado por ano e nome
select ano, carga, nome from cursos
order by ano, nome;

#filtar por linhas o ano de 2016
select * from cursos
where ano = '2016'
order by nome;

#filtar por linhas o ano de 2016, mostrnado o nome e carga
select nome, carga from cursos
where ano = '2016'
order by nome;

# o nome do que aparece é o result e query é a solicitacao

#filtar por linhas o ano de 2016
select nome, descrição, carga from cursos
where ano = '2016'
order by nome;

#filtar por linhas o ano é menor ou igual á 2015
select nome, descrição, ano from cursos
where ano <= '2015'
order by nome;

#filtar por linhas o ano é entre 2014 e 2016
select nome, ano from cursos
where ano between 2014 and 2016
order by ano desc, nome asc;

#filtar por linhas 2014 e 2016
select nome, ano from cursos
where ano in (2014, 2016, 2020)
order by ano;

#filtar por linhas onde a carga é maior que 35 e total de aulas menor que 30
select nome, carga, totalaulas from cursos
where carga > 35 AND totalaulas <30
order by nome;

#filtar por linhas onde a carga é maior que 35 ou total de aulas menor que 30
select nome, carga, totalaulas from cursos
where carga > 35 OR totalaulas <30
order by nome;
