#include "buzzer.h"
#include "i2s.h"
#include "math.h"
#include "stereo.h"
#include "nrf_log.h"

static float scale = 1; // large pulse scale factor 

bool buzzer_init(void){
  bool ok = i2s_init();
  //i2s_load_stream(chirp, SIGNAL_SIZE, 1);
  i2s_load_stream(warmup, WARMUP_SIZE, 1);
 
  //i2s_start();
  return ok;
}

void buzzer_load_chirp(void){
  i2s_load_stream(chirp, SIGNAL_SIZE, 1); 
}

void buzzer_play_chirp(uint32_t nrepititions){

  int index_of_big_pulse = 1922;

  NRF_LOG_INFO("Scale:"NRF_LOG_FLOAT_MARKER, NRF_LOG_FLOAT(scale));

  //for(int i = 0; i < SIGNAL_SIZE; i++){
    //if(i < index_of_big_pulse){
      //chirp[i] = cst_chirp[i];
    ////} else{
      //chirp[i] = (int16_t) (cst_chirp[i] * scale);
      //NRF_LOG_INFO("chirp[%d] = %d", i, chirp[i]);
    //}
  //}
  
  //NRF_LOG_INFO("Scale:"NRF_LOG_FLOAT_MARKER, NRF_LOG_FLOAT(scale));


  i2s_load_stream(cst_chirp, SIGNAL_SIZE, nrepititions);
  i2s_start();
}

void buzzer_set_chirp_scale(float* gain){

    //NRF_LOG_INFO("before scale = "NRF_LOG_FLOAT_MARKER, NRF_LOG_FLOAT(scale));
    //NRF_LOG_INFO("before gain = "NRF_LOG_FLOAT_MARKER, NRF_LOG_FLOAT(*gain));
    scale = *gain; 
    //NRF_LOG_INFO("after scale = "NRF_LOG_FLOAT_MARKER, NRF_LOG_FLOAT(scale));
    //NRF_LOG_INFO("after gain = "NRF_LOG_FLOAT_MARKER, NRF_LOG_FLOAT(*gain));
}

float buzzer_get_chirp_scale(void){
  
    return scale;
}