#include<cstdio>
#include<cstdlib>

class TicTacToe{
    private:
        char table[3][3];

    public:
        //construtor
        TicTacToe(){
            this->initTable();

            while(true){
                
                this->refreshTable();
                this->insertSymbol('X');
                if(this->checkGame('X') == false){
                    break;
                }
                this->refreshTable();
                this->insertSymbol('O');
                if(this->checkGame('O') == false){
                    break;
                }
            }
        }
        
        //atualiza tabela na tela
        void refreshTable(){
            system("clear");
            printf("[%c][%c][%c]\n", this->table[0][0], this->table[0][1], this->table[0][2]);
            printf("[%c][%c][%c]\n", this->table[1][0], this->table[1][1], this->table[1][2]);
            printf("[%c][%c][%c]\n", this->table[2][0], this->table[2][1], this->table[2][2]);
        }

        //preenche tabela com valores vazios
        void initTable(){
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    this->table[i][j]= ' ';
                }
            }
        }

        //checar se alguma das possibilidades foram satisfeitas
        bool checkGame(char symbol){
            //primeira diagonal
            if(
                this->table[0][0] == symbol &&
                this->table[1][1] == symbol &&
                this->table[2][2] == symbol
            ){
                printf("Jogador %c ganhou!\n",symbol);
                return false;
            }

            //segunda diagonal
            else if(
                this->table[0][2] == symbol &&
                this->table[1][1] == symbol &&
                this->table[2][0] == symbol
            ){
                printf("Jogador %c ganhou!\n",symbol);
                return false;
            }

            //primeira linha
            else if(
                this->table[0][0] == symbol &&
                this->table[0][1] == symbol &&
                this->table[0][2] == symbol
            ){
                printf("Jogador %c ganhou!\n",symbol);
                return false;
            }

            //segunda linha
            else if(
                this->table[1][0] == symbol &&
                this->table[1][1] == symbol &&
                this->table[1][2] == symbol
            ){
                printf("Jogador %c ganhou!\n",symbol);
                return false;
            }

            //terceira linha
            else if(
                this->table[2][0] == symbol &&
                this->table[2][1] == symbol &&
                this->table[2][2] == symbol
            ){
                printf("Jogador %c ganhou!\n",symbol);
                return false;
            }

            //primeira coluna
            else if(
                this->table[0][0] == symbol &&
                this->table[1][0] == symbol &&
                this->table[2][0] == symbol
            ){
                printf("Jogador %c ganhou!\n",symbol);
                return false;
            }

            //segunda coluna
            else if(
                this->table[0][1] == symbol &&
                this->table[1][1] == symbol &&
                this->table[2][1] == symbol
            ){
                printf("Jogador %c ganhou!\n",symbol);
                return false;
            }

            //terceira coluna
            else if(
                this->table[0][2] == symbol &&
                this->table[1][2] == symbol &&
                this->table[2][2] == symbol
            ){
                printf("Jogador %c ganhou!\n",symbol);
                return false;
            }

            //checar se tabela está cheia
            else if(
                this->table[0][0] != ' ' &&
                this->table[0][1] != ' ' &&
                this->table[0][2] != ' ' &&
                this->table[1][0] != ' ' &&
                this->table[1][1] != ' ' &&
                this->table[1][2] != ' ' &&
                this->table[2][0] != ' ' &&
                this->table[2][1] != ' ' &&
                this->table[2][2] != ' '
            ){
                printf("Tabela cheia, jogo encerrado.\n");
                return true;
            }

            else return true;
        }

        //marcar símbolo na tabela
        void insertSymbol(char symbol){
            int linha, coluna;
            while(true){
                printf("Jogador %c, marque uma posição:\n",symbol);
                printf("Linha:");
                scanf("%d",&linha);
                printf("Coluna:");
                scanf("%d",&coluna);
                if(this->table[linha - 1][coluna - 1] != ' '){
                    printf("Posição já usada, escolha outro.\n");
                }
                else {
                    this->table[linha - 1][coluna - 1] = symbol;
                    break;
                }
            }
        }
};