# tarefa1robofei
Conceitos iniciais: 

-Nodes -> são os elementos responsáveis pelas diferentes funções do robo, como andar, chutar, analisar, etc. Existem dois tipos de node:
   > Publisher -> "publica" seus dados em um topic, sua principal função é fornecer os dados.
   > Subscriber -> "subscriba" a uma topic, sua função é receber os dados.

- Topic -> conecta os nodes, pode ser conectado a vários nodes

- Serviços -> outro método de comunicação entre os nodes, diferente dos topics, os serviços só trocam informações com os nodes se essa informação for pedida por um dos nodes.

-Pacotes -> é onde organizamos os nossos códigos e projetos no ros2, ele é estruturado em:
   >CMakeLists.txt -> descreve como compilar o código, e inclui as dependências.
   >package.xml -> contém outras informações e dependências necessárias.
   >include/<package_name> -> sei lá
   >src -> onde colocamos os códigos que fizermos no VScode (no nosso caso com .cpp)

- Colcon é a ferramenta para compilar e gerenciar os work spaces. Gera pastas organizadas no workspace (build, install, log) e dá suporte a overlays.

- Source -> lembra de dar source install/setup.bash nos terminais

- Criando pacotes -> ros2 pkg create --build-type ament_cmake --license Apache-2.0 <package_name>
-Construindo pacotes -> colcon build --packages-select my_package

-Custmização -> uma forma de customizar os conteúdos dos pacotes, que será necessário em package.xml e CMakeLists.txt, podemos abrí-los com nano( um dos editores de texto do ubuntu) e mexer como quisermos. Só não podemos esquecer de salvar quando acabarmos.

-Mkidr -> cria diretórios ( mkdir <nomedo diretório> por exemplo)
