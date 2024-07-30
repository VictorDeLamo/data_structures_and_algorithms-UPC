#include "Player.hh"
#include <limits>




/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME love_u


struct PLAYER_NAME : public Player {

  /**
   * Factory: returns a new instance of this class.
   * Do not modify this function.
   */
  static Player* factory () {
    return new PLAYER_NAME;
  }

  /**
   * Types and attributes for your player can be defined here.
   */

  /**
   * Play method, invoked once per each round.
   */
  int Cols = board_cols();
  int Rows = board_rows();
  const vector<Dir> dirs = {Up,Down,Left,Right};

  vector<int> filas = {-1, +1 , 0, 0};
  vector<int> columnas = {0, 0, -1, +1};

  bool enemigo(int id) {
    if (id == -1) return false;
    for (int i = 0; i <=3 ; ++i) {
      if (i != me()) {
        for(int f: alive_units(i)) {
          if(id == f) return true;
        }
      }
    }
    for(int f: zombies()) {
      if(id == f) return true;
    }

    return false;
  }

  bool diagonall(Pos pos_ini, int i_enem, int j_enem) {
    return (abs(pos_ini.i - i_enem)== 1 and abs(pos_ini.j - j_enem)== 1);
  }
  bool posible_mov(int x, int y) {
    return (pos_ok(x,y) and cell(x, y).type != Waste and (enemigo(cell(x, y).id) or  cell(x, y).id == -1));
  }

  void go_to(int id, Pos pos_ini, int i_enem, int j_enem) {
    bool diagonal= diagonall(pos_ini,i_enem,j_enem);
    
    bool es_zombie = false;
    for (int i:zombies()) {
      if (cell(i_enem, j_enem).id  == i) {
        es_zombie = true;
      } 
    }
    
      
    int y = i_enem - pos_ini.i;
    int x = j_enem - pos_ini.j;
    
    if (not (es_zombie) and diagonal and not (cell(i_enem, j_enem).food) ) {}
      
    else {
    
      int direccion = 0;
      if (abs(y)> abs(x)) {
        if (y < 0 and posible_mov( pos_ini.i -1, pos_ini.j) ) direccion = 0;
        else if (y > 0 and posible_mov(pos_ini.i +1, pos_ini.j) ) direccion = 1;
        else if (x < 0 and posible_mov(pos_ini.i, pos_ini.j - 1)) direccion = 2;
        else if (x > 0 and posible_mov(pos_ini.i, pos_ini.j +1) ) direccion = 3;
      }
      else {
        if (x < 0 and posible_mov(pos_ini.i, pos_ini.j - 1)) direccion = 2;
        else if (x > 0 and posible_mov(pos_ini.i, pos_ini.j +1) ) direccion = 3;
        else if (y < 0 and posible_mov( pos_ini.i -1, pos_ini.j) ) direccion = 0;
        else if (y > 0 and posible_mov(pos_ini.i +1, pos_ini.j) ) direccion = 1;
      }
      move(id,dirs[direccion]);
    }
  }

  

  void mirar_vecinos(int fil, int col, vector<vector<bool>>& visitados, queue <int>& colax, queue <int>& colay, int& pasos ) {
    for (int i = 0; i<4; ++i) {
      int filn = fil + filas[i];
      int coln = col + columnas[i];
      if (pos_ok(filn,coln) and not(visitados[filn][coln]) and cell(filn,coln).type != Waste) {
        colax.push(filn);
        colay.push(coln);
        visitados[filn][coln] = true;
      }
      ++pasos;
    }
  }

  vector<int> bfs (int filn, int coln, vector<vector<bool>>& visitados, queue <int>& colax, queue <int>& colay, int& pasos, int& pasos_restantes,int& pasos_sig_capa ) {
    //cerr << "añado a la cola " << filn << " , " << coln << endl;
    colax.push(filn);
    colay.push(coln);
    vector<int>vec(3);
    //cerr << "all good " << endl;
    while (not (colax.empty())) {
      //cerr << "quito de la cola " << colax.front() << " , " << colay.front() << endl;
      int fil = colax.front();
      int col = colay.front();
      visitados[filn][coln] = true;
      colax.pop();
      colay.pop();
      if (cell(fil,col).food or enemigo(cell(fil,col).id)) {
        vec[0] = pasos;
        vec[1] = fil;
        vec[2] = col;
        return vec;
      }
      mirar_vecinos(fil,col, visitados, colax, colay, pasos);
      --pasos_restantes;
      if (pasos_restantes == 0) {
        pasos_restantes = pasos_sig_capa;
        pasos_sig_capa = 0;
        ++pasos;
      }
    }
    vec[0] = -1;
    return vec;



  }

   int matar_zombie(int mi, int mj, int zi ,int zj) { // i y j mía e i y j del zombie

    if (zi == mi) { // si el zombie está en la misma fila
      if (abs(zj - mj) == 2) return 4; // si está exactamente a dos casillas mejor no movernos
      if (zj - mj >2) return 3; // tendrás que ir a la derecha si el zombie está a la derecha
      else return 2; // tendrás que ir a la izquierda si el zombie está en la izquierda
    }   
    if (zj == mj) { //si el zombie está en la misma columna
      if (abs(zi - mi ) == 2) return 4;
      if (zi - mi >2) return 1; // tendrás que ir hacia abajo
      else return 0; // tendrás que ir hacia arriba
    }   
    if (abs(zj - mj) >= abs(zi - mi)) { // si el zombie está más lejos horizontalmente que verticalmente
      if (zi - mi > 0) return 1; // queremos igualar las filas (es lo que menos tardaremos en igualar)
      // si su fila es mayor a la mia significa que  está debajo
      else return 0;
    }
    else {
      if (zj - mj > 0) return 3; // si su columna es mayor que la mía significa que está a mi derecha
      else return 2;
    }
  }
  virtual void play () {
    vector<int> alive = alive_units(me());
    for (int id : alive) {
      int min = 100000;
      int direccion = 0;
      for (int i = 0; i<4; ++i) {
        vector<vector<bool>> visitados (60,vector<bool> (60,false));
        queue <int> colax;
        queue <int> colay;
        visitados[unit(id).pos.i][unit(id).pos.j] = true;
        int filn = unit(id).pos.i + filas[i];
        int coln = unit(id).pos.j + columnas[i];
        if (posible_mov(filn,coln)) {
          int pasos = 0;
          int pasos_restantes = 1;
          int pasos_sig_capa = 0;
          //cerr <<unit(id).pos.i"id: " << id << " hago el bfs" << endl;
          vector<int> actual = bfs (filn, coln, visitados, colax, colay, pasos, pasos_restantes, pasos_sig_capa );
          //cerr <<"id: " << id <<" miro en la posicion: " << filn << " , " << coln << endl;
          //cerr << "actual: " << actual << endl;
          if ( actual[0] != -1 and actual[0] < min) {
            min = actual[0];
            direccion = i;
          }
          
            bool es_zombie = false;
            for (int i:zombies()) {
              if (cell(actual[1], actual[2]).id  == i) {
                es_zombie = true;
              }
            
        
            if (es_zombie ) {
              filn =unit(id).pos.i;
              coln =  unit(id).pos.j;
             // cerr << "es zombie ---("<< unit(id).pos.i<< " , "<< unit(id).pos.j<< ") --- (" << actual[1] <<" , "<< actual[2] << ")"<< endl;
              if (actual[1] == filn -1 and  actual[2]== coln -1){
                
                if (posible_mov(filn,coln+1)) direccion = 3;
                else if(posible_mov(filn + 1,coln)) direccion = 1;
              } 
              else if (actual[1] == filn -1 and  actual[2]== coln +1){
               
                if(posible_mov(filn,coln-1)) direccion = 2;
                else if(posible_mov(filn + 1,coln)) direccion = 1;
              } 
              else if (actual[1] == filn +1 and  actual[2]== coln -1){
               
                if (posible_mov(filn,coln+1)) direccion = 3;
                else if(posible_mov(filn - 1,coln)) direccion = 0;
              } 
              else if (actual[1] == filn +1 and  actual[2]== coln +1){
                
                if (posible_mov(filn,coln-1)) direccion = 2;
                else if(posible_mov(filn - 1,coln)) direccion = 1;
              } 
              else if (filn == actual[1] and abs(actual[2] - coln) == 2 ) direccion = 4;
              else if (coln == actual[2] and abs(actual[1] - filn) == 2 ) direccion = 4;
              else if (abs(actual[2] - coln) == 2 and abs(actual[1] - filn) == 1) {
                if (actual[1] > filn) direccion = 1;
                else direccion = 0;
              } 
              else if (abs(actual[2] - coln) == 1 and abs(actual[1] - filn) == 2) {
                if (actual[2] > coln) direccion = 3;
                else direccion = 2;
              }
      
                
              
              
            
            } 
          }
        }
      }
      if (direccion != 4) {
        move(id, dirs[direccion]);
      }
      
    }

  }

};


/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);
