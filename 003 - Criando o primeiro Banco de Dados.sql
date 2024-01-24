#criar o banco de dados
CREATE DATABASE cadastro;

#seleciona a tabela
use cadastro;

#tipos de dados
#Numéricos
#L Inteiro 		- TynyInt, SmallInt, Int, MediumInt, BigInt
#L Real 		- Decimal, Float, Double, Real
#L Lógica		- Bit, Bool
#Data/Tempo		- Date, DataTime, TimeStamp, Time, Year
#Literal 		
#L Caractere	- Char, varchar
#L Texto		- TinyText, Text, MediumText, Longtext
#L Coleção 		- Enum, Set
#Especial		- Geometry, Point, Polygon, MultiPolygon

#criar tabelas
create table pessoas (
nome varchar(30),
idade tinyint(3),
sexo char(1),
peso float,
altura float,
nacionalidade varchar(20)
);

#descreve as pessoa a estrutura da tabela
describe pessoas;
