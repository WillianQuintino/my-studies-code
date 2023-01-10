<?php

namespace App\Http\Controllers;

use Facade\Ignition\DumpRecorder\Dump;
use Illuminate\Http\Request;
use App\SiteContato;
use PhpParser\Builder\Function_;

class ContatoController extends Controller
{
    public function contato(Request $request)
    {

        $motivo_contatos = [
            '1' => 'Dúvida',
            '2' => 'Elogio',
            '3' => 'Reclamação'
        ];

        return view('site.contato', ['titulo' => 'Contato (teste)', 'motivo_contatos' => $motivo_contatos]);
    }

    public function salvar (Request $request){
        //realizar a validação dos  dados do formulário recebidos no request
        $request->validate([
            'nome' => 'required|min:3|max:40', //nomes com no mínino 3 caracteres e no máximo 40
            'telefone' => 'required',
            'email' => 'required',
            'motivo_contato' => 'required',
            'mensagem' => 'required|max:2000'
        ]);
        //SiteContato::create($request->all());
    }
}
