#include <bits/stdc++.h>
#include <map>
#include <vector>
using namespace std;
     
int hora[5];
int minuto[5];
int espejo[12];
int pos, pos_2;
int vol_min[5];
int vol_hor[5];

void hrs(char x){
  pos++;
  if (x == '0') hora[pos] = 0;
  if (x == '1') hora[pos] = 1;
  if (x == '2') hora[pos] = 2;
  if (x == '3') hora[pos] = 3;
  if (x == '4') hora[pos] = 4;
  if (x == '5') hora[pos] = 5;
  if (x == '6') hora[pos] = 6;
  if (x == '7') hora[pos] = 7;
  if (x == '8') hora[pos] = 8;
  if (x == '9') hora[pos] = 9;
}

void mts(char x){
  pos_2++;
  if (x == '0') minuto[pos_2] = 0;
  if (x == '1') minuto[pos_2] = 1;
  if (x == '2') minuto[pos_2] = 2;
  if (x == '3') minuto[pos_2] = 3;
  if (x == '4') minuto[pos_2] = 4;
  if (x == '5') minuto[pos_2] = 5;
  if (x == '6') minuto[pos_2] = 6;
  if (x == '7') minuto[pos_2] = 7;
  if (x == '8') minuto[pos_2] = 8;
  if (x == '9') minuto[pos_2] = 9;
}

void voltea(){
  espejo[0] = 0;
  espejo[1] = 1;
  espejo[2] = 5;
  espejo[3] = -3;
  espejo[4] = -4;
  espejo[5] = 2;
  espejo[6] = -6;
  espejo[7] = -7;
  espejo[8] = 8;
  espejo[9] = -9;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  voltea();
  cin >> t;
  while(t--){
    int limite_horas, limite_minutos;
    string s;
    char a;
    cin >> limite_horas >> limite_minutos;
    cin >> s;
    pos = 0;
    pos_2 = 0;
    for (int i = 0; i < s.length(); i++){
      a = s[i];
      if (i < 2)  hrs(a);
      if (i > 2)  mts(a);
    }
    limite_horas--;
    limite_minutos--;
    int hrs_vol;
    int min_vol;
    int aux, aux_2;
    int hora_final;
    int min_final;
    int hora_inicial = hora[1] * 10 + hora[2]; 
    int min_inicial = minuto[1] * 10 + minuto[2];
    bool puede = false;
    int res_h, res_m;
    for (int i = hora_inicial; i <= hora_inicial; i++){
      for (int j = min_inicial; j <= limite_minutos; j++){
        aux =  i;
        aux = aux % 10;
        vol_min[1] = espejo[aux];
        aux = i;
        aux = aux / 10;
        aux = aux % 10;
        vol_min[2] = espejo[aux];
        aux_2 = j;
        aux_2 = aux_2 % 10;
        vol_hor[1] = espejo[aux_2];
        aux_2 = j;
        aux_2 = aux_2 / 10;
        aux_2 = aux_2 % 10;
        vol_hor[2] = espejo[aux_2];
        if (vol_hor[1] >= 0 and vol_hor[2] >= 0 and vol_min[1] >= 0 and vol_min[2] >= 0){
          hora_final = vol_hor[1] * 10 + vol_hor[2];
          min_final = vol_min[1] * 10 + vol_min[2];
          if (hora_final <= limite_horas and min_final <= limite_minutos){
            res_h = i;
            res_m = j;
            puede = true;
            break;
          }
        }
      }
    }
    if (puede){
      aux = res_h / 10;
      aux = aux % 10;
      aux_2 = res_m / 10;
      aux_2 = aux_2 % 10;
      cout << aux << res_h % 10 << ':' << aux_2 << res_m % 10;
    }else{
      puede = false;
      for (int i = hora_inicial + 1; i <= limite_horas; i++){
        for (int j = 0; j <= limite_minutos; j++){
          aux =  i;
          aux = aux % 10;
          vol_min[1] = espejo[aux];
          aux = i;
          aux = aux / 10;
          aux = aux % 10;
          vol_min[2] = espejo[aux];
          aux_2 = j;
          aux_2 = aux_2 % 10;
          vol_hor[1] = espejo[aux_2];
          aux_2 = j;
          aux_2 = aux_2 / 10;
          aux_2 = aux_2 % 10;
          vol_hor[2] = espejo[aux_2];
          if (vol_hor[1] >= 0 and vol_hor[2] >= 0 and vol_min[1] >= 0 and vol_min[2] >= 0){
            hora_final = vol_hor[1] * 10 + vol_hor[2];
            min_final = vol_min[1] * 10 + vol_min[2];
            if (hora_final <= limite_horas and min_final <= limite_minutos){
              res_h = i;
              res_m = j;
              puede = true;
              break;
            }
          }
        }
        if (puede){
        break;
        }
      }
      if (puede){
          aux = res_h / 10;
        aux = aux % 10;
        aux_2 = res_m / 10;
        aux_2 = aux_2 % 10;
        cout << aux << res_h % 10 << ':' << aux_2 << res_m % 10;
      }else{
        cout << 0 << 0 << ':' << 0 << 0;
      }
    }
    cout << "\n";
  }
  return 0;
}