
//---------------silo function for line before center plus----------//
void silonew()
{
  
  //--------------ball found on frontwall-------------//
  if (i == 1)
  {
    ms=200;
    x = temp - 200;
    y = temp - 200;
    z = temp - 200;
    w = temp - 200;
    cor = (w + x + z) / 3;
    while ( cor > i1silo2)
    {
      imus();
      cor = (w + x + z) / 3;
      backward(yawDeg, imutune);
    }
    i = 10;
  }

  //----------------------ball found on initial left----------------//
  else if (i == 2)
  {
    x = temp;
    y = temp;
    z = temp;
    w = temp;
    cor = (w + x + z) / 3;
    while (cor > i2silo2)
    {
      imus();
      cor = (w + x + z) / 3;
      backward(yawDeg, imutune);
    }
   imu_clock_right(-78); 
    reset_imu();
    x = Ycor;
    y = Ycor;
    w = Ycor;
    z = Ycor;
    cor = (w + x + z) / 3;
    ms=200;
    while ( cor > i1silo2)
    {
      imus();
      cor = (w + x + z) / 3;
      backward(yawDeg, imutune);
    }
    i = 10;
  }

 //----------------------ball found on initial right before certain count----------------// 
  else if (i == 3 && cor < i3silo2)
  {
    x = temp;
    y = temp;
    z = temp;
    w = temp;
    cor = (w + x + z) / 3;
    while (cor < i3silo2)
    {
      imus();
      cor = (w + x + z) / 3;
      forward(yawDeg, imutune);
    }
     imu_anticlock();
    
    reset_imu();
    x = Ycor;
    y = Ycor;
    z = Ycor;
    w = Ycor;
    cor = (w + x + z) / 3;
    ms=200;
    while (cor > 5)
    {
      imus();
      cor = (w + x + z) / 3;
      backward(yawDeg, imutune);
    }
    i = 10;
  }

  //----------------------ball found on initial right after certain count----------------//
  else if (i == 3 && cor > i3silo2)
  {
    x = temp;
    y = temp;
    z = temp;
    w = temp;
    cor = (w + x + z) / 3;
    while (cor > i3silo2)
    {
      imus();
      cor = (w + x + z) / 3;
      backward(yawDeg, imutune);
    }
   
     imu_anticlock();

    reset_imu();
    x = Ycor;
    y = Ycor;
    w = Ycor;
    z = Ycor;
    cor = (w + x + z) / 3;
    ms=200;
    while (cor > 5)
    {
      imus();
      cor = (w + x + z) / 3;
      backward(yawDeg, imutune);
    }
    i = 10;
  }

  //----------------------ball found on second left before certain count----------------//
  else if (i == 6 && cor < i6silo2)
  {
    x = temp;
    y = temp;
    z = temp;
    w = temp;
    cor = (w + x + z) / 3;
    while (cor < i6silo2)
    {
      imus();
      cor = (w + x + z) / 3;
      forward(yawDeg, imutune);
    }
      imu_clock_right(-78);
    
    reset_imu();
    x = Ycor;
    y = Ycor;
    z = Ycor;
    w = Ycor;
    cor = (w + x + z) / 3;
    ms=200;
    while (cor > 10)
    {
      imus();
      cor = (w + x + z) / 3;
      backward(yawDeg, imutune);
    }
    i = 10;
  }

  //----------------------ball found on second left after certain count----------------//
  else if (i == 6 && cor > i6silo2)
  {
    x = temp;
    y = temp;
    z = temp;
    w = temp;
    cor = (w + x + z) / 3;
    while (cor > i6silo2)
    {
      imus();
      cor = (w + x + z) / 3;
      backward(yawDeg, imutune);
    }
    
     imu_clock_right(-78);
    
    reset_imu();
    x = Ycor;
    y = Ycor;
    z = Ycor;
    w = Ycor;
    cor = (w + x + z) / 3;
    ms=200;
    while (cor > 5)
    {
      imus();
      cor = (w + x + z) / 3;
      backward(yawDeg, imutune);
    }
    i = 10;
  }

  //---------------ball found on the left corner--------------//
  else if (i == 7)
  {
    cor = (w + x + z) / 3;
    while (cor > i7silo2)
    {
      imus();
      cor = (w + x + z) / 3;
      backward(yawDeg, imutune);
    }
    imu_anticlock();
    reset_imu();
    x = 0;
    y = 0;
    z = 0;
    w = 0;
    cor = (w + x + z) / 3;
    while (cor < i3silo2)
    {
      imus();
      cor = (w + x + z) / 3;
      backward(yawDeg, imutune);
    }
    imu_clock_right(-78);
    reset_imu();
    x = Ycor;
    y = Ycor;
    z = Ycor;
    w = Ycor;
    cor = (w + x + z) / 3;
    ms=200;
    while (cor > 5)
    {
      imus();
      cor = (w + x + z) / 3;
      backward(yawDeg, imutune);
    }
    i = 10;
  }

//  //---------------ball found on the left corner--------------//
//  else if (i == 7 && cor < i7silo2)
//  {
//    cor = (w + x + z) / 3;
//    while (cor < i7silo2)
//    {
//      imus();
//      cor = (w + x + z) / 3;
//      forward(yawDeg, imutune);
//    }
//    imu_anticlock();
//    reset_imu();
//    x = 0;
//    y = 0;
//    z = 0;
//    w = 0;
//    cor = (w + x + z) / 3;
//    while (cor < i3silo2)
//    {
//      imus();
//      cor = (w + x + z) / 3;
//      backward(yawDeg, imutune);
//    }
//    imu_clock_right(-78);
//    reset_imu();
//    x = Ycor;
//    y = Ycor;
//    z = Ycor;
//    w = Ycor;
//    cor = (w + x + z) / 3;
//    ms=200;
//    while (cor > 5)
//    {
//      imus();
//      cor = (w + x + z) / 3;
//      backward(yawDeg, imutune);
//    }
//    i = 10;
//  }
}
