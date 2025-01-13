#usando os comando pelo terminal

#lista todos o banco de dados
show databases;

#verifica o banco ativo no terminal
# - status;

#selecionado o banco de dados
use cadastro;

#mostrar tabelas que tem no banco
show tables;

#mostrar a estrutura da tabela
describe cursos;
desc gafanhotos;

#lista os dados no banco de dados
select * from gafanhotos;
select * from cursos;

#abrimos o PHP My Admim e editamos o dados da dona Adalgiza


#atualizando a linha 4 com nome Ph
update cursos set nome = 'Ph' where idcursos = '4';

#seta para cima ou baixo navega no historico de comandos
UPDATE `gafanhotos` SET `peso` = '83.20' WHERE `gafanhotos`.`id` = 4;