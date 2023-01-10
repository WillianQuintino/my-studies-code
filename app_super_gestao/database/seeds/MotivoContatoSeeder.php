<?php

use Illuminate\Database\Seeder;
use App\MotivoContato;

class MotivoContatoSeeder extends Seeder
{
    /**
     * Run the database seeds.
     *
     * @return void
     */
    public function run()
    {
        MotivoContato::created(['motivo_contato' => 'Dúvida']);
        MotivoContato::created(['motivo_contato' => 'Elogio']);
        MotivoContato::created(['motivo_contato' => 'Reclamação']);
    }
}
