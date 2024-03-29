#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "func_menus.h"
#include "func_tela.h"

int calculadoraSimples(void) {
	float primeiroNumero, segundoNumero, resultado;
    int numeroParaCalculadora;
	int numeroCondicao;
	while (True) {
            
        limparTela();
        menuCaculadora();
        numeroCondicao = entradaDadosValidos(1,5);
        limparTela();
        numeroParaCalculadora = numeroCondicao;
        
        // Sai da calculadora 
        if (numeroCondicao == 5) {
            break;
        }

        while (True) {

            limparTela();
            // Colocar na tela a operação que esta sendo feita
            if (numeroParaCalculadora == 1) {
                printf("[Soma]\n");
            } else if (numeroParaCalculadora == 2) {
                printf("[Subtração]\n");
            } else if (numeroParaCalculadora == 3) {
                printf("[Multiplicação]\n");
            } else {
                printf("[Divisão]\n");
            }
        
            printf("Digite o primeiro número: ");
            primeiroNumero = entradaDadosValidosReal();
            printf("Digite outro número: ");
            segundoNumero = entradaDadosValidosReal();


            if (numeroParaCalculadora == 1) {
                resultado = primeiroNumero + segundoNumero;
                printf("%.2f + %.2f = %.2f", primeiroNumero, segundoNumero, resultado);
            } else if (numeroParaCalculadora == 2) {
                resultado = primeiroNumero - segundoNumero;
                printf("%.2f - %.2f = %.2f", primeiroNumero, segundoNumero, resultado);
            } else if (numeroParaCalculadora == 3) {
                resultado = primeiroNumero * segundoNumero; 
                printf("%.2f * %.2f = %.2f", primeiroNumero, segundoNumero, resultado);
            } else {
                if (segundoNumero == 0) {
                    printf("Essa divisão é indeterminada!");
                } else {
                    resultado = primeiroNumero / segundoNumero;
                    printf("%.2f / %.2f = %.2f", primeiroNumero, segundoNumero, resultado);
                }
            }
            printf("\n\n");
            printf("=-=-=-=-=-=-=-=-=-=-=--=-=-=-=\n");
            printf("Deseja fazer outra operação?\n");
            printf("=-=-=-=-=-=-=-=-=-=-=--=-=-=-=\n");
            printf("[1]Sim\n");
            printf("[2]Não\n");
            printf("=-=-=-=-=-=-=-=-=-=-=--=-=-=-=\n");
            printf("Digite aqui: ");

            numeroCondicao = entradaDadosValidos(1,2);
            
            if (numeroCondicao == 1) {
                //permanece na calculadora
                continue;
            
            } else {
                //volta para o menu de cálculos
                break;
            }
        }
    }
    return numeroCondicao;
}	


int conversorMedidas(void){
    //O (float) transforma os números em reais
    int numeroCondicao, conv[1][3] = {1,10,100}; //armazenamento das constantes
    float primeiroNumero, segundoNumero;
    while (True){
        limparTela();
        menuConversorMedida1();
        numeroCondicao = entradaDadosValidos(1, 3);
        menuConversorMedida2();
        switch(numeroCondicao){
            case 1:
                numeroCondicao = entradaDadosValidos(1, 3);
                printf("Informe a quantidade: ");
                switch(numeroCondicao){
                    case 1:
                        primeiroNumero = entradaDadosValidosReal();
                        printf("%.2fM = %.2fM",primeiroNumero, primeiroNumero);
                        break;
                    case 2:
                        primeiroNumero = entradaDadosValidosReal();
                        printf("%.2fM ", primeiroNumero);
                        primeiroNumero = primeiroNumero * (float)conv[0][1];
                        printf("= %.2fDM", primeiroNumero);
                        break;
                    case 3:
                        primeiroNumero = entradaDadosValidosReal();
                        printf("%.2fM ", primeiroNumero);
                        primeiroNumero = primeiroNumero * (float)conv[0][2] ;
                        printf("= %.2fCM", primeiroNumero);
                        break;
                }
                break;
            case 2:
                numeroCondicao = entradaDadosValidos(1, 3);
                printf("Informe a quantidade: ");
                switch(numeroCondicao){
                   case 1:
                        primeiroNumero = entradaDadosValidosReal();
                        printf("%.2fDM ", primeiroNumero);
                        primeiroNumero = primeiroNumero / (float)conv[0][1] ;
                        printf("= %.2fM", primeiroNumero);
                        break;
                   case 2:
                        primeiroNumero = entradaDadosValidosReal();
                        printf("%.2fDM = %.2fDM", primeiroNumero, primeiroNumero);
                        break;
                   case 3:
                        primeiroNumero = entradaDadosValidosReal();
                        printf("%.2fDM ", primeiroNumero);
                        primeiroNumero = primeiroNumero * (float)conv[0][1] ;
                        printf("= %.2fCM", primeiroNumero);
                        break;
                 }	        
                break;
            case 3:
                numeroCondicao = entradaDadosValidos(1, 3);
                printf("Informe a quantidade: ");
                switch(numeroCondicao){
                   case 1:
                        primeiroNumero = entradaDadosValidosReal();
                        printf("%.2fCM ", primeiroNumero);
                        primeiroNumero = primeiroNumero / (float)conv[0][2] ;
                        printf("= %.2fM", primeiroNumero);
                        break;
                   case 2:
                        primeiroNumero = entradaDadosValidosReal();
                        printf("%.2fCM ", primeiroNumero);
                        primeiroNumero = primeiroNumero / (float)conv[0][1] ;
                        printf("= %.2fDM", primeiroNumero);
                        break;
                   case 3:
                        primeiroNumero = entradaDadosValidosReal();
                        printf("%.2fCM = %.2fCM", primeiroNumero, primeiroNumero);
                        break;
                break;
               }
         }
        limparTela();
        printf("\nDeseja fazer outra conversão?\n[1]Sim\n[2]Não\nDigite aqui: ");
        numeroCondicao = entradaDadosValidos(1, 2);
        if (numeroCondicao == 1) continue; //Volar ao menu de conversor
        else break; //Sair do menu de conversor 
    }   
    return numeroCondicao;
}


int pedraPapelTesoura(void){  
    int jogador,ia,cont;
    cont = 0;
    limparTela();
    printf("Bem-vindo ao pedra, papel e tesoura\n");

    sleep(2);
    limparTela();
    while (cont < 2){

        printf("Escolha uma das opções:\n[1]pedra\n[2]papel\n[3]tesoura\nDigite aqui: ");
        jogador = entradaDadosValidos(1,3);
        limparTela();
        printf("A IA está pensando...\n");
        
        sleep(2);
        
        printf("Pronto!\n");
        sleep(1);
        srand(time(NULL)); //iniciar a função rand
        ia = rand()%3+1; //pegar um número de 1 a 3
    
        if (jogador == ia){
            printf("Processando...\n");
    
            sleep(2);
              
            printf("Deu empate!\n");
                
        }
        else if (jogador == 2 && ia == 1){
            printf("Processando...\n");
    
            sleep(2);
            
            printf("Vitória do jogador\n");
                
        }
        else if (jogador == 3 && ia == 2){
            printf("Processando...\n");
    
            sleep(2); 
            
            printf("Vitoria do jogador\n");
        }
        else if (jogador == 1 && ia == 3){
            printf("Processando...\n");
    
            sleep(2);
              
            printf("Vitoria do jogador\n");
            
        }
        else{
            printf("Processando...\n");
    
            sleep(2);
              
            printf("Vitoria da IA\n");
        }
    
        printf("\nDeseja jogar novamente?\n");
        printf("[1]Sim\n[2]Não\nDigite aqui: ");
        cont = entradaDadosValidos(1,2);
        limparTela();
    }

    return cont;
}

int jogoAdivinha(void){
    
    int player,n,nmin,nmax,rep,cont;
    cont = 0;
    limparTela();
    printf("Bem-vindo(a) ao adivinha, você tem 5 chances\n");

    sleep(2);
    limparTela();


    while (cont < 2){
    
        cont = 0;
        rep = 5;
        
        srand(time(NULL)); //iniciar a função rand
        n = rand()%10+1; //pergar número de 1 a 10

        nmin = n - 2;
        nmax = n + 2;

        while(rep != 0){
            printf("Você tem %d tentativas \n", rep);
            printf("Digite um número entre 1 e 10\nDigite aqui: ");
            player = entradaDadosValidos(1,10);

            if (player == n){
                limparTela();
                printf("Você acertou!\n");
                break;
            }
        
            else if (n < player && player <= nmax){
                limparTela();
                printf("Você chegou perto!\n");
                rep -= 1; 
            }
            else if (n > player && nmin <= player){
                limparTela();
                printf("Você chegou perto!\n");
                rep -= 1;    
            }
            else{
                limparTela();
                printf("Você está longe\n");
                rep -= 1; 
            } 
        }
        if (rep == 0){
            limparTela();
            printf("Você perdeu :(\n");
        }
        printf("Deseja jogar novamente?\n");
        printf("[1]sim\n[2]não\nDigite aqui: ");
        cont = entradaDadosValidos(1,2);
        limparTela();
    }
     return cont;
}

int areaFigurasPlanas(void){
	float area, base, altura, lado;
	int numeroCondicao;
	
	while (True){
	    limparTela();    
        printf("[1]Triângulo\n[2]Quadrado\n[3]Retângulo\n[4]Voltar ao menu de cálculo\nDigite aqui: ");
	    numeroCondicao = entradaDadosValidos(1,4);
	    switch(numeroCondicao){
	        case 1:
	            limparTela();
	            printf("Informe a altura do triângulo: ");
        	    altura = entradaDadosValidosReal();
	            printf("Informe a base do triângulo: ");
	            base = entradaDadosValidosReal();
	            area = (base*altura)/2;
	            printf("A área do triângulo é %.2f\n", area);
	            
	            printf("Deseja fazer outra operação?\n[1]Sim\n[2]Não\nDigite aqui: ");
	            numeroCondicao = entradaDadosValidos(1,2);
	            if (numeroCondicao == 1) break;
	            
	             
	            break;
	        case 2:
	            limparTela();
	            printf("Informe o lado do quadrado: ");
	            lado = entradaDadosValidosReal();
	            area = lado*lado;
	            printf("A área do quadrado é %.2f\n", area);
	            printf("Deseja fazer outra operação?\n[1]Sim\n[2]Não\nDigite aqui: ");
	            numeroCondicao = entradaDadosValidos(1,2);
	            if (numeroCondicao == 1) break;
	            
	            
	            break;
	        case 3:
	            limparTela();
	            printf("Informe a altura do retângulo: ");
	            altura = entradaDadosValidosReal();
	            printf("Informe a base do retângulo: ");
	            base = entradaDadosValidosReal();
	            area = base*altura;
	            printf("A área do retângulo é %.2f\n", area);	            
	            printf("Deseja fazer outra operação?\n[1]Sim\n[2]Não\nDigite aqui: ");
	            numeroCondicao = entradaDadosValidos(1,2);
	            if (numeroCondicao == 1) break;
	             
	            break;
	        case 4:
	            break;
	    }
    	if (numeroCondicao == 4) break;
        
	}
    return numeroCondicao;
}