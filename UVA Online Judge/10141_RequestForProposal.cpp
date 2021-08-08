#include <iostream>
#include <string>

#define MAX 2000000000.00

using namespace std;

int main() {

   int numrequest_solic = 0, numpropost = 0, numrequest_final = 0, contRFP = 1;
   float conformidade = 0.0, dinpropost, aux_din = 0.0, aux_conf = 0.0;
   string nomeEmpresa, propostas, nomeFinal;

   do
   {
      scanf("%d %d\n", &numrequest_solic, &numpropost);
      
      if (numrequest_solic == 0 && numpropost == 0) 
         break;
         
      //Pular Linha para RFP > 1
      if(contRFP > 1)
         cout << endl;

      //Propostas/Objetivos
      for(int i=0; i<numrequest_solic; i++){
         getline(cin, propostas);
      }

      //"Melhor" conformidade e custo possíveis para o problema
      conformidade = 0.0;
      dinpropost = MAX;

      for(int i=0; i<numpropost; i++){
         getline(cin, nomeEmpresa); //Nome da Empresa
         //cin >> aux_din >> numrequest_final; //Dinheiro da Proposta e dos Requisitos Cumpridos
         scanf("%f %d\n", &aux_din, &numrequest_final); //Dinheiro da Proposta e dos Requisitos Cumpridos

         for(int j=0; j<numrequest_final; j++){ //Propostas "para cumprir" da Empresa
            getline(cin, propostas);
         }

         //Verificação da Melhor Empresa
         //1º: Conformidade = Nº Propostas "A Cumprir"/Nº de Propostas Totais
         //Caso empate; 2º: Menor preço para cumprir as propostas.
         //Caso tudo seja empatado, receber a primeira do input
         
         aux_conf = (float)numrequest_final/numrequest_solic;
         if (conformidade < aux_conf || (conformidade == aux_conf && dinpropost > aux_din))
         {
            conformidade = aux_conf;
            dinpropost = aux_din;
            nomeFinal = nomeEmpresa;
         }
      }
      cout << "RFP #" << contRFP << endl;
      cout << nomeFinal << endl;

      contRFP++;

   } while (numrequest_solic != 0 || numpropost != 0);
       
   return 0;
}