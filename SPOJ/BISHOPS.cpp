/*Criado por Davi Augusto (esse foi foda...)*/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//Tratamento por String
string Subtrai(string str)
{
     //Auxiliar
     string aux = "";

     //Invertendo a string para realizar subtração
     reverse(str.begin(), str.end());

     //Carry
     int carry = 0;

     //Percorrendo e realizando a subtração dígito a dígito
     for (int i = 0; i < str.length(); i++)
     {
          int sub;
          //Subtraindo o dígito 1
          if (i == 0)
          {
               sub = ((str[i] - '0') - 1);
               if (sub < 0)
               {
                    sub += 10;
                    carry = 1;
               }
          }
          //Realizando a conta com demais dígitos (carry)
          else
          {
               sub = ((str[i] - '0') - carry);
               if (sub < 0)
               {
                    sub += 10;
                    carry = 1;
               }
               else
               {
                    carry = 0;
               }
          }
          aux.push_back(sub + '0');
     }

     //Após o processo, basta inverter a string novamente
     reverse(aux.begin(), aux.end());
     return aux;
}
string MultiplicaDois(string str)
{
     //Invertendo a string para realizar operação
     reverse(str.begin(), str.end());

     //Carry
     int carry = 0;

     //Percorrendo e realizando multiplicação por 2
     for (int i = 0; i < str.size(); i++)
     {
          int mult = ((str[i] - '0') * 2) + carry;
          str[i] = (mult % 10) + '0';
          carry = mult / 10;
     }
     //Se sobrou carry, acrescentar pro final da string
     if (carry > 0)
     {
          str += (carry + '0');
     }

     //Inverter a string novamente
     reverse(str.begin(), str.end());
     return str;
}
string Resolve(string N)
{
     //Passo 1: Subtrair "1" da String
     N = Subtrai(N);

     //Passo 2: Multiplicar a String por 2
     N = MultiplicaDois(N);

     return N;
}

int main()
{

     string N;

     while (getline(cin, N))
     {
          if (N == "1")
          {
               cout << N << endl;
          }
          else
          {
               //Por se tratar de um tamanho muito grande, necessário tratar por meio de dígito da string
               //2 * (N - 1)

               cout << Resolve(N) << endl;
          }
     }

     return 0;
}