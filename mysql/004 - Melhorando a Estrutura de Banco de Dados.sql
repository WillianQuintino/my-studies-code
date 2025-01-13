#apaga o banco de dados
drop database cadastro;

#cria o banco de dados
create database cadastro
# set caracter para utf8
default character set utf8
default collate utf8_general_ci;

#seleciona a tabela
use cadastro;

#cria a tabela com configurações adicionais
create table pessoas (
id int not null auto_increment, # cria o identificado unico que não é nulo e gerado automaticamente
nome varchar(30) not null, # nao pode entrar sem valor
nascimento date, #limita a entrada so para datas
sexo enum('M', 'F'), #limita o sexo somente a M e F
peso decimal(5,2), # antes da vigula a quantidade de decimais e depois das vigura quantas casas deste quantidade vai ser usado depois da vigula
altura decimal(3,2),
nacionalidade varchar(20) default 'Brasil', # se emtrar sem valor adiciona o padrao escrito
primary key (id) #define o id como chave primaria (principal)
) default charset = utf8;