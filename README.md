## DUNGEON CLAWS


Dungeon Claws é um rpg de texto em turnos feito por dois alunos da turma de segundo semestre do curo 
de engenharia de computação do CESUPA para a matéria de programação 2.


O jogo possui um menu inicial com 3 opções, dentre elas o "play", para dar início ao jogo, os "créditos", 
reservado para o nome dos criadores do jogo e o "exit" para o usuário fechar o programa.

Ao dar "play", o usuário será levado ao menu de criação de personagem, onde poderá escolher o seu nome
e distribuir seus 15 atributos iniciais entre constituição, agilidade, força e destreza.

`Constituição`: Influencia na vida e na defesa do personagem
`Agilidade`: Influencia sobre quem iniciará cada turno na hora da batalha. Quem possuir a maior agilidade começará primeiro.
`Força`: Influencia no dano de armas pesadas.
`Destreza`: Influencia no dano de armas leves.

Após a distribuição de pontos, o usuário será levado para um pequeno tutorial sobre o sistema de batalha do jogo, onde
será ensinado sobre como atacar e usar poções.


## SISTEMA DE BATALHA


Durante uma batalha, o usuário possui 3 opções, dentre elas, o ataque, defesa e uso de poções. As poções são limitadas
a 3 por batalha.

O inimigo possui as mesmas 3 opções que serão escolhidas aleatoriamente por ele, dependendo do seu nível de agressividade
curabilidade e defensibilidade.

No ataque, o dano do personagem será calculado levando em conta a força ou destreza, dependendo da categoria da arma
(leve ou pesada), e levando em conta o dano base de cada arma.


Quanto a defesa, será levado em conta a defesa da armadura que o player está utilizando.


- `Créditos`: Leonardo Antonio Gomes dos Santos e José Victor Colino Gonçalves
- `Linguagem`: Java
