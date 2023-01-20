<?php

namespace App\Http\Middleware;

use Closure;
use Facade\FlareClient\Http\Response;

class AutenticacaoMiddleware
{
    /**
     * Handle an incoming request.
     *
     * @param  \Illuminate\Http\Request  $request
     * @param  \Closure  $next
     * @return mixed
     */
    public function handle($request, Closure $next, $metodo_atenticacao, $perfil, $param3, $param4)
    {
        //verifica se o usuario tem acesso a rota
        echo $metodo_atenticacao.' - '.$perfil.'<br>';

        if ($metodo_atenticacao == 'padrao') {
            echo 'Verificar o usuário e senha no banco de dados'.$perfil.' <br>';
        } 

        if ($metodo_atenticacao == 'ldap') {
            echo 'Verificar o usuário e senha no AD'.$perfil.'<br>';
        }
        
        if ($perfil == 'visitante') {
            echo 'Exibir apenas alguns recursos';
        }else{
            echo 'Carregar o perfil do banco de dados';
        }

        if(false) {
            return $next($request);
        }else{            
            return Response('Acesso Negado! Rota exige autenticação!!!');
        }
    }
}
