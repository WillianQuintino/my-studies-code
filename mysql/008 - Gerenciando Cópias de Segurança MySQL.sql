# GERENCIAR CÓPIAS DE SEGURANÇÃO DE DADOS

# selecionando o banco de dados cadastro
use cadastro;

#mostrar tabelas
show tables;

#selecionado a tabela cursos
select * from cursos;

#selecionado a tabela gafanhotos
select * from gafanhotos;

#verificar a estrutura da tabela gafanhotos
describe gafanhotos;

#verificar a estrutura da tabela cursos comando curto
desc cursos;

#copia do banco de dados pode ser chamado de 'dump'
#gerado um dump na pasta 
# L no MySQL Workbench vai em > Server > Data Export > seleciona a pasta onde quer salvar
#apagando o banco de dados
drop database cadastro;
drop database test;

# importando um dump da pasta ou arquivo
# L no MySQL Workbench vai em > Server > Data Importe > seleciona onde foi salvo
