## Código de detecção de erro (CDE)

Qualquer transmissão está sujeita a problemas, como ruídos e atenuação, e a camada de enlace tem a função de realizar o tratamento dos possíveis erros. O controle de erro envolve duas etapas distintas: primeiro a detecção dos possíveis erros nos dados transmitidos e, em seguida, a correção dos erros encontrados. Aqui iremos dar um exemplo de como essa detecção de erro pode se dar.

O mecanismo de detecção de erro é semelhante ao esquema de dígito verificador utilizado para garantir que o número de uma identidade ou conta bancária esteja correto. Por exemplo, suponha a conta bancária 05652-5, em que 05652 é o número da conta e o último número 5 represente o dígito verificador. O dígito verificador é gerado a partir dos números que compõem a conta corrente, utilizando uma função previamente definida. Sempre que a conta é utilizada, o dígito verificador é recalculado e comparado com o dígito presente na conta corrente. Se o dígito verificador calculado for igual ao dígito da conta, a informação está correta; caso contrário existe um erro.

E é dessa forma que iremos fazer a detecção de erros em uma mensagem, adicionando um código verificador ao final da mensagem com base no cálculo da soma dos códigos ANSII de cada caractere dividido pela quantidade de caracteres contidos na tabela ANSII, que é 256. Exemplo:

* Na mensagem "Ola, mundo", é feito a soma de todos os caracteres: O + l + a + , +  + m + u + n + d + o, mas convertendo isso para a codificação da tabela ANSII, temos 79 + 108 + 97 + 44 + 32 + 109 + 117 + 110 + 100 + 111 = 907.

* Possuindo a mensagem "Ola, mundo" com o valor inteiro de 907, agora é feito a divisão por 256 para se obter o resto, que é igual a 139: 907 % 256 = 139. Feito isso, é obtido o caractere de código 139 da tabela ANSII, que é "ï", e ele é adicionado ao final da mensagem.

* Feito isso, todas as vezes que ser feita uma transmissão, é realizado esse cálculo para o transmissor e para o receptor, e logo após isso é feito a comparação entre os códigos de detecção de erro (CDE) para analisar se a mensagem foi transmitida com sucesso ou se houve algum erro.

## Compilação e Execução

O repositório possui um arquivo <i>Makefile</i> que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:

<table align="center">
  <tr>
    <td><strong>Comando</strong></td>
    <td><strong>Função</strong></td>
  </tr>
  <tr>
    <td><code>make clean</code></td>
    <td>Apaga a última compilação realizada contida na pasta build.</td>
  </tr>
  <tr>
    <td><code>make</code></td>
    <td>Executa a compilação do programa utilizando o g++, e o resultado vai para a pasta build.</td>
  </tr>
  <tr>
    <td><code>make run</code></td>
    <td>Executa o programa da pasta build após a realização da compilação.</td>
  </tr>
</table>