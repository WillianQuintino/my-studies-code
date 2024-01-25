# teminal para exiber os banco de dados
show databases;

#PHPMyAdmin para ciar um base de dados vc clica em New ou na pagina pricipal na Base de Dados
#criamos um bamco de dados exemplo
#criamos um a tabela amigos com 3 campos
#nomeamos os capos com id, nome, tel e colocamos as informações de validaçãoptimize

#no terminal colocamos o comando 
show databases;

# abrimos o banco de dados com
use exemplo;

#motramos as tabelas com 
show tables;

#mostrar a estrutura com
desc amigos;

#para mostrar como foi o comando para criar a tabela amigos
show create table amigos;

#mostra
CREATE TABLE `amigos` (
`id` int(11) NOT NULL AUTO_INCREMENT,
`nome` varchar(30) NOT NULL,
`tel` varchar(11) DEFAULT NULL,
PRIMARY KEY (`id`),
UNIQUE KEY `nome` (`nome`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci

#para mostrar como foi o comando para criar o banco de dados exemplo
show create database exemplo;

#mostra
CREATE DATABASE `exemplo` /*!40100 DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci */

#clicamos para ver a estrutura no PHPMyAdmin
#para modificar no PHPMyAdmin clica no lápis muda
# em cima parace o comando
ALTER TABLE `amigos` CHANGE `tel` `tel` VARCHAR(15) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL;

# clicando no editar vc pode editar o comando
# criando em criar um codigo PHP e mostra:
# $sql = "ALTER TABLE `amigos` CHANGE `tel` `tel` VARCHAR(15) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL;";
#clicamos em criar coluna, e selecionamos depois de nome
ALTER TABLE `amigos` ADD `idade` INT NOT NULL AFTER `nome`;

#clicamos eliminar
ALTER TABLE `amigos` DROP `idade`;

#criamos uma coluna sexo depois do nome
ALTER TABLE `amigos` ADD `sexo` ENUM('M','F') NOT NULL AFTER `nome`;

#para inserir um novo registro clica na tabla depois em insere
#inserimos os duas pessoas e inserir novamente
INSERT INTO `amigos` (`id`, `nome`, `sexo`, `tel`) VALUES (NULL, 'Maria', 'F', '2222-3333'), (NULL, 'João', 'M', '2222-3333');

#inserimos mais duas pessoas e volta atrás
INSERT INTO `amigos` (`id`, `nome`, `sexo`, `tel`) VALUES (NULL, 'José', 'M', '3333-4444'), (NULL, 'Ana', 'F', '1111-2222');

#lista a tabela
SELECT * FROM `amigos`;

#atualizamos o telefone do id 2
UPDATE `amigos` SET `tel` = '1111-2222' WHERE `amigos`.`id` = 2;

#deletamos o id 4
DELETE FROM amigos WHERE `amigos`.`id` = 4;

#voltamos o workbench
select * from amigos;

#gerando dump no PHPMyAdmin clica > casinha > exportar > personalizado > 'exemplo' > save output to a file > formato utf8 > sem compressão > formato SQL > mostrar comentarios > Add CREATE DATABASE / USE statement
#coloque na pasta dumps arquivo 127_0_0_1
#clicamos na estrutura da tabela elimina
DROP TABLE `amigos`;

#selecionamos o banco de dados e cliclamos em elimina
DROP DATABASE `exemplo`;
