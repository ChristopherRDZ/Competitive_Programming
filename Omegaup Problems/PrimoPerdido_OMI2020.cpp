/// Problem Link: https://omegaup.com/arena/problem/OMI-2020-Primo/
/// OMI 2020 - Interactive problem, binary search + Sieve of Eratosthenes

#include "primo.h"

#include <bits/stdc++.h>

#include <map>

using namespace std;

// Main

//	int primo(int posicion)

bool p[10000005];

int busca(int n) {

    int primos[2000005];

    int aux = 0, ini, fin, mitad;

    int mio, consulta, respuesta;

    for (int i = 2; i*i <= n; i++){

        if (p[i] == false){

          for (int j = i*i; j <= n; j=j+i){

              p[j] = true;

          }

        }

    }

    aux = 0;

  for (int i = 2 ; i <= n; i++){

    if (p[i] == false){

      primos[aux] = i;

      aux++;

    }

  }

    ini = 0;

    fin = aux - 1;

    while (ini <= fin){

        mitad = (ini + fin) / 2;

        mio = primos[mitad];

        consulta = primo(mitad);

        if (mio == consulta){

            ini = mitad + 1;

        }

        if (mio < consulta){

            fin = mitad - 1;

            respuesta = mio;

        }

    }

	// FIXME

	return respuesta;

}