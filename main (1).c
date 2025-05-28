#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
int colisaoespinhos(char fase2 [22][22], int x, int y){
	return fase2 [y][x] == '#';
}
int colisaoespinhos3(char fase3 [42][42], int x, int y){
	return fase3 [y][x] == '#';
}

void reiniciarMapa2(char fase2[22][22]) {
	int i, j;
    char mapa_inicial[22][22] = {
        "**********************",
        "*                    *",
        "*########            *",
        "*       #            *",
        "*       D            *",
        "*  O    #            *",
        "*@   @  #            *",
        "*       #            *",
        "*########            *",
        "*                    *",
        "*                    *",
        "*                    *",
        "*                    *",
        "*                    *",
        "*                    *",
        "* @                  *",
        "*            *********",
        "*            *       *",
        "*            *       *",
        "*            D       *",
        "*            *       D",
        "**********************"
    };

    for(i = 0; i < 22; i++) {
        for(j = 0; j < 22; j++) {
            fase2[i][j] = mapa_inicial[i][j];
        }
    }
}

void reiniciarMapa3(char fase3[42][42]){
	int i,j;
	char mapainicial[42][42] = {
			    "******************************************",
			    "<        #                               *",
			    "*      O #                               *",
			    "*  @     #                               *",
			    "*        #                               *",
			    "*#########                               *",
			    "*                                        *",
			    "*                      @                 *",
			    "*                                        *",
			    "*                                        *",
			    "*                                        *",
			    "*                                        *",
			    "*              #############             *",
			    "*              #     @     #             *",
			    "*              #           #             *",
			    "*              #           #             *",
			    "*              #           #             *",
			    "*              #           #             *",
			    "*###############           ########D#####*",
			    "*                                        *",
			    "*                                        *",
			    "*                                        *",
			    "*                                        *",
			    "*                                        *",
			    "*                                        *",
			    "*                                        *",
			    "*                                        *",
			    "*                                        *",
			    "*                                        *",
			    "*                                        *",
			    "*                                        *",
			    "*                                        *",
			    "*                                        *",
			    "*                                        *",
			    "*                                        *",
			    "*                                        *",
			    "***********                    ##########*",
			    "*         *                    #         *",
			    "*         D                    #         *",
			    "*         *                    #         *",
			    "D         *                    =         >",
			    "******************************************"
			};
			
	for(i = 0; i < 42; i++) {
        for(j = 0; j < 42; j++) {
            fase3[i][j] = mapainicial[i][j];
        }
    }
}

int main()
{
    //iniciando as variaveis necessarias para o la�o de sele��o do menu
  int menu;
  int vidas = 3;

  //usando c�digo setlocale para deixar a linguagem C com caracteristicas do portugues brasileiro como acentos e �.
  setlocale(LC_ALL,"Portuguese_Brazil");

  //solicitando que o usu�rio selecione uma das op��es do menu
  printf("Menu principal:\n1.Jogar\n2.Cr�dito\n3.Sair\nEscolha uma op��o: ");
    scanf("%d",&menu);

    //la�o de repti��o para for�ar o usu�rio apenas a selecionar op��es v�lidas no caso 1, 2 ou 3
    while(menu != 1 && menu != 2 && menu != 3){
	    printf("Op��o inv�lida, selecione novamente: ");
	    scanf("%d",&menu);
  }

  //la�o de repti��o que dar� ao usu�rio a chance de jogar quantas vezes quiser, so sendo quebrado no momento que o 3 for selecionado 
  while(menu != 3){
  	vidas = 3;
  	
    //la�o de sele��o para o caso do usu�rio selecionar op��o 1
      if(menu == 1){
      	
      	 printf("Na pacata vila de Praga, o cavaleiro Jorge vivia uma vida simples, treinando com sua espada e protegendo os alde�es de pequenas amea�as. Ele n�o buscava gl�ria nem riquezas, apenas a honra de servir. Por�m, seu destino mudou de repente.\n");
            printf("Enquanto patrulhava a floresta, Jorge foi envolto por uma n�voa negra e, quando os vapores se dissiparam, ele se viu diante de um portal sombrio. Antes que pudesse reagir, for�as invis�veis o puxaram para dentro, e ele caiu em uma masmorra maldita.\n");
			system("pause");
			system("cls");
			printf("O jogo � do estilo aventura/puzzle onde o objetivo � o jogador conseguir passar de tr�s fases. Em cada fase o jogador deve se movimentar para pegar uma chave para abrir a porta fechada.\n");
			printf("O jogador possui os seguintes comando:\nW: O jogador movimenta uma unidade para cima;\nA: O jogador movimenta uma unidade para esquerda;\nS: O jogador movimenta uma unidade para baixo;\nD: O jogador movimenta uma unidade para direita;\ni: O jogador interage com o objeto que est� em cima.");
	       system("pause");
	       system("cls");
	       printf(" & : jogador\n");
	       printf(" P : NPC\n");
	       printf(" * : parede\n");
	       printf(" @ : chave para abrir a porta\n");
	       printf(" D : porta fechada\n");
	       printf(" = : porta aberta\n");
	       printf(" O : bot�o que o jogador interage quando fica em cima dele\n");
	       printf(" # : espinho(se o jogador encostar no espinho 3 vezes o jogo � reiniciado)\n");
	       printf(" > : teletransporte\n");
	       printf(" X : Monstro n�vel 1\n");
	       printf(" V : Monstro n�vel 2\n");
	       system("pause");

      printf("Vila");
        //declarando variaveis que ser�o usadas para a locomo��o do personagem
          int x = 5, y = 5, i, j, a, b;
          char vila [12][12]={"************",
          	  	  	  	  	  "*    =  P  *",
          	  	  	  	  	  "D    *     *",
          	  	  	  	  	  "******     *",
          	  	  	  	  	  "*          *",
          	  	  	  	  	  "*          *",
          	  	  	  	  	  "*      @   *",
          	  	  	  	  	  "*          *",
          	  	  	  	  	  "*          *",
          	  	  	  	  	  "*          *",
          	  	  	  	  	  "*          *",
          	  	  	  	  	  "************"
		};
          char move;
          int chave = 0;
          //inicio da vila
          while(1){
          	
	    
            //fun��o system que serve para atualizar a tela do jogo sem precisar que fique v�rias atualiza��es na tela do usu�rio
          system("cls");
          
          	
          
          //sequencia de for's para a cria��o e atualiza��o do mapa
          for(i=0; i<12; i++){
            for(j=0; j<12; j++){
              if(i==y && j==x){
                printf("&");
              }
              //comando que orienta onde ser� as paredes
              else{
                printf("%c",vila [i] [j]);
              }
            } 
            printf("\n");
          }

          //fun��o getch para receber o caractere daa variavel move sem precisar mostrar nada na tela
          move = getch();
          
          //sequ�ncia de if's paea fazer a movimenta��o do personagem
          if((move == 'w' || move == 'W') && (vila [y-1] [x] != '*' && vila [y-1] [x] != 'D' && vila [y-1] [x] != '@' && vila [y-1] [x] != 'P' )) y--; 
          if((move == 's' || move == 'S') && (vila [y+1] [x] != '*' && vila [y+1] [x] != 'D' && vila [y+1] [x] != '@' && vila [y+1] [x] != 'P' )) y++;
          if((move == 'a' || move == 'A') && (vila [y] [x-1] != '*' && vila [y] [x-1] != 'D' && vila [y] [x-1] != '@' && vila [y] [x-1] != 'P' )) x--;
          if((move == 'd' || move == 'D') && (vila [y] [x+1] != '*' && vila [y] [x+1] != 'D' && vila [y] [x+1] != '@' && vila [y] [x+1] != 'P' )) x++;
          if(move == 'b') break;
          
          if(x== 7 && y == 7 &&(move == 'i' || move == 'I') && vila [6][7] == '@'){
          	vila[6][7] = ' ';
			chave = 1;
			}
			if(x== 8 && y == 2 &&(move == 'i' || move == 'I')){
				printf("Ah, ent�o voc� � o cavaleiro Jorge... A n�voa te escolheu, como muitos antes de ti.\nEsta masmorra n�o � apenas pedra e escurid�o � � um teste.\nPara sair daqui, n�o bastar� for�a, mas tamb�m sabedoria e coragem.\nEncontre as chaves, abra os caminhos e n�o tema o que espreita nas sombras.\nO destino da vila pode muito bem estar ligado ao seu."

);
             system("pause");
				
			}
			if(x == 1 && y == 2 && (move == 'i' || move == 'I') && chave ==1){
			  vila[2][0] = '=';
			}
		
		  if(x == 0 && y == 2) {
			  printf("Parab�ns voc� encerrou o tutorial da vila");
			  Sleep(3000);
			  break;
		  }
        }
    
    	//inicio da fase 1
    	
    	char fase1 [12][12]={"************",
          	  	  	  	  	  "*    *     *",
          	  	  	  	  	  "D    D     *",
          	  	  	  	  	  "******     *",
          	  	  	  	  	  "*          *",
          	  	  	  	  	  "*          *",
          	  	  	  	  	  "*      @   *",
          	  	  	  	  	  "*@         *",
          	  	  	  	  	  "*          *",
          	  	  	  	  	  "*          *",
          	  	  	  	  	  "*          *",
          	  	  	  	  	  "************"
		};
			
			x =5;
    		y =5;
    		chave = 0;  
		  
    	while(1){
 		
    		
    		
    		int i, j;
    		char move1;
			 //fun��o system que serve para atualizar a tela do jogo sem precisar que fique v�rias atualiza��es na tela do usu�rio
          system("cls");
          
            //sequencia de for's para a cria��o e atualiza��o do mapa
          for(i=0; i<12; i++){
            for(j=0; j<12; j++){
              if(i==y && j==x){
                printf("&");
              }
              //comando que orienta onde ser� as paredes
              else{
                printf("%c",fase1 [i][j]);
              }
            } 
            printf("\n");
          }

          //fun��o getch para receber o caractere daa variavel move sem precisar mostrar nada na tela
          move1 = getch();
          
          //sequ�ncia de if's paea fazer a movimenta��o do personagem
          if((move1 == 'w' || move1 == 'W') && (fase1 [y-1] [x] != '*' && fase1 [y-1] [x] != 'D' && fase1 [y-1] [x] != '@' && fase1 [y-1] [x] != 'P')) y--; 
          if((move1 == 's' || move1 == 'S') && (fase1 [y+1] [x] != '*' && fase1 [y+1] [x] != 'D' && fase1 [y+1] [x] != '@' && fase1 [y+1] [x] != 'P')) y++;
          if((move1 == 'a' || move1 == 'A') && (fase1 [y] [x-1] != '*' && fase1 [y] [x-1] != 'D' && fase1 [y] [x-1] != '@' && fase1 [y] [x-1] != 'P')) x--;
          if((move1 == 'd' || move1 == 'D') && (fase1 [y] [x+1] != '*' && fase1 [y] [x+1] != 'D' && fase1 [y] [x+1] != '@' && fase1 [y] [x+1] != 'P')) x++;
          
          if(move1 == 'b') break; 
          
          if(x == 1 && y == 8 && (move1 == 'i' || move1 == 'I') && fase1[7][1] == '@') {
			    fase1[7][1] = ' ';
			    chave++;
			}
			
			if(x == 7 && y == 7 && (move1 == 'i' || move1 == 'I') && fase1[6][7] == '@') {
			    fase1[6][7] = ' ';
			    chave++;
			}
			
			 if(x == 6 && y == 2 && (move1 == 'i' || move1 == 'I') && chave>=1){
				fase1[2][5] = '=';
			}
          
            if(x == 1 && y == 2 && (move1 == 'i' || move1 == 'I') && chave ==2){
				fase1[2][0] = '=';
			}
          if(x == 0 && y == 2) {
			  printf("Parab�ns voc� encerrou a fase 1");
			  Sleep(3000);
			  break;
		  }
        
          
		}
		
		
		
		//inicio da fase 2
		
			char fase2 [22][22]={"**********************",
          	  	  	  	  	     "*                    *",
          	  	  	  	  	     "*########            *",
          	  	  	  	  	     "*       #            *",
          	  	  	  	  	     "*       D            *",
          	  	  	  	  	     "*  O    #            *",
          	  	  	  	  	     "*@   @  #            *",
          	  	   	  	  	     "*       #            *",
          	  	  	  	  	     "*########            *",
          	  	  	  	  	     "*                    *",
          	  	  	  	  	     "*                    *",
          	  	  	  	  	     "*                    *",
          	  	  	  	  	     "*                    *",
          	  	  	  	  	     "*                    *",
          	  	  	  	  	     "*                    *",
          	  	  	  	  	     "* @                  *",
          	  	  	  	  	     "*            *********",
          	  	  	  	  	     "*            *       *",
          	  	  	  	  	     "*            *       *",
          	  	  	  	   	     "*            D       *",
          	  	  	  	  	     "*            *       D",
          	  	  	  	  	     "**********************"
			};
			
			x = 12;
    		y = 12;
    		a = 10;
    		b = 1;
    		chave = 0;
    		int vilao;
		  
    	while(1){
 		while(vidas>0){
    		int i, j;
    		char move2;
			 //fun��o system que serve para atualizar a tela do jogo sem precisar que fique v�rias atualiza��es na tela do usu�rio
          system("cls");
          
          //sequencia de for's para a cria��o e atualiza��o do mapa
          for(i=0; i<22; i++){
            for(j=0; j<22; j++){
              if(i==y && j==x){
                printf("&");
              }
              else if(i==b && j==a){
                printf("X");
              }
              //comando que orienta onde ser� as paredes
              else{
                printf("%c",fase2 [i][j]);
              }
              
            } 
            printf("\n");
          }
          
          //fun��o getch para receber o caractere daa variavel move sem precisar mostrar nada na tela
          move2 = getch();
          
          vilao = rand()%4;
          //sequ�ncia de if's paea fazer a movimenta��o do personagem
        if(move2 == 'w' || move2 == 'W') {
        if(colisaoespinhos(fase2, x, y - 1)) {
        vidas--;
        printf("Voc� pisou em um espinho! Vidas restantes: %d\n", vidas);
        reiniciarMapa2(fase2);
        x = 12;
        y = 12;
        a = 10;
 		b = 1;
        chave = 0;
        Sleep(2000);
    }   else if(fase2[y-1][x] != '*' && fase2[y-1][x] != 'D' && fase2[y-1][x] != '@' && fase2[y-1][x] != 'O') {
        y--;
	}
    }

        if(move2 == 's' || move2 == 'S') {
        if(colisaoespinhos(fase2, x, y + 1)) {
        vidas--;
        printf("Voc� pisou em um espinho! Vidas restantes: %d\n", vidas);
        reiniciarMapa2(fase2);
        x = 12;
        y = 12;
        a = 10;
 		b = 1;
        chave = 0;
        Sleep(2000);
    }   else if(fase2[y+1][x] != '*' && fase2[y+1][x] != 'D' && fase2[y+1][x] != '@' && fase2[y+1][x] != 'O') {
        y++;
    }
}
        if(move2 == 'a' || move2 == 'A') {
        if(colisaoespinhos(fase2, x - 1, y)) {
        vidas--;
        printf("Voc� pisou em um espinho! Vidas restantes: %d\n", vidas);
        reiniciarMapa2(fase2);
        x = 12;
        y = 12;
        a = 10;
 		b = 1;
        chave = 0;
        Sleep(2000);
    } else if(fase2[y][x-1] != '*' && fase2[y][x-1] != 'D' && fase2[y][x-1] != '@' && fase2[y][x-1] != 'O') {
        x--;
    }
}

        if(move2 == 'd' || move2 == 'D') {
        if(colisaoespinhos(fase2, x + 1, y)) {
        vidas--;
        printf("Voc� pisou em um espinho! Vidas restantes: %d\n", vidas);
        reiniciarMapa2(fase2);
        x = 12;
        y = 12;
        a = 10;
 		b = 1;
        chave = 0;
        Sleep(2000);
    }   else if(fase2[y][x+1] != '*' && fase2[y][x+1] != 'D' && fase2[y][x+1] != '@' && fase2[y][x+1] != 'O') {
        x++;
    }
}

          
          if(vilao == 0 && (fase2 [b-1] [a] != '*' && fase2 [b-1] [a] != 'D' && fase2 [b-1] [a] != '@' && fase2 [b-1] [a] != 'P' && fase2 [b-1] [a] != '#')) b--; 
          if(vilao == 1 && (fase2 [b+1] [a] != '*' && fase2 [b+1] [a] != 'D' && fase2 [b+1] [a] != '@' && fase2 [b+1] [a] != 'P'&& fase2 [b+1] [a] != '#')) b++;
          if(vilao == 2 && (fase2 [b] [a-1] != '*' && fase2 [b] [a-1] != 'D' && fase2 [b] [a-1] != '@' && fase2 [b] [a-1] != 'P'&& fase2 [b] [a-1] != '#')) a--;
          if(vilao == 3 && (fase2 [b] [a+1] != '*' && fase2 [b] [a+1] != 'D' && fase2 [b] [a+1] != '@' && fase2 [b] [a+1] != 'P'&& fase2 [b] [a+1] != '#')) a++;
          
          if(x == 2 && y == 16 && (move2 == 'i' || move2 == 'I') && fase2[15][2] == '@') {
			    fase2[15][2] = ' ';
			    chave++;
			}
			
		if(x == 1 && y == 7 && (move2 == 'i' || move2 == 'I') && fase2[6][1] == '@') {
			    fase2[6][1] = ' ';
			    chave++;
			}

			if(x == 5 && y == 7 && (move2 == 'i' || move2 == 'I') && fase2[6][5] == '@') {
			    fase2[6][5] = ' ';
			    chave++;
			}
			
			 if(x == 9 && y == 4 && (move2 == 'i' || move2 == 'I') && chave>=1 && fase2[4][8] == 'D'){
				fase2[4][8] = '=';
				chave --;
			}
			
			if(x == 5 && y == 7 && (move2 == 'i' || move2 == 'I') && fase2[6][5] == '@') {
			    fase2[6][5] = ' ';
			    chave++;
			}
			
			if(x == 12 && y == 19 && (move2 == 'i' || move2 == 'I') && chave >= 1 && fase2[19][13] == 'D') {
			    fase2[19][13] = '=';
			    chave--;
			}
			
			
			if(x == 20 && y == 20 && (move2 == 'i' || move2 == 'I') && chave >= 1 && fase2[20][21] == 'D') {
			    fase2[20][21] = '=';
			    chave--;
			}
			
			if (x == 3 && y ==6 && (move2 == 'i' || move2 == 'I') && fase2[5][3] == 'O') {
			    int resultado = rand() % 2;
			    if (resultado == 0) {
			        vidas--;
			        printf("Voc� perdeu uma vida! Vidas restantes: %d\n", vidas);
			        Sleep(3000);
			        if (vidas <= 0) {
			            printf("Game Over!\n");
			        }
			    } else {
			        vidas++;
			        printf("Voc� ganhou uma vida! Vidas restantes: %d\n", vidas);
			        Sleep(3000);
			    }
			}
			if (a == x && b == y) {
			    vidas--;
			    printf("Voc� foi atingido por um inimigo! Vidas restantes: %d\n", vidas);
			    reiniciarMapa2(fase2);
			    x = 12;
			    y = 12;
			    a = 10;
    			b = 1;
			    chave = 0;
			    Sleep(3000);
			    if (vidas <= 0) {
			        printf("Game Over!\n");
			    }
			}

			
			if(x == 21 && y == 20) {
			  printf("Parab�ns voc� encerrou a fase 2");
			  Sleep(3000);
			  break;
		  } 
		  
		  if (vidas <= 0) {
			        break;
			    }
          if(move2 == 'b') break;
		
		if(vidas<=0){
		printf("Parab�ns, Jorge!\nSe o objetivo era morrer r�pido, miss�o cumprida com louvor.\nA masmorra agradece sua visita� curta estadia, ali�s!"

);
        printf("Menu principal:\n1.Jogar\n2.Cr�dito\n3.Sair\nEscolha uma op��o: ");
        scanf("%d",&menu);
        break;
		}
		 }
		 break;
	  }
		
		//inicio da fase 3
		
		char fase3[42][42] = {
			    "******************************************",
			    "<        #                               *",
			    "*      O #                               *",
			    "*  @     #                               *",
			    "*        #                               *",
			    "*#########                               *",
			    "*                                        *",
			    "*                      @                 *",
			    "*                                        *",
			    "*                                        *",
			    "*                                        *",
			    "*                                        *",
			    "*              #############             *",
			    "*              #     @     #             *",
			    "*              #           #             *",
			    "*              #           #             *",
			    "*              #           #             *",
			    "*              #           #             *",
			    "*###############           ########D#####*",
			    "*                                        *",
			    "*                                        *",
			    "*                                        *",
			    "*                                        *",
			    "*                                        *",
			    "*                                        *",
			    "*                                        *",
			    "*                                        *",
			    "*                                        *",
			    "*                                        *",
			    "*                                        *",
			    "*                                        *",
			    "*                                        *",
			    "*                                        *",
			    "*                                        *",
			    "*                                        *",
			    "*                                        *",
			    "***********                    ##########*",
			    "*         *                    #         *",
			    "*         D                    #         *",
			    "*         *                    #         *",
			    "D         *                    =         >",
			    "******************************************"
			};
			
			x = 22;
			y = 22;
			a = 1;
			b = 22;
			chave = 0;
			int vilao_x = 40;
			int vilao_y = 35;
    	while(1){
 		while(vidas>0){
			 int i, j;
			 
    		 vilao = rand()%4;
			 char move3;
			 //fun��o system que serve para atualizar a tela do jogo sem precisar que fique v�rias atualiza��es na tela do usu�rio
          system("cls");
          
          //sequencia de for's para a cria��o e atualiza��o do mapa
          for(i=0; i<42; i++){
            for(j=0; j<42; j++){
              if(i==y && j==x){
                printf("&");
              }
              else if(i==b && j==a){
				  printf("X");
			  }
			  else if(i == vilao_y && j == vilao_x){
				  printf("V");
			  }
              //comando que orienta onde ser� as paredes
              else{
                printf("%c",fase3 [i][j]);
              }
            } 
            printf("\n");
          }
          
          //fun��o getch para receber o caractere daa variavel move sem precisar mostrar nada na tela
          move3 = getch();
          
          //sequ�ncia de if's paea fazer a movimenta��o do personagem
        if(move3 == 'w' || move3 == 'W') {
        if(colisaoespinhos3(fase3, x, y - 1)) {
        vidas--;
        printf("Voc� pisou em um espinho! Vidas restantes: %d\n", vidas);
        reiniciarMapa3(fase3);
			    x = 22;
			    y = 22;
			    a = 1;
				b = 22;
				vilao_x = 40;
				vilao_y = 35;
			    chave = 0;
        Sleep(2000);
    }   else if(fase3[y-1][x] != '*' && fase3[y-1][x] != 'D' && fase3[y-1][x] != '@' && fase3[y-1][x] != 'O') {
        y--;
	}
    }
        if(move3 == 's' || move3 == 'S') {
        if(colisaoespinhos3(fase3, x, y + 1)) {
        vidas--;
        printf("Voc� pisou em um espinho! Vidas restantes: %d\n", vidas);
        reiniciarMapa3(fase3);
			    x = 22;
			    y = 22;
			    a = 1;
				b = 22;
				vilao_x = 40;
				vilao_y = 35;
			    chave = 0;
        Sleep(2000);
    }   else if(fase3[y+1][x] != '*' && fase3[y+1][x] != 'D' && fase3[y+1][x] != '@' && fase3[y+1][x] != 'O') {
        y++;
    }
}
        if(move3 == 'a' || move3 == 'A') {
        if(colisaoespinhos3(fase3, x - 1, y)) {
        vidas--;
        printf("Voc� pisou em um espinho! Vidas restantes: %d\n", vidas);
        reiniciarMapa3(fase3);
			    x = 22;
			    y = 22;
			    a = 1;
				b = 22;
				vilao_x = 40;
				vilao_y = 35;
			    chave = 0;
        Sleep(2000);
    }   else if(fase3[y][x-1] != '*' && fase3[y][x-1] != 'D' && fase3[y][x-1] != '@' && fase3[y][x-1] != 'O') {
        x--;
    }
}
        if(move3 == 'd' || move3 == 'D') {
        if(colisaoespinhos3(fase3, x + 1, y)) {
        vidas--;
        printf("Voc� pisou em um espinho! Vidas restantes: %d\n", vidas);
        reiniciarMapa3(fase3);
			    x = 22;
			    y = 22;
			    a = 1;
				b = 22;
				vilao_x = 40;
				vilao_y = 35;
			    chave = 0;
        Sleep(2000);
    }   else if(fase3[y][x+1] != '*' && fase3[y][x+1] != 'D' && fase3[y][x+1] != '@' && fase3[y][x+1] != 'O') {
        x++;
    }
}

			if(vilao == 0 && (fase3[b-1][a] != '*' && fase3[b-1][a] != 'D' && fase3[b-1][a] != '@' && fase3[b-1][a] != 'P' && fase3[b-1][a] != '#')) b--; 
			if(vilao == 1 && (fase3[b+1][a] != '*' && fase3[b+1][a] != 'D' && fase3[b+1][a] != '@' && fase3[b+1][a] != 'P' && fase3[b+1][a] != '#')) b++;
			if(vilao == 2 && (fase3[b][a-1] != '*' && fase3[b][a-1] != 'D' && fase3[b][a-1] != '@' && fase3[b][a-1] != 'P' && fase3[b][a-1] != '#')) a--;
			if(vilao == 3 && (fase3[b][a+1] != '*' && fase3[b][a+1] != 'D' && fase3[b][a+1] != '@' && fase3[b][a+1] != 'P' && fase3[b][a+1] != '#')) a++;

						
			if (y < vilao_y && fase3[vilao_y - 1][vilao_x] != '#' && fase3[vilao_y - 1][vilao_x] != '*' && fase3[vilao_y - 1][vilao_x] != 'D' && fase3[vilao_y - 1][vilao_x] != '@')
			    vilao_y--;
			else if (y > vilao_y && fase3[vilao_y + 1][vilao_x] != '#' && fase3[vilao_y + 1][vilao_x] != '*' && fase3[vilao_y + 1][vilao_x] != 'D' && fase3[vilao_y + 1][vilao_x] != '@')
			    vilao_y++;
			else if (x < vilao_x && fase3[vilao_y][vilao_x - 1] != '#' && fase3[vilao_y][vilao_x - 1] != '*' && fase3[vilao_y][vilao_x - 1] != 'D' && fase3[vilao_y][vilao_x - 1] != '@')
			    vilao_x--;
			else if (x > vilao_x && fase3[vilao_y][vilao_x + 1] != '#' && fase3[vilao_y][vilao_x + 1] != '*' && fase3[vilao_y][vilao_x + 1] != 'D' && fase3[vilao_y][vilao_x + 1] != '@')
			    vilao_x++;
		
			if (x == 3 && y == 4 && (move3 == 'i' || move3 == 'I') && fase3[3][3] == '@') {
				    fase3[3][3] = ' ';
				    chave++;
				}
				
				if (x == 23 && y == 8 && (move3 == 'i' || move3 == 'I') && fase3[7][23] == '@') {
				    fase3[7][23] = ' ';
				    chave++;
				}
				
				if (x == 21 && y == 14 && (move3 == 'i' || move3 == 'I') && fase3[13][21] == '@') {
				    fase3[13][21] = ' ';
				    chave++;
				}
				
				if (x == 35 && y == 19 && (move3 == 'i' || move3 == 'I') && chave >= 1 && fase3[18][35] == 'D') {
				    fase3[18][35] = '=';
				    chave--;
				}
				
				if (x == 11 && y == 38 && (move3 == 'i' || move3 == 'I') && chave >= 1 && fase3[38][10] == 'D') {
				    fase3[38][10] = '=';
				    chave--;
				}
				
				if (x == 1 && y == 40 && (move3 == 'i' || move3 == 'I') && chave >= 1 && fase3[40][0] == 'D') {
				    fase3[40][0] = '=';
				    chave--;
				}
				
				if (x == 7 && y == 3 && (move3 == 'i' || move3 == 'I') && fase3[2][7] == 'O') {
				    int resultado = rand() % 2;
				    if (resultado == 0) {
				        vidas--;
				        printf("Voc� perdeu uma vida! Vidas restantes: %d\n", vidas);
				        Sleep(3000);
				        if (vidas <= 0) {
				            printf("Game Over!\n");
				        }
				    } else {
				        vidas++;
				        printf("Voc� ganhou uma vida! Vidas restantes: %d\n", vidas);
				        Sleep(3000);
				    }
				}

			
			if(x==41 && y==40){
				x=2;
				y=1;
				
			}
			if(x==0 && y==1){
				x=40;
				y=40;
			}
			if (a == x && b == y) {
			    vidas--;
			    printf("Voc� foi atingido por um inimigo! Vidas restantes: %d\n", vidas);
			    reiniciarMapa3(fase3);
			    x = 22;
			    y = 22;
			    a = 1;
				b = 22;
				vilao_x = 40;
				vilao_y = 35;
			    chave = 0;
			    Sleep(3000);
			    if (vidas <= 0) {
			        printf("Game Over!\n");
			    }
			}
			if (vilao_x == x && vilao_y == y) {
			    vidas--;
			    printf("Voc� foi atingido por um inimigo! Vidas restantes: %d\n", vidas);
			    reiniciarMapa3(fase3);
			    x = 22;
			    y = 22;
			    a = 1;
				b = 22;
				vilao_x = 40;
				vilao_y = 35;
			    chave = 0;
			    Sleep(3000);
			    if (vidas <= 0) {
			        printf("Game Over!\n");
			    }
			}
			if(x == 0 && y == 40) {
			  printf("Impressionante, Jorge!\nA masmorra tentou te derrubar, mas voc� mostrou quem manda!\nContinue assim � a vila precisa de um her�i que sabe usar a espada� e o c�rebro!");
			  Sleep(3000);
			  break;
		  } 
		  
          if(move3 == 'b') break;
          
		}
        printf("Parab�ns, Jorge!\nSe o objetivo era morrer r�pido, miss�o cumprida com louvor.\nA masmorra agradece sua visita� curta estadia, ali�s!"

);
        printf("Menu principal:\n1.Jogar\n2.Cr�dito\n3.Sair\nEscolha uma op��o: ");
        scanf("%d",&menu);
        break;
		}
		 
    }

    //la�o de sele��o para o caso do usu�rio selecionar op��o 2
    if(menu == 2)
    {
      printf("Desenvolvedores:\nJos� Vitor Matos Monteiro Seabra\nLais Cunha Pereira\nMariane Marinho de Castro\n");
    }

    //solicitando que o usu�rio selecione novamente uma das op��es do menu
    printf("\nMenu principal:\n1.Jogar\n2.Cr�dito\n3.Sair\nEscolha uma op��o: ");
      scanf("%d",&menu);

      //la�o de repti��o para for�ar o usu�rio apenas a selecionar op��es v�lidas no caso 1, 2 ou 3
      while(menu != 1 && menu != 2 && menu != 3){
      printf("Op��o inv�lida, selecione novamente: ");
      scanf("%d",&menu);
    }
  }

  //mensagem final de agradecimento para quando o usu�rio decidir parar de jogar
  printf("O jogo foi encerrado, obrigado por participar dessa aventura com a gente!");

    return 0;
}