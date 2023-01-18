<?php

namespace App\Http\Middleware;

use Closure;
use Facade\FlareClient\Http\Response;

class LogAcessoMiddleware
{
    /**
     * Handle an incoming request.
     *
     * @param  \Illuminate\Http\Request  $request
     * @param  \Closure  $next
     * @return mixed
     */
    public function handle($request, Closure $next)
    {
        //$request - manipular
        //return $next($request);
        //response - manipular
        return Response('Chegamos no middleware e finalizamos no próprio middleware');
    }
}
