#include <stdio.h>
#include <cassert>
#include <string.h>
#include <cstdint>

template <int OY, int OX, int OC, int IC, int FY, int FX, int STRIDE>
void conv_gold(int16_t ifmap[(OY-1)*STRIDE+FY][(OX-1)*STRIDE+FX][IC],
               int16_t weight[FY][FX][IC][OC],
               int32_t ofmap[OY][OX][OC]){

  // Implement the functionality of a convolutional layer, which convolves
  // ifmap with weight to produce ofmap. Your code should assign values to the
  // ofmap array. Make sure you take STRIDE into account.
 
  // Your code starts here
  for (int i = 0; i < OY; i++) {
    for (int j = 0; j < OX; j++) {
      for (int k = 0; k < OC; k++) {
        ofmap[i][j][k] = 0;
      }
    }
  }
    for (int var_oc=0; var_oc<OC; var_oc++){
      for (int var_ic=0; var_ic<IC; var_ic++){
        for (int var_oy=0; var_oy<OY; var_oy++){
          for (int var_ox=0; var_ox<OX; var_ox++){
            for (int var_fy=0; var_fy<FY; var_fy++){
              for (int var_fx=0; var_fx<FX; var_fx++){
                ofmap[var_oy][var_ox][var_oc] += ifmap[var_oy*STRIDE+var_fy][var_ox*STRIDE+var_fx][var_ic] * weight[var_fy][var_fx][var_ic][var_oc];
              }
            }
          }
        }
      }
    }
  // Your code ends here
}
