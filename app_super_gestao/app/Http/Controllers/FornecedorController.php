<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

class FornecedorController extends Controller
{
    public function index()
    {
        $fornecedores = [
            0 => [
                'nome' => 'Fornecedor 1',
                'status' => 'N',
                'cnpj' => '0',
                'ddd' => '', //São Paulo (SP)
                'telefone' => '0000-0000'
            ],
            1 => [
                'nome' => 'Fornecedor 2',
                'status' => 'N',
                'cnpj' => null,
                'ddd' => '85', //Fortaleza (CE)
                'telefone' => '0000-0000'
            ],
            2 => [
                'nome' => 'Fornecedor 3',
                'status' => 'N',
                'cnpj' => null,
                'ddd' => '32', //Juíz de Fora (MG)
                'telefone' => '0000-0000'
            ]
        ];
        
        /*
        condica ? se verdadeiro : se falso;
        condica ? se verdadeiro : (condica ? se verdadeiro : se falso;);
        */
        $msg = isset($fornecedores[0]['cnpj']) ? 'CNPJ informado' : 'CNPJ não informado';
        echo $msg;        
        return view('app.fornecedor.index', compact('fornecedores'));
    }
}
