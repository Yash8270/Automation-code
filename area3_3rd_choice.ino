void area3_navigation3()
{

  //-----------------------------ball checking-------------------------------//
  if (sensor[id] == 2 && i != 5 && i != 10 && i!=1)
  {
    halt();
    imus();
    delay(630);
    picking(0);
    free_fall(255);
    delay(1800);

  }
  else if (sensor[id] == 1 && i != 5 && i != 10 && i!=1)
  {
    halt();
    imus();
    delay(800);
    picking(0);
    free_fall(0);
    ms = 220;
    silonext();
  }
  else if (i != 5 && i != 10)
  {
    picking(255);
    free_fall(0);
  }

  //------------------------Navigation------------------------------//

  //---------------------avoiding frontwall collision----------------------//
  if (cor > frontwall3 && i == 1)
  {
    Ycor = temp - 200;
    imu_clock_right(-83);
    reset_imu();
    cor = 0;                       
    x = 0;
    y = 0;
    z = 0;
    w = 0;
    temp = 0;
    i = 2;
  }

 //----------------avoiding rightwall collision------------// 
  else if (cor > rightwall3 && i == 2)
  {
    halt();
    imus();
    delay(800);

   //---------------code from start zone------------//  
   if(retry==0)
   { 
    imu_anticlock_line();
    reset_imu();                       
    cor = 0;
    x = 0;
    y = 0;
    z = 0;
    w = 0;
    temp = 0;
    i = 3;
   }

   //---------------code from retry zone------------// 
   else
   {
      imu_anticlock();
    reset_imu();                        
    cor = 0;
    x = 0;
    y = 0;
    z = 0;
    w = 0;
    temp = 0;
    i = 7;
    i7silo2 = 5;
     Ycor = Ycor + 200;
   }
  }

  //-----------------avoiding leftwall collision-----------------//
  else if (cor > leftwall3 && i == 3)
  {
    x = 0;
    y = 0;
    z = 0;
    w = 0;
    cor = (w + x + z) / 3;
    left_shift(i);
  }
  
  //
  else if (i == 4)
  {
    halt();
  }

 //--------------code for getting back to the main silo------------// 
  else if (i == 5)
  {
    back_to_position3();
  }

 //--------------alignment and throowing into silo--------------// 
  else if (i == 10)
  {
    align_with_silo3();
  }

 //--------------avoiding new rightwall collision-------------// 
  else if (cor > (rightwall3 +  200) && i == 6)
  {
    halt();
    imus();
    delay(800);
    imu_anticlock();
    reset_imu();
    x = 0;
    y = 0;
    z = 0;
    w = 0;
    cor = (w + x + z) / 3;
    temp = 0;
    i = 7;
  }

  //------------avoiding corner collision--------------//
  else if (i == 7 && cor > corner3)
  {
    halt();
    imus();
    delay(800);
//    cor = (w + x + z) / 3;

   //---------code from start zone-------------//
   if(retry==0)
   {
    while (cor > 350)
    {
      imus();
      cor = (w + x + z) / 3;
      backward(yawDeg, imutune);
    }
   }

   //---------code from retry zone-------------//
   else
   { 
    while (cor > 5)
    {
      imus();
      cor = (w + x + z) / 3;
      backward(yawDeg, imutune);
    }
   } 
    imu_anticlock();
    reset_imu();
    cor = 0;
    x = 0;
    y = 0;
    z = 0;
    w = 0;
    temp = 0;
    i = 3;
  }

 //------------------Movement forward--------------//
  else
  {
    if (i != 2) ms = 160;
    else ms = 115;
    imus();
    cor = (w + x + z) / 3;
    temp = cor;                      

    //------------------push button for ball intake---------------//
    if (sensor[push] == 0)
    {
      halt();
      imus();
      delay(150);
    }
    else if(cor < -60 && sensor[frontlsa] <= 70)
    {
      if(cor < -300) ms=100;
      else ms=160;
       lsa_forward_with_imu();
    }
    else
    {
      if (i != 2) ms = 160;
      else ms = 115;
      forward(yawDeg, imutune);
    }
  }
}
