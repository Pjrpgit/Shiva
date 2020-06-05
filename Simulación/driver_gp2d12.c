//*****************************DRIVER DE CONTROL DEL SENSOR DE DISTANCIA Gp2d12, para una recta entre 10 cm y 55 cm.
//HACE LA CONVERISON DE TENSION PROCEDENTE DEL SENSOR Gp2d12 A UNA DISTANCIA (SE OBTIENE UNA DISTANCIA EN FUNCION DE LA TENSIÓN).
//SE INTRODUCE UN VALOR DE TENSIÓN (v)TIPO FLOAT Y DEVUELVE UNA DISTANCIA (d)FLOAT.




//****************************** DECLARACIÓN DE FUNCIONES***************************************************************************

float Gp2d12_v_d(float);


//****************************************FUNCIÓN Gp2d12_v_d*******************************************************************

float Gp2d12_v_d(float v){
      
      float l;
      l=0;
      
      if(v<2.45&&v>=1.9)
      l = 13.5 + ((10-13.5)* (v - 1.9) /(2.45-1.9));
      if(v<1.9&&v>=1.65)
      l = 16 + ((13.5-16)* (v- 1.65) / (1.9-1.65));
      if(v<1.65&&v>=1.38)
      l = 20 + ((16-20)* (v- 1.38) / (1.65-1.38));
      if(v<1.38&&v>=1.15)
      l = 25 + ((20-25)* (v- 1.15) / (1.38-1.15));
      if(v<1.15&&v>=0.95)
      l = 30 + ((25-30)* (v- 0.95) / (1.15-0.95));
      if(v<0.95&&v>=0.75)
      l = 40 + ((30-40)* (v- 0.75) / (0.95-0.75));
      if(v<0.75&&v>=0.68)
      l = 45 + ((40-45)* (v- 0.68) / (0.75-0.68));
      if(v<0.68&&v>=0.58)
      l = 55 + ((45-55)* (v- 0.58) / (0.68-0.58));
      
      return(l);
      
}
   
